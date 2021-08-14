---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/union_find.cpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.cpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 (Kruskal)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
  bundledCode: "#line 1 \"verify/graph/GRL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\
    \r\n#include <bits/stdc++.h>\r\n#line 2 \"graph/graph.cpp\"\n\r\nstruct Edge {\r\
    \n\tint to; long long cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int\
    \ to, long long cost) : to(to), cost(cost) {}\r\n};\r\nusing Graph = std::vector<std::vector<Edge>>;\n\
    #line 2 \"data-structure/union_find.cpp\"\n\r\nstruct UnionFind {\r\nprivate:\r\
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
    \ {\r\n\t\treturn f_s;\r\n\t}\r\n};\n#line 4 \"graph/kruskal.cpp\"\n\r\nlong long\
    \ kruskal(const Graph& g) {\r\n\tUnionFind UF(g.size());\r\n\tlong long ret =\
    \ 0;\r\n\tstd::vector<std::pair<int, Edge>> edges;\r\n\tfor (int i = 0; i < g.size();\
    \ i++)for (auto e : g[i]) {\r\n\t\tedges.push_back({ i,e });\r\n\t}\r\n\tstd::sort(edges.begin(),\
    \ edges.end(), [](const auto& l, const auto& r) {return l.second.cost < r.second.cost;\
    \ });\r\n\tfor (int i = 0; i < edges.size(); i++) {\r\n\t\tif (!UF.issame(edges[i].first,\
    \ edges[i].second.to) || edges[i].second.cost <= 0) {\r\n\t\t\tret += edges[i].second.cost;\r\
    \n\t\t\tUF.merge(edges[i].first, edges[i].second.to);\r\n\t\t}\r\n\t}\r\n\treturn\
    \ ret;\r\n}\n#line 5 \"verify/graph/GRL_2_A.test.cpp\"\nusing namespace std;\r\
    \ntypedef long long ll;\r\n\r\nint main() {\r\n\tint V, E;\r\n\tcin >> V >> E;\r\
    \n\tGraph g(V);\r\n\tfor (int i = 0; i < E; i++) {\r\n\t\tint s, t, w;\r\n\t\t\
    cin >> s >> t >> w;\r\n\t\tg[s].emplace_back(t, w);\r\n\t\tg[t].emplace_back(s,\
    \ w);\r\n\t}\r\n\tcout << kruskal(g) << endl;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\r\n\
    #include <bits/stdc++.h>\r\n#include \"graph/graph.cpp\"\r\n#include \"graph/kruskal.cpp\"\
    \r\nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint\
    \ V, E;\r\n\tcin >> V >> E;\r\n\tGraph g(V);\r\n\tfor (int i = 0; i < E; i++)\
    \ {\r\n\t\tint s, t, w;\r\n\t\tcin >> s >> t >> w;\r\n\t\tg[s].emplace_back(t,\
    \ w);\r\n\t\tg[t].emplace_back(s, w);\r\n\t}\r\n\tcout << kruskal(g) << endl;\r\
    \n}"
  dependsOn:
  - graph/graph.cpp
  - graph/kruskal.cpp
  - data-structure/union_find.cpp
  isVerificationFile: true
  path: verify/graph/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-08-15 04:52:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/GRL_2_A.test.cpp
- /verify/verify/graph/GRL_2_A.test.cpp.html
title: verify/graph/GRL_2_A.test.cpp
---