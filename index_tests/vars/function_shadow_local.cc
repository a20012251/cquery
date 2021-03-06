void foo() {
  int a;
  a = 1;
  {
    int a;
    a = 2;
  }
  a = 3;
}
/*
OUTPUT:
{
  "includes": [],
  "skipped_by_preprocessor": [],
  "types": [],
  "funcs": [{
      "id": 0,
      "is_operator": false,
      "usr": 4259594751088586730,
      "short_name": "foo",
      "detailed_name": "void foo()",
      "kind": 12,
      "declarations": [],
      "definition_spelling": "1:6-1:9",
      "definition_extent": "1:1-9:2",
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }],
  "vars": [{
      "id": 0,
      "usr": 3440226937504376525,
      "short_name": "a",
      "detailed_name": "int a",
      "definition_spelling": "2:7-2:8",
      "definition_extent": "2:3-2:8",
      "kind": 13,
      "uses": ["2:7-2:8", "3:3-3:4", "8:3-8:4"]
    }, {
      "id": 1,
      "usr": 14700715011944976607,
      "short_name": "a",
      "detailed_name": "int a",
      "definition_spelling": "5:9-5:10",
      "definition_extent": "5:5-5:10",
      "kind": 13,
      "uses": ["5:9-5:10", "6:5-6:6"]
    }]
}
*/
