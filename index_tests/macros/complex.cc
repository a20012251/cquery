#define FOO(aaa, bbb) \
  int a();\
  int a() { return aaa + bbb; }


int make1() {
  return 3;
}
const int make2 = 5;


FOO(make1(), make2);

/*
OUTPUT:
{
  "includes": [],
  "skipped_by_preprocessor": [],
  "types": [],
  "funcs": [{
      "id": 0,
      "is_operator": false,
      "usr": 14400399977994209582,
      "short_name": "make1",
      "detailed_name": "int make1()",
      "kind": 12,
      "declarations": [],
      "definition_spelling": "6:5-6:10",
      "definition_extent": "6:1-8:2",
      "base": [],
      "derived": [],
      "locals": [],
      "callers": ["1@12:5-12:10"],
      "callees": []
    }, {
      "id": 1,
      "is_operator": false,
      "usr": 9720930732776154610,
      "short_name": "a",
      "detailed_name": "int a()",
      "kind": 12,
      "declarations": [{
          "spelling": "12:1-12:20",
          "extent": "12:1-12:20",
          "content": "int a();\n  int a() { return aaa + bbb; }\n\n\nint make1() {\n  return 3;\n}\nconst int make2 = 5;\n\n\nFOO(make1(), make2)",
          "param_spellings": []
        }],
      "definition_spelling": "12:1-12:20",
      "definition_extent": "12:1-12:20",
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": ["0@12:5-12:10"]
    }],
  "vars": [{
      "id": 0,
      "usr": 2878407290385495202,
      "short_name": "make2",
      "detailed_name": "const int make2",
      "hover": "const int make2 = 5",
      "definition_spelling": "9:11-9:16",
      "definition_extent": "9:1-9:20",
      "kind": 13,
      "uses": ["9:11-9:16", "12:14-12:19"]
    }, {
      "id": 1,
      "usr": 4261071340275951718,
      "short_name": "FOO",
      "detailed_name": "FOO",
      "hover": "#define FOO(aaa, bbb)\n  int a();\n  int a() { return aaa + bbb; }",
      "definition_spelling": "1:9-1:12",
      "definition_extent": "1:9-3:32",
      "kind": 4,
      "uses": ["1:9-1:12", "12:1-12:4"]
    }]
}
*/