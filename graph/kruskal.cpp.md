---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union_find.cpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_2_A.test.cpp
    title: verify/graph/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.cpp\"\n\r\nstruct Edge {\r\n\tint to; long long\
    \ cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int to, long long cost)\
    \ : to(to), cost(cost) {}\r\n};\r\nusing Graph = std::vector<std::vector<Edge>>;\n\
    #line 2 \"data-structure/union_find.cpp\"\n\r\nstruct UnionFind {\r\n\tstd::vector<int>\
    \ siz, par;\r\n\tstd::vector<long long> wei;\r\n\tint f_s;\r\n\r\n\tUnionFind(int\
    \ size) : f_s(size) {\r\n\t\tsiz.assign(size, 1);\r\n\t\twei.assign(size, 0);\r\
    \n\t\tpar.assign(size, 0);\r\n\t\tfor (int i = 0; i < size; i++)par[i] = i;\r\n\
    \t}\r\n\tbool merge(int x, int y, long long w = 0) {\r\n\t\tw += weight(x); w\
    \ -= weight(y);\r\n\t\tx = root(x); y = root(y);\r\n\t\tif (x == y)return false;\r\
    \n\t\tif (siz[x] < siz[y])std::swap(x, y), w = -w;\r\n\t\tsiz[x] += siz[y];\r\n\
    \t\tpar[y] = x;\r\n\t\twei[y] = w;\r\n\t\tf_s--;\r\n\t\treturn true;\r\n\t}\r\n\
    \tlong long weight(int x) {\r\n\t\troot(x);\r\n\t\treturn wei[x];\r\n\t}\r\n\t\
    int root(int k) {\r\n\t\tif (par[k] == k)return k;\r\n\t\tint tmp = root(par[k]);\r\
    \n\t\twei[k] += wei[par[k]];\r\n\t\treturn par[k] = tmp;\r\n\t}\r\n\tbool issame(int\
    \ x, int y) {\r\n\t\treturn root(x) == root(y);\r\n\t}\r\n\tlong long diff(int\
    \ x, int y) {\r\n\t\treturn weight(y) - weight(x);\r\n\t}\r\n\tint size(int x)\
    \ {\r\n\t\treturn siz[x];\r\n\t}\r\n\tint forest_size() {\r\n\t\treturn f_s;\r\
    \n\t}\r\n};\r\n#line 4 \"graph/kruskal.cpp\"\n\r\nlong long kruskal(const Graph&\
    \ g) {\r\n\tUnionFind UF(g.size());\r\n\tlong long ret = 0;\r\n\tstd::vector<std::pair<int,\
    \ Edge>> edges;\r\n\tfor (int i = 0; i < g.size(); i++)for (auto e : g[i]) {\r\
    \n\t\tedges.push_back({ i,e });\r\n\t}\r\n\tstd::sort(edges.begin(), edges.end(),\
    \ [](const auto& l, const auto& r) {return l.second.cost < r.second.cost; });\r\
    \n\tfor (int i = 0; i < edges.size(); i++) {\r\n\t\tif (!UF.issame(edges[i].first,\
    \ edges[i].second.to) || edges[i].second.cost <= 0) {\r\n\t\t\tret += edges[i].second.cost;\r\
    \n\t\t\tUF.merge(edges[i].first, edges[i].second.to);\r\n\t\t}\r\n\t}\r\n\treturn\
    \ ret;\r\n}\n"
  code: "#pragma once\r\n#include \"graph/graph.cpp\"\r\n#include \"data-structure/union_find.cpp\"\
    \r\n\r\nlong long kruskal(const Graph& g) {\r\n\tUnionFind UF(g.size());\r\n\t\
    long long ret = 0;\r\n\tstd::vector<std::pair<int, Edge>> edges;\r\n\tfor (int\
    \ i = 0; i < g.size(); i++)for (auto e : g[i]) {\r\n\t\tedges.push_back({ i,e\
    \ });\r\n\t}\r\n\tstd::sort(edges.begin(), edges.end(), [](const auto& l, const\
    \ auto& r) {return l.second.cost < r.second.cost; });\r\n\tfor (int i = 0; i <\
    \ edges.size(); i++) {\r\n\t\tif (!UF.issame(edges[i].first, edges[i].second.to)\
    \ || edges[i].second.cost <= 0) {\r\n\t\t\tret += edges[i].second.cost;\r\n\t\t\
    \tUF.merge(edges[i].first, edges[i].second.to);\r\n\t\t}\r\n\t}\r\n\treturn ret;\r\
    \n}"
  dependsOn:
  - graph/graph.cpp
  - data-structure/union_find.cpp
  isVerificationFile: false
  path: graph/kruskal.cpp
  requiredBy: []
  timestamp: '2021-03-12 03:00:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/GRL_2_A.test.cpp
documentation_of: graph/kruskal.cpp
layout: document
title: "\u6700\u5C0F\u5168\u57DF\u6728 (Kruskal)"
---

## 説明
無向グラフ $g$ の最小全域木の辺の重みの総和を求める。