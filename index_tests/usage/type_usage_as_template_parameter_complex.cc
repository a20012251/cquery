template<typename T, typename B>
class unique_ptr;

struct S1;
struct S2;

#if false
VarDecl f
  TemplateRef unique_ptr
  TemplateRef unique_ptr
  TypeRef struct S1
  TypeRef struct S2
  TypeRef struct S2
#endif
extern unique_ptr<unique_ptr<S1, S2>, S2> f;

#if false
FunctionDecl as_return_type
  TemplateRef unique_ptr
  TemplateRef unique_ptr
  TypeRef struct S1
  TypeRef struct S2
  TypeRef struct S2
  ParmDecl
    TemplateRef unique_ptr
    TypeRef struct S1
    TypeRef struct S2
  CompoundStmt
    ReturnStmt
      UnexposedExpr
        CXXNullPtrLiteralExpr
#endif
unique_ptr<unique_ptr<S1, S2>, S2>* as_return_type(unique_ptr<S1, S2>*) { return nullptr; }

#if false
FunctionDecl no_return_type
  ParmDecl
  CompoundStmt
#endif
void no_return_type(int) {}

#if false
FunctionDecl empty
  CompoundStmt
    DeclStmt
      VarDecl local
        TemplateRef unique_ptr
        TemplateRef unique_ptr
        TypeRef struct S1
        TypeRef struct S2
        TypeRef struct S2
#endif
void empty() {
  unique_ptr<unique_ptr<S1, S2>, S2>* local;
}

#if false
ClassDecl Foo
  CXXMethod foo
    TemplateRef unique_ptr
    TypeRef struct S1
    TypeRef struct S2
#endif
class Foo {
  unique_ptr<S1, S2>* foo();
};

#if false
CXXMethod foo
  TemplateRef unique_ptr
  TypeRef struct S1
  TypeRef struct S2
  TypeRef class Foo
  CompoundStmt
    ReturnStmt
      UnexposedExpr
        CXXNullPtrLiteralExpr
#endif
unique_ptr<S1, S2>* Foo::foo() { return nullptr; }

/*
OUTPUT:
{
  "includes": [],
  "skipped_by_preprocessor": ["7:1-14:7", "17:1-32:7", "35:1-39:7", "42:1-52:7", "57:1-63:7", "68:1-78:7"],
  "types": [{
      "id": 0,
      "usr": 14209198335088845323,
      "short_name": "",
      "detailed_name": "",
      "kind": 0,
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [],
      "instances": [0, 1],
      "uses": ["2:7-2:17", "15:8-15:18", "15:19-15:29", "33:1-33:11", "33:12-33:22", "33:52-33:62", "54:3-54:13", "54:14-54:24", "65:3-65:13", "79:1-79:11"]
    }, {
      "id": 1,
      "usr": 4310164820010458371,
      "short_name": "",
      "detailed_name": "",
      "kind": 0,
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [],
      "instances": [],
      "uses": ["4:8-4:10", "15:30-15:32", "33:23-33:25", "33:63-33:65", "54:25-54:27", "65:14-65:16", "79:12-79:14"]
    }, {
      "id": 2,
      "usr": 12728490517004312484,
      "short_name": "",
      "detailed_name": "",
      "kind": 0,
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [],
      "instances": [],
      "uses": ["5:8-5:10", "15:34-15:36", "15:39-15:41", "33:27-33:29", "33:32-33:34", "33:67-33:69", "54:29-54:31", "54:34-54:36", "65:18-65:20", "79:16-79:18"]
    }, {
      "id": 3,
      "usr": 15041163540773201510,
      "short_name": "Foo",
      "detailed_name": "Foo",
      "kind": 7,
      "definition_spelling": "64:7-64:10",
      "definition_extent": "64:1-66:2",
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [3],
      "vars": [],
      "instances": [],
      "uses": ["64:7-64:10", "79:21-79:24"]
    }],
  "funcs": [{
      "id": 0,
      "is_operator": false,
      "usr": 1246637699196435450,
      "short_name": "as_return_type",
      "detailed_name": "unique_ptr<unique_ptr<S1, S2>, S2> *as_return_type(unique_ptr<S1, S2> *)",
      "kind": 12,
      "declarations": [],
      "definition_spelling": "33:37-33:51",
      "definition_extent": "33:1-33:92",
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }, {
      "id": 1,
      "is_operator": false,
      "usr": 13067214284561914253,
      "short_name": "no_return_type",
      "detailed_name": "void no_return_type(int)",
      "kind": 12,
      "declarations": [],
      "definition_spelling": "40:6-40:20",
      "definition_extent": "40:1-40:28",
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }, {
      "id": 2,
      "is_operator": false,
      "usr": 18320186404467436976,
      "short_name": "empty",
      "detailed_name": "void empty()",
      "kind": 12,
      "declarations": [],
      "definition_spelling": "53:6-53:11",
      "definition_extent": "53:1-55:2",
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }, {
      "id": 3,
      "is_operator": false,
      "usr": 17922201480358737771,
      "short_name": "foo",
      "detailed_name": "unique_ptr<S1, S2> *Foo::foo()",
      "kind": 16,
      "declarations": [{
          "spelling": "65:23-65:26",
          "extent": "65:3-65:28",
          "content": "unique_ptr<S1, S2>* foo()",
          "param_spellings": []
        }],
      "definition_spelling": "79:26-79:29",
      "definition_extent": "79:1-79:51",
      "declaring_type": 3,
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": []
    }],
  "vars": [{
      "id": 0,
      "usr": 2933643612409209903,
      "short_name": "f",
      "detailed_name": "unique_ptr<unique_ptr<S1, S2>, S2> f",
      "declaration": "15:43-15:44",
      "variable_type": 0,
      "kind": 13,
      "uses": ["15:43-15:44"]
    }, {
      "id": 1,
      "usr": 11547294959889394856,
      "short_name": "local",
      "detailed_name": "unique_ptr<unique_ptr<S1, S2>, S2> *local",
      "definition_spelling": "54:39-54:44",
      "definition_extent": "54:3-54:44",
      "variable_type": 0,
      "kind": 13,
      "uses": ["54:39-54:44"]
    }]
}
*/
