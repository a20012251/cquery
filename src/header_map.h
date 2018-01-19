#include <string>
#include <vector>
#include <optional.h>

// These constants are borrowed from
// https://clang.llvm.org/doxygen/HeaderMapTypes_8h_source.html

const uint32_t HMAP_HeaderMagicNumber =
    ('h' << 24) | ('m' << 16) | ('a' << 8) | 'p';
const uint32_t HMAP_HeaderVersion = 1;


struct HeaderMapBucket {
  uint32_t key;    // Offset (into strings) of key.
  uint32_t prefix; // Offset (into strings) of value prefix.
  uint32_t suffix; // Offset (into strings) of value suffix.
};

struct HeaderMapHeader {
  uint32_t magic;          // Magic word, also indicates byte order.
  uint16_t version;        // Version number -- currently 1.
  uint16_t reserved;       // Reserved for future use - zero for now.
  uint32_t strings_offset;  // Offset to start of string pool.
  uint32_t numentries;     // Number of entries in the string table.
  uint32_t num_buckets;     // Number of buckets (always a power of 2).
  uint32_t max_value_length; // Length of longest result path (excluding nul).
  // An array of 'NumBuckets' HMapBucket objects follows this header.
  // Strings follow the buckets, at StringsOffset.
};

struct HeaderMapEntry {
  std::string key;
  std::string prefix;
  std::string suffix;
};

struct HeaderMap {
  std::vector<HeaderMapEntry> entries;
};

class HeaderMapParser {
 public:
  HeaderMapParser(const std::string &path);
  optional<HeaderMap> Parse();

 private:
  void ParseHeader();
  optional<HeaderMapBucket> LookupBucket(int index);
  optional<HeaderMapEntry> LookupEntry(int index);
  optional<std::string> LookupString(int index);
  uint32_t AdjustEndianness(uint32_t num);

  bool needs_byte_swapping_;
  optional<std::string> content_;
  bool is_valid_;
  HeaderMapHeader *header_;
  std::string path_;
};
