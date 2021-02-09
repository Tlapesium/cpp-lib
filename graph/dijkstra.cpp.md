---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_1_A.test.cpp
    title: verify/graph/GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.cpp\"\n#include <vector>\r\n#include <queue>\r\
    \n#include <utility>\r\n#include <limits>\r\n#line 4 \"graph/graph.cpp\"\n\r\n\
    using UnWeightedGraph = std::vector<std::vector<int>>;\r\nusing WeightedGraph\
    \ = std::vector<std::vector<std::pair<int, long long>>>;\n#line 7 \"graph/dijkstra.cpp\"\
    \n\r\nauto Dijkstra(int s, WeightedGraph& g) {\r\n\tconstexpr auto inf = std::numeric_limits<long\
    \ long>::max();\r\n\tusing P = std::pair<long long, int>;\r\n\tstd::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> q;\r\n\tstd::vector d(g.size(), inf);\r\n\t\
    d[s] = 0;\r\n\tq.push({ 0,s });\r\n\r\n\twhile (q.size()) {\r\n\t\tauto [cost,\
    \ pos] = q.top(); q.pop();\r\n\t\tif (d[pos] < cost)continue;\r\n\t\tfor (auto&&\
    \ e : g[pos]) {\r\n\t\t\tif (d[e.first] > d[pos] + e.second) {\r\n\t\t\t\td[e.first]\
    \ = d[pos] + e.second;\r\n\t\t\t\tq.push({ d[e.first] , e.first });\r\n\t\t\t\
    }\r\n\t\t}\r\n\t}\r\n\treturn d;\r\n}\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <queue>\r\n#include <utility>\r\
    \n#include <limits>\r\n#include \"graph/graph.cpp\"\r\n\r\nauto Dijkstra(int s,\
    \ WeightedGraph& g) {\r\n\tconstexpr auto inf = std::numeric_limits<long long>::max();\r\
    \n\tusing P = std::pair<long long, int>;\r\n\tstd::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> q;\r\n\tstd::vector d(g.size(), inf);\r\n\td[s] = 0;\r\n\t\
    q.push({ 0,s });\r\n\r\n\twhile (q.size()) {\r\n\t\tauto [cost, pos] = q.top();\
    \ q.pop();\r\n\t\tif (d[pos] < cost)continue;\r\n\t\tfor (auto&& e : g[pos]) {\r\
    \n\t\t\tif (d[e.first] > d[pos] + e.second) {\r\n\t\t\t\td[e.first] = d[pos] +\
    \ e.second;\r\n\t\t\t\tq.push({ d[e.first] , e.first });\r\n\t\t\t}\r\n\t\t}\r\
    \n\t}\r\n\treturn d;\r\n}"
  dependsOn:
  - graph/graph.cpp
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2021-02-09 09:18:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/GRL_1_A.test.cpp
documentation_of: graph/dijkstra.cpp
layout: document
title: Shortest Path (Dijkstra)
---

## 説明
重み付きグラフ $g$ 上で $s$ からの最短距離を全ての頂点に対し求める。
到達できないとき、型の最大値が代入される。