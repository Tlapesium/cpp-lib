---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.cpp
    title: Sparce Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/data-structure/static_rmq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\r\n#include <bits/stdc++.h>\r\n\
    #line 3 \"data-structure/sparse_table.cpp\"\n\r\n/**\r\n * @title Sparce Table\r\
    \n */\r\n\r\ntemplate<class T, class Comp = std::less<T> >\r\nstruct SparseTable\
    \ {\r\n\tstd::vector<std::vector<T>> st;\r\n\tconst int size;\r\n\tconst Comp\
    \ comp;\r\n\tSparseTable(const std::vector<T>& v, Comp c = Comp()) : size(v.size()),\
    \ comp(c) {\r\n\t\tst.resize(size, std::vector<T>(32 - __builtin_clz(size)));\r\
    \n\t\tfor (int i = 0; i < size; i++) st[i][0] = v[i];\r\n\t\tfor (int i = 1; (1\
    \ << i) <= size; i++) {\r\n\t\t\tfor (int j = 0; j + (1 << i) <= size; j++) {\r\
    \n\t\t\t\tif (comp(st[j][i - 1], st[j + (1 << (i - 1))][i - 1])) {\r\n\t\t\t\t\
    \tst[j][i] = st[j][i - 1];\r\n\t\t\t\t}\r\n\t\t\t\telse {\r\n\t\t\t\t\tst[j][i]\
    \ = st[j + (1 << (i - 1))][i - 1];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\
    \tT get(int l, int r) {\r\n\t\tint k = 32 - __builtin_clz(r - l) - 1;\r\n\t\t\
    if (comp(st[l][k], st[r - (1 << k)][k])) {\r\n\t\t\treturn st[l][k];\r\n\t\t}\r\
    \n\t\telse {\r\n\t\t\treturn st[r - (1 << k)][k];\r\n\t\t}\r\n\t}\r\n};\r\n\r\n\
    template<class T, class Comp>\r\nSparseTable<T, Comp> makeSparseTable(const std::vector<T>&\
    \ v, Comp c) {\r\n\treturn SparseTable<T, Comp>(v, c);\r\n}\r\n#line 4 \"verify/data-structure/static_rmq.test.cpp\"\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\n\r\nint main() {\r\n\t\
    int N, Q;\r\n\tcin >> N >> Q;\r\n\tvector<int> v(N);\r\n\tfor (int i = 0; i <\
    \ N; i++)cin >> v[i];\r\n\tSparseTable ST(v);\r\n\tfor (int i = 0; i < Q; i++)\
    \ {\r\n\t\tint l, r;\r\n\t\tcin >> l >> r;\r\n\t\tcout << ST.get(l, r) << endl;\r\
    \n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n#include\
    \ <bits/stdc++.h>\r\n#include \"data-structure/sparse_table.cpp\"\r\nusing namespace\
    \ std;\r\ntypedef long long ll;\r\n\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tcin\
    \ >> N >> Q;\r\n\tvector<int> v(N);\r\n\tfor (int i = 0; i < N; i++)cin >> v[i];\r\
    \n\tSparseTable ST(v);\r\n\tfor (int i = 0; i < Q; i++) {\r\n\t\tint l, r;\r\n\
    \t\tcin >> l >> r;\r\n\t\tcout << ST.get(l, r) << endl;\r\n\t}\r\n}"
  dependsOn:
  - data-structure/sparse_table.cpp
  isVerificationFile: true
  path: verify/data-structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2021-02-02 04:50:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/static_rmq.test.cpp
- /verify/verify/data-structure/static_rmq.test.cpp.html
title: verify/data-structure/static_rmq.test.cpp
---
