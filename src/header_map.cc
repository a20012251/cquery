#include "header_map.h"

#include "utils.h"

#include <loguru/loguru.hpp>

#include <cstring>
#include <memory>
#include <string>
#include <fstream>

/*
 * This implementation are inspired by
 *   https://clang.llvm.org/doxygen/HeaderMap_8cpp_source.html
 *   https://opensource.apple.com/source/distcc/distcc-2503/distcc_dist/include_server/headermap.py
 */

HeaderMapParser::HeaderMapParser(const std::string& path): path_(path) {
  content_ = ReadContent(path_);
  if (content_ == nullopt)
    LOG_S(ERROR) << "The header map " << path_ << " can't be opened";

  is_valid_ = false;
  ParseHeader();

  if (!is_valid_)
    LOG_S(ERROR) << "The header map " << path_ << " has an invalid header";
}

void HeaderMapParser::ParseHeader() {
  if (content_ != nullopt && content_->size() < sizeof(HeaderMapHeader))
    return;

  header_ = const_cast<HeaderMapHeader*>(
      reinterpret_cast<const HeaderMapHeader*>(content_->c_str()));
  needs_byte_swapping_ = false;
  // Sniff it to see if it's a headermap by checking the magic number and
  // version.
  if (header_->magic == HMAP_HeaderMagicNumber &&
      header_->version == HMAP_HeaderVersion)
    needs_byte_swapping_ = false;
  else if (header_->magic == ByteSwap32(HMAP_HeaderMagicNumber) &&
      header_->version == ByteSwap16(HMAP_HeaderVersion))
    needs_byte_swapping_ = true;  // Mixed endianness headermap.
  else
    return;  // Not a header map.

  if (header_->reserved != 0)
    return;

  // Check the number of buckets.  It should be a power of two by definition,
  // and there should be enough space in the file for all of them.
  uint32_t num_buckets = AdjustEndianness(header_->num_buckets);
  if (__builtin_popcount(num_buckets) != 1 ||
      content_->size() < sizeof(HeaderMapHeader) +
                         sizeof(HeaderMapBucket) * num_buckets)
    return;

  is_valid_ = true;
}

uint32_t HeaderMapParser::AdjustEndianness(uint32_t num) {
  return needs_byte_swapping_ ? ByteSwap32(num) : num;
}

optional<HeaderMapBucket> HeaderMapParser::LookupBucket(int index) {
  if (content_->size() >=
      sizeof(HeaderMapHeader) + sizeof(HeaderMapBucket) * index) {
      LOG_S(ERROR) << "Bucket index "
                   << index
                   << " is not in range for header map "
                   << path_;
      return nullopt;
  }

  const HeaderMapBucket *bucket_array =
      reinterpret_cast<const HeaderMapBucket*>(
          content_->c_str() + sizeof(HeaderMapHeader));
  const HeaderMapBucket *bucket_ptr = bucket_array + index;

  HeaderMapBucket bucket;
  bucket.key = AdjustEndianness(bucket_ptr->key);
  bucket.prefix = AdjustEndianness(bucket_ptr->prefix);
  bucket.suffix = AdjustEndianness(bucket_ptr->suffix);
  return bucket;
}

optional<std::string> HeaderMapParser::LookupString(int index) {
  index += AdjustEndianness(header_->strings_offset);

  if (index >= content_->size()) {
    LOG_S(ERROR) << "String index "
                 << index
                 << " is not in rage for header map "
                 << path_;
    return nullopt;
  }

  const char *data = content_->c_str() + index;
  uint32_t max_len = content_->size() - index;
  uint32_t len = strnlen(data, max_len);

  // Check whether the buffer is null-terminated.
  if (len == max_len && data[len - 1])
    return nullopt;

  return std::string(data, index);
}

optional<HeaderMapEntry> HeaderMapParser::LookupEntry(int index) {
  optional<HeaderMapBucket> bucket = LookupBucket(index);
  if (bucket == nullopt)
    return nullopt;

  auto key = LookupString(bucket->key);
  auto prefix = LookupString(bucket->prefix);
  auto suffix = LookupString(bucket->suffix);

  if (key == nullopt || prefix == nullopt || suffix == nullopt)
    return nullopt;
  HeaderMapEntry entry = {*key, *prefix, *suffix};
  return entry;
}

optional<HeaderMap> HeaderMapParser::Parse() {
  if (!is_valid_)
    return nullopt;

  unsigned num_buckets = AdjustEndianness(header_->num_buckets);

  HeaderMap hmap = {std::vector<HeaderMapEntry>()};
  hmap.entries.reserve(num_buckets);

  for (int i = 0; i != num_buckets; ++i) {
    optional<HeaderMapEntry> entry = LookupEntry(i);
    if (entry != nullopt)
      hmap.entries.push_back(*entry);
  }

  return hmap;
}
