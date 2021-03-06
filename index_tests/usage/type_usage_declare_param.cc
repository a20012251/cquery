struct ForwardType;
struct ImplementedType {};

void foo(ForwardType* f, ImplementedType a) {}

/*
OUTPUT:
{
  "includes": [],
  "skipped_by_preprocessor": [],
  "types": [{
      "id": 0,
      "usr": 13749354388332789217,
      "short_name": "",
      "detailed_name": "",
      "kind": 0,
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [],
      "instances": [0],
      "uses": ["1:8-1:19", "4:10-4:21"]
    }, {
      "id": 1,
      "usr": 8508299082070213750,
      "short_name": "ImplementedType",
      "detailed_name": "ImplementedType",
      "kind": 6,
      "definition_spelling": "2:8-2:23",
      "definition_extent": "2:1-2:26",
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [],
      "instances": [1],
      "uses": ["2:8-2:23", "4:26-4:41"]
    }],
  "funcs": [{
      "id": 0,
      "is_operator": false,
      "usr": 1699390678058422036,
      "short_name": "foo",
      "detailed_name": "void foo(ForwardType *f, ImplementedType a)",
      "kind": 12,
      "declarations": [],
      "definition_spelling": "4:6-4:9",
      "definition_extent": "4:1-4:47",
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }],
  "vars": [{
      "id": 0,
      "usr": 2584795197111552890,
      "short_name": "f",
      "detailed_name": "ForwardType *f",
      "definition_spelling": "4:23-4:24",
      "definition_extent": "4:10-4:24",
      "variable_type": 0,
      "kind": 25,
      "uses": ["4:23-4:24"]
    }, {
      "id": 1,
      "usr": 5136230284979460117,
      "short_name": "a",
      "detailed_name": "ImplementedType a",
      "definition_spelling": "4:42-4:43",
      "definition_extent": "4:26-4:43",
      "variable_type": 1,
      "kind": 25,
      "uses": ["4:42-4:43"]
    }]
}
*/
