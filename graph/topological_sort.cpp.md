---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_4_A.test.cpp
    title: verify/graph/GRL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_4_B.test.cpp
    title: verify/graph/GRL_4_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.cpp\"\n\r\nstruct Edge {\r\n\tint to; long long\
    \ cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int to, long long cost)\
    \ : to(to), cost(cost) {}\r\n};\r\nusing Graph = std::vector<std::vector<Edge>>;\n\
    #line 3 \"graph/topological_sort.cpp\"\n\r\nauto topological_sort(const Graph&\
    \ g) {\r\n\tbool cycle_flag = false;\r\n\tstd::vector<int> ret, used(g.size(),\
    \ 0);\r\n\r\n\tauto dfs = [&](auto&& dfs, int pos) -> void {\r\n\t\tif (used[pos]\
    \ == 1) cycle_flag = true;\r\n\t\telse if (used[pos] == 0) {\r\n\t\t\tused[pos]\
    \ = 1;\r\n\t\t\tfor (auto&& e : g[pos]) {\r\n\t\t\t\tdfs(dfs, e.to);\r\n\t\t\t\
    }\r\n\t\t\tused[pos] = 2;\r\n\t\t\tret.push_back(pos);\r\n\t\t}\r\n\t};\r\n\r\n\
    \tfor (int i = 0; i < g.size(); i++) {\r\n\t\tif (!used[i])dfs(dfs, i);\r\n\t\t\
    if (cycle_flag)return std::vector<int>();\r\n\t}\r\n\tstd::reverse(ret.begin(),\
    \ ret.end());\r\n\treturn ret;\r\n}\n"
  code: "#pragma once\r\n#include \"graph/graph.cpp\"\r\n\r\nauto topological_sort(const\
    \ Graph& g) {\r\n\tbool cycle_flag = false;\r\n\tstd::vector<int> ret, used(g.size(),\
    \ 0);\r\n\r\n\tauto dfs = [&](auto&& dfs, int pos) -> void {\r\n\t\tif (used[pos]\
    \ == 1) cycle_flag = true;\r\n\t\telse if (used[pos] == 0) {\r\n\t\t\tused[pos]\
    \ = 1;\r\n\t\t\tfor (auto&& e : g[pos]) {\r\n\t\t\t\tdfs(dfs, e.to);\r\n\t\t\t\
    }\r\n\t\t\tused[pos] = 2;\r\n\t\t\tret.push_back(pos);\r\n\t\t}\r\n\t};\r\n\r\n\
    \tfor (int i = 0; i < g.size(); i++) {\r\n\t\tif (!used[i])dfs(dfs, i);\r\n\t\t\
    if (cycle_flag)return std::vector<int>();\r\n\t}\r\n\tstd::reverse(ret.begin(),\
    \ ret.end());\r\n\treturn ret;\r\n}"
  dependsOn:
  - graph/graph.cpp
  isVerificationFile: false
  path: graph/topological_sort.cpp
  requiredBy: []
  timestamp: '2021-03-12 03:00:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/GRL_4_B.test.cpp
  - verify/graph/GRL_4_A.test.cpp
documentation_of: graph/topological_sort.cpp
layout: document
title: Topological Sort
---

## 説明
有向グラフ $g$ の頂点をトポロジカル順序順に並び変える。

閉路が存在するときは空のvectorを返す。