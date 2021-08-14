---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/union_find.cpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
  bundledCode: "#line 1 \"verify/data-structure/DSL_1_A.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\"\r\n#include <bits/stdc++.h>\r\
    \n#line 2 \"data-structure/union_find.cpp\"\n\r\nstruct UnionFind {\r\nprivate:\r\
    \n\tstd::vector<int> siz, par;\r\n\tstd::vector<long long> wei;\r\n\tint f_s;\r\
    \npublic:\r\n\tUnionFind(int size) : f_s(size) {\r\n\t\tsiz.assign(size, 1);\r\
    \n\t\twei.assign(size, 0);\r\n\t\tpar.assign(size, 0);\r\n\t\tfor (int i = 0;\
    \ i < size; i++)par[i] = i;\r\n\t}\r\n\tbool merge(int x, int y, long long w =\
    \ 0) {\r\n\t\tw += weight(x); w -= weight(y);\r\n\t\tx = root(x); y = root(y);\r\
    \n\t\tif (x == y)return false;\r\n\t\tif (siz[x] < siz[y])std::swap(x, y), w =\
    \ -w;\r\n\t\tsiz[x] += siz[y];\r\n\t\tpar[y] = x;\r\n\t\twei[y] = w;\r\n\t\tf_s--;\r\
    \n\t\treturn true;\r\n\t}\r\n\tlong long weight(int x) {\r\n\t\troot(x);\r\n\t\
    \treturn wei[x];\r\n\t}\r\n\tint root(int k) {\r\n\t\tif (par[k] == k)return k;\r\
    \n\t\tint tmp = root(par[k]);\r\n\t\twei[k] += wei[par[k]];\r\n\t\treturn par[k]\
    \ = tmp;\r\n\t}\r\n\tbool issame(int x, int y) {\r\n\t\treturn root(x) == root(y);\r\
    \n\t}\r\n\tlong long diff(int x, int y) {\r\n\t\treturn weight(y) - weight(x);\r\
    \n\t}\r\n\tint size(int x) {\r\n\t\treturn siz[root(x)];\r\n\t}\r\n\tint forest_size()\
    \ {\r\n\t\treturn f_s;\r\n\t}\r\n};\n#line 4 \"verify/data-structure/DSL_1_A.test.cpp\"\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint N,\
    \ Q;\r\n\tcin >> N >> Q;\r\n\tUnionFind UF(N);\r\n\tfor (int i = 0; i < Q; i++)\
    \ {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint x, y;\r\n\
    \t\t\tcin >> x >> y;\r\n\t\t\tUF.merge(x, y);\r\n\t\t}\r\n\t\tif (t == 1) {\r\n\
    \t\t\tint x, y;\r\n\t\t\tcin >> x >> y;\r\n\t\t\tcout << UF.issame(x, y) << endl;\r\
    \n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\"\r\n\
    #include <bits/stdc++.h>\r\n#include \"data-structure/union_find.cpp\"\r\nusing\
    \ namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint N, Q;\r\
    \n\tcin >> N >> Q;\r\n\tUnionFind UF(N);\r\n\tfor (int i = 0; i < Q; i++) {\r\n\
    \t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint x, y;\r\n\t\t\t\
    cin >> x >> y;\r\n\t\t\tUF.merge(x, y);\r\n\t\t}\r\n\t\tif (t == 1) {\r\n\t\t\t\
    int x, y;\r\n\t\t\tcin >> x >> y;\r\n\t\t\tcout << UF.issame(x, y) << endl;\r\n\
    \t\t}\r\n\t}\r\n}"
  dependsOn:
  - data-structure/union_find.cpp
  isVerificationFile: true
  path: verify/data-structure/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-08-15 04:52:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/DSL_1_A.test.cpp
- /verify/verify/data-structure/DSL_1_A.test.cpp.html
title: verify/data-structure/DSL_1_A.test.cpp
---
