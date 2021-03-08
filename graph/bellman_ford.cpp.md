---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/graph/GRL_1_B.test.cpp
    title: verify/graph/GRL_1_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bellman_ford.cpp\"\n#include <vector>\r\n#include\
    \ <utility>\r\n#include <limits>\r\n#line 3 \"graph/graph.cpp\"\n\r\nstruct Edge\
    \ {\r\n\tint to; long long cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\t\
    Edge(int to, long long cost) : to(to), cost(cost) {}\r\n};\r\nusing Graph = vector<vector<Edge>>;\n\
    #line 6 \"graph/bellman_ford.cpp\"\n\r\nauto BellmanFord(int s, Graph& g) {\r\n\
    \tconstexpr auto inf = std::numeric_limits<long long>::max();\r\n\tstd::vector\
    \ d(g.size(), inf);;\r\n\td[s] = 0;\r\n\tfor (int i = 0; i < g.size(); i++) {\r\
    \n\t\tfor (int j = 0; j < g.size(); j++) {\r\n\t\t\tfor (auto&& e : g[j]) {\r\n\
    \t\t\t\tif (d[j] != inf && d[e.to] > d[j] + e.cost) {\r\n\t\t\t\t\td[e.to] = d[j]\
    \ + e.cost;\r\n\t\t\t\t\tif (i == g.size() - 1)return std::vector<long long>();\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn d;\r\n}\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <utility>\r\n#include <limits>\r\
    \n#include \"graph/graph.cpp\"\r\n\r\nauto BellmanFord(int s, Graph& g) {\r\n\t\
    constexpr auto inf = std::numeric_limits<long long>::max();\r\n\tstd::vector d(g.size(),\
    \ inf);;\r\n\td[s] = 0;\r\n\tfor (int i = 0; i < g.size(); i++) {\r\n\t\tfor (int\
    \ j = 0; j < g.size(); j++) {\r\n\t\t\tfor (auto&& e : g[j]) {\r\n\t\t\t\tif (d[j]\
    \ != inf && d[e.to] > d[j] + e.cost) {\r\n\t\t\t\t\td[e.to] = d[j] + e.cost;\r\
    \n\t\t\t\t\tif (i == g.size() - 1)return std::vector<long long>();\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn d;\r\n}"
  dependsOn:
  - graph/graph.cpp
  isVerificationFile: false
  path: graph/bellman_ford.cpp
  requiredBy: []
  timestamp: '2021-03-08 20:03:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/graph/GRL_1_B.test.cpp
documentation_of: graph/bellman_ford.cpp
layout: document
title: Shortest Path (Bellman-Ford)
---

## 説明
重み付きグラフ $g$ 上で $s$ からの最短距離を全ての頂点に対し求める。

到達できないとき、型の最大値が代入される。また、負閉路が存在するときは空のvectorを返す。