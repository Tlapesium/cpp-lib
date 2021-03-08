---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/topological_sort.cpp
    title: Topological Sort
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
  bundledCode: "#line 1 \"verify/graph/GRL_4_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \r\n#line 2 \"graph/graph.cpp\"\n#include <vector>\r\n\r\nstruct Edge {\r\n\t\
    int to; long long cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int\
    \ to, long long cost) : to(to), cost(cost) {}\r\n};\r\nusing Graph = std::vector<std::vector<Edge>>;\n\
    #line 3 \"graph/topological_sort.cpp\"\n#include <algorithm>\r\n#line 5 \"graph/topological_sort.cpp\"\
    \n\r\nauto topological_sort(const Graph& g) {\r\n\tbool cycle_flag = false;\r\n\
    \tstd::vector<int> ret, used(g.size(), 0);\r\n\r\n\tauto dfs = [&](auto&& dfs,\
    \ int pos) -> void {\r\n\t\tif (used[pos] == 1) cycle_flag = true;\r\n\t\telse\
    \ if (used[pos] == 0) {\r\n\t\t\tused[pos] = 1;\r\n\t\t\tfor (auto&& e : g[pos])\
    \ {\r\n\t\t\t\tdfs(dfs, e.to);\r\n\t\t\t}\r\n\t\t\tused[pos] = 2;\r\n\t\t\tret.push_back(pos);\r\
    \n\t\t}\r\n\t};\r\n\r\n\tfor (int i = 0; i < g.size(); i++) {\r\n\t\tif (!used[i])dfs(dfs,\
    \ i);\r\n\t\tif (cycle_flag)return std::vector<int>();\r\n\t}\r\n\tstd::reverse(ret.begin(),\
    \ ret.end());\r\n\treturn ret;\r\n}\n#line 4 \"verify/graph/GRL_4_B.test.cpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\ntypedef long long ll;\r\n\
    \r\nint main() {\r\n\tint V, E;\r\n\tcin >> V >> E;\r\n\tGraph g(V);\r\n\tfor\
    \ (int i = 0; i < E; i++) {\r\n\t\tint s, t;\r\n\t\tcin >> s >> t;\r\n\t\tg[s].emplace_back(t);\r\
    \n\t}\r\n\tauto sorted = topological_sort(g);\r\n\tfor (int i = 0; i < sorted.size();\
    \ i++) {\r\n\t\tcout << sorted[i] << endl;\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \r\n#include \"graph/graph.cpp\"\r\n#include \"graph/topological_sort.cpp\"\r\n\
    #include <bits/stdc++.h>\r\nusing namespace std;\r\ntypedef long long ll;\r\n\r\
    \nint main() {\r\n\tint V, E;\r\n\tcin >> V >> E;\r\n\tGraph g(V);\r\n\tfor (int\
    \ i = 0; i < E; i++) {\r\n\t\tint s, t;\r\n\t\tcin >> s >> t;\r\n\t\tg[s].emplace_back(t);\r\
    \n\t}\r\n\tauto sorted = topological_sort(g);\r\n\tfor (int i = 0; i < sorted.size();\
    \ i++) {\r\n\t\tcout << sorted[i] << endl;\r\n\t}\r\n}"
  dependsOn:
  - graph/graph.cpp
  - graph/topological_sort.cpp
  isVerificationFile: true
  path: verify/graph/GRL_4_B.test.cpp
  requiredBy: []
  timestamp: '2021-03-08 23:41:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/GRL_4_B.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/GRL_4_B.test.cpp
- /verify/verify/graph/GRL_4_B.test.cpp.html
title: verify/graph/GRL_4_B.test.cpp
---
