---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/union_find.cpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc065/tasks/arc065_b
    links:
    - https://atcoder.jp/contests/arc065/tasks/arc065_b
  bundledCode: "#line 1 \"verify/data-structure/ABC049-D.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc065/tasks/arc065_b\"\r\n#include <bits/stdc++.h>\r\
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
    \ {\r\n\t\treturn f_s;\r\n\t}\r\n};\n#line 4 \"verify/data-structure/ABC049-D.test.cpp\"\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint N,\
    \ K, L;\r\n\tcin >> N >> K >> L;\r\n\tUnionFind UF1(N), UF2(N);\r\n\tfor (int\
    \ i = 0; i < K; i++) {\r\n\t\tint p, q;\r\n\t\tcin >> p >> q;\r\n\t\tUF1.merge(p\
    \ - 1, q - 1);\r\n\t}\r\n\tfor (int i = 0; i < L; i++) {\r\n\t\tint p, q;\r\n\t\
    \tcin >> p >> q;\r\n\t\tUF2.merge(p - 1, q - 1);\r\n\t}\r\n\tmap<pair<int, int>,\
    \ int> cnt;\r\n\tfor (int i = 0; i < N; i++) {\r\n\t\tcnt[{UF1.root(i), UF2.root(i)}]++;\r\
    \n\t}\r\n\tfor (int i = 0; i < N; i++) {\r\n\t\tcout << cnt[{UF1.root(i), UF2.root(i)}]\
    \ << ' ';\r\n\t}\r\n    cout << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc065/tasks/arc065_b\"\r\n\
    #include <bits/stdc++.h>\r\n#include \"data-structure/union_find.cpp\"\r\nusing\
    \ namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint N, K, L;\r\
    \n\tcin >> N >> K >> L;\r\n\tUnionFind UF1(N), UF2(N);\r\n\tfor (int i = 0; i\
    \ < K; i++) {\r\n\t\tint p, q;\r\n\t\tcin >> p >> q;\r\n\t\tUF1.merge(p - 1, q\
    \ - 1);\r\n\t}\r\n\tfor (int i = 0; i < L; i++) {\r\n\t\tint p, q;\r\n\t\tcin\
    \ >> p >> q;\r\n\t\tUF2.merge(p - 1, q - 1);\r\n\t}\r\n\tmap<pair<int, int>, int>\
    \ cnt;\r\n\tfor (int i = 0; i < N; i++) {\r\n\t\tcnt[{UF1.root(i), UF2.root(i)}]++;\r\
    \n\t}\r\n\tfor (int i = 0; i < N; i++) {\r\n\t\tcout << cnt[{UF1.root(i), UF2.root(i)}]\
    \ << ' ';\r\n\t}\r\n    cout << endl;\r\n}\r\n"
  dependsOn:
  - data-structure/union_find.cpp
  isVerificationFile: true
  path: verify/data-structure/ABC049-D.test.cpp
  requiredBy: []
  timestamp: '2021-10-13 22:26:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/data-structure/ABC049-D.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/ABC049-D.test.cpp
- /verify/verify/data-structure/ABC049-D.test.cpp.html
title: verify/data-structure/ABC049-D.test.cpp
---
