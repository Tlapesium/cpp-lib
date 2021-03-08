---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/bellman_ford.cpp
    title: Shortest Path (Bellman-Ford)
  - icon: ':x:'
    path: graph/dijkstra.cpp
    title: Shortest Path (Dijkstra)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/graph/GRL_1_A.test.cpp
    title: verify/graph/GRL_1_A.test.cpp
  - icon: ':x:'
    path: verify/graph/GRL_1_B.test.cpp
    title: verify/graph/GRL_1_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.cpp\"\n#include <vector>\r\n\r\nstruct Edge\
    \ {\r\n\tint to; long long cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\t\
    Edge(int to, long long cost) : to(to), cost(cost) {}\r\n};\r\nusing Graph = vector<vector<Edge>>;\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\nstruct Edge {\r\n\tint to; long\
    \ long cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int to, long long\
    \ cost) : to(to), cost(cost) {}\r\n};\r\nusing Graph = vector<vector<Edge>>;"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.cpp
  requiredBy:
  - graph/dijkstra.cpp
  - graph/bellman_ford.cpp
  timestamp: '2021-03-08 20:03:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/graph/GRL_1_B.test.cpp
  - verify/graph/GRL_1_A.test.cpp
documentation_of: graph/graph.cpp
layout: document
title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
