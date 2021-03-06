class Foo {
  void declonly();
  virtual void purevirtual() = 0;
  void def();
};

void Foo::def() {}

/*
OUTPUT:
{
  "includes": [],
  "skipped_by_preprocessor": [],
  "types": [{
      "id": 0,
      "usr": 15041163540773201510,
      "short_name": "Foo",
      "detailed_name": "Foo",
      "kind": 7,
      "definition_spelling": "1:7-1:10",
      "definition_extent": "1:1-5:2",
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [0, 1, 2],
      "vars": [],
      "instances": [],
      "uses": ["1:7-1:10", "7:6-7:9"]
    }],
  "funcs": [{
      "id": 0,
      "is_operator": false,
      "usr": 4012226004228259562,
      "short_name": "declonly",
      "detailed_name": "void Foo::declonly()",
      "kind": 16,
      "declarations": [{
          "spelling": "2:8-2:16",
          "extent": "2:3-2:18",
          "content": "void declonly()",
          "param_spellings": []
        }],
      "declaring_type": 0,
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }, {
      "id": 1,
      "is_operator": false,
      "usr": 10939323144126021546,
      "short_name": "purevirtual",
      "detailed_name": "void Foo::purevirtual()",
      "kind": 16,
      "declarations": [{
          "spelling": "3:16-3:27",
          "extent": "3:3-3:33",
          "content": "virtual void purevirtual() = 0",
          "param_spellings": []
        }],
      "declaring_type": 0,
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }, {
      "id": 2,
      "is_operator": false,
      "usr": 15416083548883122431,
      "short_name": "def",
      "detailed_name": "void Foo::def()",
      "kind": 16,
      "declarations": [{
          "spelling": "4:8-4:11",
          "extent": "4:3-4:13",
          "content": "void def()",
          "param_spellings": []
        }],
      "definition_spelling": "7:11-7:14",
      "definition_extent": "7:1-7:19",
      "declaring_type": 0,
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }],
  "vars": []
}
*/
