---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union_find.cpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"verify/data-structure/ABC120-D.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\r\n#include\
    \ <bits/stdc++.h>\r\n#line 2 \"data-structure/union_find.cpp\"\n\r\nstruct UnionFind\
    \ {\r\nprivate:\r\n\tstd::vector<int> siz, par;\r\n\tstd::vector<long long> wei;\r\
    \n\tint f_s;\r\npublic:\r\n\tUnionFind(int size) : f_s(size) {\r\n\t\tsiz.assign(size,\
    \ 1);\r\n\t\twei.assign(size, 0);\r\n\t\tpar.assign(size, 0);\r\n\t\tfor (int\
    \ i = 0; i < size; i++)par[i] = i;\r\n\t}\r\n\tbool merge(int x, int y, long long\
    \ w = 0) {\r\n\t\tw += weight(x); w -= weight(y);\r\n\t\tx = root(x); y = root(y);\r\
    \n\t\tif (x == y)return false;\r\n\t\tif (siz[x] < siz[y])std::swap(x, y), w =\
    \ -w;\r\n\t\tsiz[x] += siz[y];\r\n\t\tpar[y] = x;\r\n\t\twei[y] = w;\r\n\t\tf_s--;\r\
    \n\t\treturn true;\r\n\t}\r\n\tlong long weight(int x) {\r\n\t\troot(x);\r\n\t\
    \treturn wei[x];\r\n\t}\r\n\tint root(int k) {\r\n\t\tif (par[k] == k)return k;\r\
    \n\t\tint tmp = root(par[k]);\r\n\t\twei[k] += wei[par[k]];\r\n\t\treturn par[k]\
    \ = tmp;\r\n\t}\r\n\tbool issame(int x, int y) {\r\n\t\treturn root(x) == root(y);\r\
    \n\t}\r\n\tlong long diff(int x, int y) {\r\n\t\treturn weight(y) - weight(x);\r\
    \n\t}\r\n\tint size(int x) {\r\n\t\treturn siz[root(x)];\r\n\t}\r\n\tint forest_size()\
    \ {\r\n\t\treturn f_s;\r\n\t}\r\n};\n#line 4 \"verify/data-structure/ABC120-D.cpp\"\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tll N,\
    \ M;\r\n\tcin >> N >> M;\r\n\tUnionFind uf(N);\r\n\tvector<pair<int, int>> e(M);\r\
    \n\tvector<ll> ans(M);\r\n\tfor (int i = 0; i < M; i++) {\r\n\t\tcin >> e[i].first\
    \ >> e[i].second;\r\n\t\te[i].first--; e[i].second--;\r\n\t}\r\n\tll tmp = N *\
    \ (N - 1) / 2;;\r\n\tfor (int i = M - 1; i >= 0; i--) {\r\n\t\tans[i] = tmp;\r\
    \n\t\tif (uf.issame(e[i].first, e[i].second))continue;\r\n\t\ttmp -= ll(uf.size(e[i].first))\
    \ * ll(uf.size(e[i].second));\r\n\t\tuf.merge(e[i].first, e[i].second);\r\n\t\
    }\r\n\tfor (int i = 0; i < M; i++)cout << ans[i] << endl;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \r\n#include <bits/stdc++.h>\r\n#include \"data-structure/union_find.cpp\"\r\n\
    using namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tll N, M;\r\
    \n\tcin >> N >> M;\r\n\tUnionFind uf(N);\r\n\tvector<pair<int, int>> e(M);\r\n\
    \tvector<ll> ans(M);\r\n\tfor (int i = 0; i < M; i++) {\r\n\t\tcin >> e[i].first\
    \ >> e[i].second;\r\n\t\te[i].first--; e[i].second--;\r\n\t}\r\n\tll tmp = N *\
    \ (N - 1) / 2;;\r\n\tfor (int i = M - 1; i >= 0; i--) {\r\n\t\tans[i] = tmp;\r\
    \n\t\tif (uf.issame(e[i].first, e[i].second))continue;\r\n\t\ttmp -= ll(uf.size(e[i].first))\
    \ * ll(uf.size(e[i].second));\r\n\t\tuf.merge(e[i].first, e[i].second);\r\n\t\
    }\r\n\tfor (int i = 0; i < M; i++)cout << ans[i] << endl;\r\n}"
  dependsOn:
  - data-structure/union_find.cpp
  isVerificationFile: false
  path: verify/data-structure/ABC120-D.cpp
  requiredBy: []
  timestamp: '2021-08-15 04:52:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/data-structure/ABC120-D.cpp
layout: document
redirect_from:
- /library/verify/data-structure/ABC120-D.cpp
- /library/verify/data-structure/ABC120-D.cpp.html
title: verify/data-structure/ABC120-D.cpp
---
