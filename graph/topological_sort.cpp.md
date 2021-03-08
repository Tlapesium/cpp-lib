---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"graph/topological_sort.cpp\"\n#include <vector>\r\n#include\
    \ <algorithm>\r\n\r\nauto topological_sort(const Graph& g) {\r\n\tbool cycle_flag\
    \ = false;\r\n\tstd::vector<int> ret, used(g.size(), 0);\r\n\r\n\tauto dfs = [&](auto&&\
    \ dfs, const Graph& g, int pos) -> void {\r\n\t\tif (used[pos] == 1) cycle_flag\
    \ = true;\r\n\t\telse if (used[pos] == 0) {\r\n\t\t\tused[pos] = 1;\r\n\t\t\t\
    for (int i = 0; i < g[pos].size(); i++) {\r\n\t\t\t\tdfs(dfs, g, g[pos][i].to);\r\
    \n\t\t\t}\r\n\t\t\tused[pos] = 2;\r\n\t\t\tret.push_back(pos);\r\n\t\t}\r\n\t\
    };\r\n\r\n\tfor (int i = 0; i < g.size(); i++) {\r\n\t\tif (used[i] == 0)dfs(dfs,\
    \ g, i);\r\n\t\tif (cycle_flag)return std::vector<int>();\r\n\t}\r\n\tstd::reverse(ret.begin(),\
    \ ret.end());\r\n\treturn ret;\r\n}\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n\r\nauto topological_sort(const\
    \ Graph& g) {\r\n\tbool cycle_flag = false;\r\n\tstd::vector<int> ret, used(g.size(),\
    \ 0);\r\n\r\n\tauto dfs = [&](auto&& dfs, const Graph& g, int pos) -> void {\r\
    \n\t\tif (used[pos] == 1) cycle_flag = true;\r\n\t\telse if (used[pos] == 0) {\r\
    \n\t\t\tused[pos] = 1;\r\n\t\t\tfor (int i = 0; i < g[pos].size(); i++) {\r\n\t\
    \t\t\tdfs(dfs, g, g[pos][i].to);\r\n\t\t\t}\r\n\t\t\tused[pos] = 2;\r\n\t\t\t\
    ret.push_back(pos);\r\n\t\t}\r\n\t};\r\n\r\n\tfor (int i = 0; i < g.size(); i++)\
    \ {\r\n\t\tif (used[i] == 0)dfs(dfs, g, i);\r\n\t\tif (cycle_flag)return std::vector<int>();\r\
    \n\t}\r\n\tstd::reverse(ret.begin(), ret.end());\r\n\treturn ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.cpp
  requiredBy: []
  timestamp: '2021-03-08 20:36:50+09:00'
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