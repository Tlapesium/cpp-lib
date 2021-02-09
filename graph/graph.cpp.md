---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.cpp
    title: Shortest Path (Bellman-Ford)
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: Shortest Path (Dijkstra)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_1_A.test.cpp
    title: verify/graph/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_1_B.test.cpp
    title: verify/graph/GRL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.cpp\"\n#include <vector>\r\n#include <utility>\r\
    \n\r\nusing UnWeightedGraph = std::vector<std::vector<int>>;\r\nusing WeightedGraph\
    \ = std::vector<std::vector<std::pair<int, long long>>>;\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <utility>\r\n\r\nusing UnWeightedGraph\
    \ = std::vector<std::vector<int>>;\r\nusing WeightedGraph = std::vector<std::vector<std::pair<int,\
    \ long long>>>;"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.cpp
  requiredBy:
  - graph/bellman_ford.cpp
  - graph/dijkstra.cpp
  timestamp: '2021-02-09 09:18:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/GRL_1_B.test.cpp
  - verify/graph/GRL_1_A.test.cpp
documentation_of: graph/graph.cpp
layout: document
title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
