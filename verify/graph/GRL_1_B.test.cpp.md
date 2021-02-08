---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.cpp
    title: Shortest Path (Bellman-Ford)
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"verify/graph/GRL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \r\n#line 2 \"graph/graph.cpp\"\n#include <vector>\r\n#include <utility>\r\n\r\
    \n/**\r\n * @title \u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \r\n */\r\n\r\nusing UnWeightedGraph = std::vector<std::vector<int>>;\r\nusing\
    \ WeightedGraph = std::vector<std::vector<std::pair<int, long long>>>;\n#line\
    \ 4 \"graph/bellman_ford.cpp\"\n#include <limits>\r\n#line 6 \"graph/bellman_ford.cpp\"\
    \n\r\n/**\r\n * @title Shortest Path (Bellman-Ford)\r\n */\r\n\r\nauto BellmanFord(int\
    \ s, WeightedGraph& g) {\r\n\tconstexpr auto inf = std::numeric_limits<long long>::max();\r\
    \n\tstd::vector d(g.size(), inf);;\r\n\td[s] = 0;\r\n\tfor (int i = 0; i < g.size();\
    \ i++) {\r\n\t\tfor (int j = 0; j < g.size(); j++) {\r\n\t\t\tfor (auto&& e :\
    \ g[j]) {\r\n\t\t\t\tif (d[j] != inf && d[e.first] > d[j] + e.second) {\r\n\t\t\
    \t\t\td[e.first] = d[j] + e.second;\r\n\t\t\t\t\tif (i == g.size() - 1)return\
    \ std::vector<long long>();\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn\
    \ d;\r\n}\r\n\r\n#line 4 \"verify/graph/GRL_1_B.test.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint V,\
    \ E, r;\r\n\tcin >> V >> E >> r;\r\n\tWeightedGraph g(V);\r\n\tfor (int i = 0;\
    \ i < E; i++) {\r\n\t\tint s, t, c;\r\n\t\tcin >> s >> t >> c;\r\n\t\tg[s].push_back({\
    \ t,c });\r\n\t}\r\n\tauto d = BellmanFord(r, g);\r\n\tif (d.empty())cout << \"\
    NEGATIVE CYCLE\" << endl;\r\n\telse {\r\n\t\tfor (int i = 0; i < d.size(); i++)\
    \ {\r\n\t\t\t(d[i] == numeric_limits<ll>::max() ? cout << \"INF\" << endl : cout\
    \ << d[i] << endl);\r\n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \r\n#include \"graph/graph.cpp\"\r\n#include \"graph/bellman_ford.cpp\"\r\n#include\
    \ <bits/stdc++.h>\r\nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint\
    \ main() {\r\n\tint V, E, r;\r\n\tcin >> V >> E >> r;\r\n\tWeightedGraph g(V);\r\
    \n\tfor (int i = 0; i < E; i++) {\r\n\t\tint s, t, c;\r\n\t\tcin >> s >> t >>\
    \ c;\r\n\t\tg[s].push_back({ t,c });\r\n\t}\r\n\tauto d = BellmanFord(r, g);\r\
    \n\tif (d.empty())cout << \"NEGATIVE CYCLE\" << endl;\r\n\telse {\r\n\t\tfor (int\
    \ i = 0; i < d.size(); i++) {\r\n\t\t\t(d[i] == numeric_limits<ll>::max() ? cout\
    \ << \"INF\" << endl : cout << d[i] << endl);\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - graph/graph.cpp
  - graph/bellman_ford.cpp
  isVerificationFile: true
  path: verify/graph/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 08:06:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/GRL_1_B.test.cpp
- /verify/verify/graph/GRL_1_B.test.cpp.html
title: verify/graph/GRL_1_B.test.cpp
---
