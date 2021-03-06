struct Base0 {
  virtual ~Base0() { }
};
struct Base1 {
  virtual ~Base1() { }
};
struct Derived : Base0, Base1 {
  ~Derived() override { }
};

/*
OUTPUT:
{
  "includes": [],
  "skipped_by_preprocessor": [],
  "types": [{
      "id": 0,
      "usr": 11628904180681204356,
      "short_name": "Base0",
      "detailed_name": "Base0",
      "kind": 6,
      "definition_spelling": "1:8-1:13",
      "definition_extent": "1:1-3:2",
      "parents": [],
      "derived": [2],
      "types": [],
      "funcs": [0],
      "vars": [],
      "instances": [],
      "uses": ["1:8-1:13", "2:12-2:17", "7:18-7:23"]
    }, {
      "id": 1,
      "usr": 15826803741381445676,
      "short_name": "Base1",
      "detailed_name": "Base1",
      "kind": 6,
      "definition_spelling": "4:8-4:13",
      "definition_extent": "4:1-6:2",
      "parents": [],
      "derived": [2],
      "types": [],
      "funcs": [1],
      "vars": [],
      "instances": [],
      "uses": ["4:8-4:13", "5:12-5:17", "7:25-7:30"]
    }, {
      "id": 2,
      "usr": 10963370434658308541,
      "short_name": "Derived",
      "detailed_name": "Derived",
      "kind": 6,
      "definition_spelling": "7:8-7:15",
      "definition_extent": "7:1-9:2",
      "parents": [0, 1],
      "derived": [],
      "types": [],
      "funcs": [2],
      "vars": [],
      "instances": [],
      "uses": ["7:8-7:15", "8:4-8:11"]
    }],
  "funcs": [{
      "id": 0,
      "is_operator": false,
      "usr": 16347272523198263017,
      "short_name": "~Base0",
      "detailed_name": "void Base0::~Base0() noexcept",
      "kind": 23,
      "declarations": [],
      "definition_spelling": "2:11-2:17",
      "definition_extent": "2:3-2:23",
      "declaring_type": 0,
      "base": [],
      "derived": [2],
      "locals": [],
      "callers": [],
      "callees": []
    }, {
      "id": 1,
      "is_operator": false,
      "usr": 8401779086123965305,
      "short_name": "~Base1",
      "detailed_name": "void Base1::~Base1() noexcept",
      "kind": 23,
      "declarations": [],
      "definition_spelling": "5:11-5:17",
      "definition_extent": "5:3-5:23",
      "declaring_type": 1,
      "base": [],
      "derived": [2],
      "locals": [],
      "callers": [],
      "callees": []
    }, {
      "id": 2,
      "is_operator": false,
      "usr": 13164726294460837993,
      "short_name": "~Derived",
      "detailed_name": "void Derived::~Derived() noexcept",
      "kind": 23,
      "declarations": [],
      "definition_spelling": "8:3-8:11",
      "definition_extent": "8:3-8:26",
      "declaring_type": 2,
      "base": [0, 1],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }],
  "vars": []
}
*/