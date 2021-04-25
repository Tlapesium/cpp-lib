---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_5_A.test.cpp
    title: verify/graph/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/tree_diameter.test.cpp
    title: verify/graph/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.cpp\"\n\r\nstruct Edge {\r\n\tint to; long long\
    \ cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int to, long long cost)\
    \ : to(to), cost(cost) {}\r\n};\r\nusing Graph = std::vector<std::vector<Edge>>;\n\
    #line 3 \"graph/tree_diameter.cpp\"\n\r\nauto tree_diameter(const Graph& g) {\r\
    \n\tstd::vector<long long> dist(g.size(), 0);\r\n\tstd::vector<int> v;\r\n\tauto\
    \ dfs = [&](auto&& dfs, int pos, int par, long long d, int dest) -> bool {\r\n\
    \t\tbool flag = pos == dest;\r\n\t\tfor (auto&& e : g[pos]) {\r\n\t\t\tif (e.to\
    \ == par)continue;\r\n\t\t\tflag |= dfs(dfs, e.to, pos, d + e.cost, dest);\r\n\
    \t\t\tdist[e.to] = d + e.cost;\r\n\t\t}\r\n\t\tif (flag)v.push_back(pos);\r\n\t\
    \treturn flag;\r\n\t};\r\n\tdfs(dfs, 0, -1, 0, -1);\r\n\tint p = std::max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\r\n\tdist[p] = 0;\r\n\tdfs(dfs, p, -1, 0, -1);\r\
    \n\tint q = std::max_element(dist.begin(), dist.end()) - dist.begin();\r\n\tdfs(dfs,\
    \ p, -1, 0, q);\r\n\treturn std::make_pair(*std::max_element(dist.begin(), dist.end()),\
    \ v);\r\n}\n"
  code: "#pragma once\r\n#include \"graph/graph.cpp\"\r\n\r\nauto tree_diameter(const\
    \ Graph& g) {\r\n\tstd::vector<long long> dist(g.size(), 0);\r\n\tstd::vector<int>\
    \ v;\r\n\tauto dfs = [&](auto&& dfs, int pos, int par, long long d, int dest)\
    \ -> bool {\r\n\t\tbool flag = pos == dest;\r\n\t\tfor (auto&& e : g[pos]) {\r\
    \n\t\t\tif (e.to == par)continue;\r\n\t\t\tflag |= dfs(dfs, e.to, pos, d + e.cost,\
    \ dest);\r\n\t\t\tdist[e.to] = d + e.cost;\r\n\t\t}\r\n\t\tif (flag)v.push_back(pos);\r\
    \n\t\treturn flag;\r\n\t};\r\n\tdfs(dfs, 0, -1, 0, -1);\r\n\tint p = std::max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\r\n\tdist[p] = 0;\r\n\tdfs(dfs, p, -1, 0, -1);\r\
    \n\tint q = std::max_element(dist.begin(), dist.end()) - dist.begin();\r\n\tdfs(dfs,\
    \ p, -1, 0, q);\r\n\treturn std::make_pair(*std::max_element(dist.begin(), dist.end()),\
    \ v);\r\n}"
  dependsOn:
  - graph/graph.cpp
  isVerificationFile: false
  path: graph/tree_diameter.cpp
  requiredBy: []
  timestamp: '2021-03-14 00:13:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/GRL_5_A.test.cpp
  - verify/graph/tree_diameter.test.cpp
documentation_of: graph/tree_diameter.cpp
layout: document
title: "\u6728\u306E\u76F4\u5F84"
---

## 説明
無向木 $g$ の直径を求める。直径と直径を構成する頂点列のペアを返す。