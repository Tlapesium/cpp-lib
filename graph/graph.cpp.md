---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_1_A.test.cpp
    title: verify/graph/GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"graph/graph.cpp\"\n#include <vector>\r\n#include <utility>\r\
    \n\r\n/**\r\n * @title \u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \r\n */\r\n\r\nusing UnWeightedGraph = std::vector<std::vector<int>>;\r\nusing\
    \ WeightedGraph = std::vector<std::vector<std::pair<int, long long>>>;\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <utility>\r\n\r\n/**\r\n *\
    \ @title \u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\r\n */\r\
    \n\r\nusing UnWeightedGraph = std::vector<std::vector<int>>;\r\nusing WeightedGraph\
    \ = std::vector<std::vector<std::pair<int, long long>>>;"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.cpp
  requiredBy:
  - graph/dijkstra.cpp
  timestamp: '2021-02-02 05:00:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/GRL_1_A.test.cpp
documentation_of: graph/graph.cpp
layout: document
redirect_from:
- /library/graph/graph.cpp
- /library/graph/graph.cpp.html
title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
