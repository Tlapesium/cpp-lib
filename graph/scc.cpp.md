---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_3_C.test.cpp
    title: verify/graph/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/scc.test.cpp
    title: verify/graph/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.cpp\"\n\r\nstruct Edge {\r\n\tint to; long long\
    \ cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int to, long long cost)\
    \ : to(to), cost(cost) {}\r\n};\r\nusing Graph = std::vector<std::vector<Edge>>;\n\
    #line 3 \"graph/scc.cpp\"\n\r\nstruct StronglyConnectedComponents {\r\n\tGraph\
    \ g, rg;\r\n\tstd::vector<int> comp;\r\n\tstd::vector<std::vector<int>> group;\r\
    \n\r\n\tStronglyConnectedComponents(Graph& g) : g(g), rg(g.size()), comp(g.size(),\
    \ -1) {\r\n\t\tfor (int i = 0; i < g.size(); i++) {\r\n\t\t\tfor (auto&& e : g[i])\
    \ {\r\n\t\t\t\trg[e.to].emplace_back(i);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\t\
    Graph build() {\r\n\t\tstd::vector<int> order, used(g.size(), 0);\r\n\t\tauto\
    \ dfs = [&](auto&& dfs, int pos) -> void {\r\n\t\t\tif (used[pos])return;\r\n\t\
    \t\tused[pos] = true;\r\n\t\t\tfor (auto&& e : g[pos]) dfs(dfs, e.to);\r\n\t\t\
    \torder.push_back(pos);\r\n\t\t};\r\n\r\n\t\tauto rdfs = [&](auto&& rdfs, int\
    \ pos, int cnt) -> void {\r\n\t\t\tif (comp[pos] != -1)return;\r\n\t\t\tcomp[pos]\
    \ = cnt;\r\n\t\t\tfor (auto&& e : rg[pos])rdfs(rdfs, e.to, cnt);\r\n\t\t};\r\n\
    \r\n\t\tfor (int i = 0; i < g.size(); i++)dfs(dfs, i);\r\n\t\tstd::reverse(order.begin(),\
    \ order.end());\r\n\t\tint cnt = 0;\r\n\t\tfor (auto&& v : order)if (comp[v] ==\
    \ -1)rdfs(rdfs, v, cnt), cnt++;\r\n\r\n\t\tGraph ret(cnt);\r\n\t\tfor (int i =\
    \ 0; i < g.size(); i++) {\r\n\t\t\tfor (auto&& e : g[i]) {\r\n\t\t\t\tint x =\
    \ comp[i], y = comp[e.to];\r\n\t\t\t\tif (x == y)continue;\r\n\t\t\t\tret[x].emplace_back(y,\
    \ e.cost);\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\tgroup.resize(cnt);\r\n\t\tfor (int i\
    \ = 0; i < g.size(); i++) {\r\n\t\t\tgroup[comp[i]].push_back(i);\r\n\t\t}\r\n\
    \r\n\t\treturn ret;\r\n\t}\r\n\r\n\tint operator[] (int k) const {\r\n\t\treturn\
    \ comp[k];\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n#include \"graph/graph.cpp\"\r\n\r\nstruct StronglyConnectedComponents\
    \ {\r\n\tGraph g, rg;\r\n\tstd::vector<int> comp;\r\n\tstd::vector<std::vector<int>>\
    \ group;\r\n\r\n\tStronglyConnectedComponents(Graph& g) : g(g), rg(g.size()),\
    \ comp(g.size(), -1) {\r\n\t\tfor (int i = 0; i < g.size(); i++) {\r\n\t\t\tfor\
    \ (auto&& e : g[i]) {\r\n\t\t\t\trg[e.to].emplace_back(i);\r\n\t\t\t}\r\n\t\t\
    }\r\n\t}\r\n\r\n\tGraph build() {\r\n\t\tstd::vector<int> order, used(g.size(),\
    \ 0);\r\n\t\tauto dfs = [&](auto&& dfs, int pos) -> void {\r\n\t\t\tif (used[pos])return;\r\
    \n\t\t\tused[pos] = true;\r\n\t\t\tfor (auto&& e : g[pos]) dfs(dfs, e.to);\r\n\
    \t\t\torder.push_back(pos);\r\n\t\t};\r\n\r\n\t\tauto rdfs = [&](auto&& rdfs,\
    \ int pos, int cnt) -> void {\r\n\t\t\tif (comp[pos] != -1)return;\r\n\t\t\tcomp[pos]\
    \ = cnt;\r\n\t\t\tfor (auto&& e : rg[pos])rdfs(rdfs, e.to, cnt);\r\n\t\t};\r\n\
    \r\n\t\tfor (int i = 0; i < g.size(); i++)dfs(dfs, i);\r\n\t\tstd::reverse(order.begin(),\
    \ order.end());\r\n\t\tint cnt = 0;\r\n\t\tfor (auto&& v : order)if (comp[v] ==\
    \ -1)rdfs(rdfs, v, cnt), cnt++;\r\n\r\n\t\tGraph ret(cnt);\r\n\t\tfor (int i =\
    \ 0; i < g.size(); i++) {\r\n\t\t\tfor (auto&& e : g[i]) {\r\n\t\t\t\tint x =\
    \ comp[i], y = comp[e.to];\r\n\t\t\t\tif (x == y)continue;\r\n\t\t\t\tret[x].emplace_back(y,\
    \ e.cost);\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\tgroup.resize(cnt);\r\n\t\tfor (int i\
    \ = 0; i < g.size(); i++) {\r\n\t\t\tgroup[comp[i]].push_back(i);\r\n\t\t}\r\n\
    \r\n\t\treturn ret;\r\n\t}\r\n\r\n\tint operator[] (int k) const {\r\n\t\treturn\
    \ comp[k];\r\n\t}\r\n};\r\n"
  dependsOn:
  - graph/graph.cpp
  isVerificationFile: false
  path: graph/scc.cpp
  requiredBy: []
  timestamp: '2021-03-12 22:46:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/GRL_3_C.test.cpp
  - verify/graph/scc.test.cpp
documentation_of: graph/scc.cpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

## 説明
有向グラフ $g$ を強連結成分分解する。

## 操作
### StronglyConnectedComponents(g)
有向グラフ $g$ で前処理する。

### build()
$g$ を強連結成分分解したグラフを返す。
強連結成分の番号はトポロジカル順にふられ、groupには各強連結成分に属する頂点が格納される。

### operator[](k)
頂点 $k$ が属する強連結成分の番号を返す。