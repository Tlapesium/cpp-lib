---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dijkstra.cpp
    title: Shortest Path (Dijkstra)
  - icon: ':x:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"verify/graph/GRL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \r\n#line 2 \"graph/graph.cpp\"\n#include <vector>\r\n\r\nstruct Edge {\r\n\t\
    int to; long long cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int\
    \ to, long long cost) : to(to), cost(cost) {}\r\n};\r\nusing Graph = vector<vector<Edge>>;\n\
    #line 3 \"graph/dijkstra.cpp\"\n#include <queue>\r\n#include <utility>\r\n#include\
    \ <limits>\r\n#line 7 \"graph/dijkstra.cpp\"\n\r\nauto Dijkstra(int s, Graph&\
    \ g) {\r\n\tconstexpr auto inf = std::numeric_limits<long long>::max();\r\n\t\
    using P = std::pair<long long, int>;\r\n\tstd::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> q;\r\n\tstd::vector d(g.size(), inf);\r\n\td[s] = 0;\r\n\t\
    q.push({ 0,s });\r\n\r\n\twhile (q.size()) {\r\n\t\tauto [cost, pos] = q.top();\
    \ q.pop();\r\n\t\tif (d[pos] < cost)continue;\r\n\t\tfor (auto&& e : g[pos]) {\r\
    \n\t\t\tif (d[e.to] > d[pos] + e.cost) {\r\n\t\t\t\td[e.to] = d[pos] + e.cost;\r\
    \n\t\t\t\tq.push({ d[e.to] , e.to });\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn d;\r\
    \n}\r\n#line 4 \"verify/graph/GRL_1_A.test.cpp\"\n#include <bits/stdc++.h>\r\n\
    using namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint V,\
    \ E, r;\r\n\tcin >> V >> E >> r;\r\n\tGraph g(V);\r\n\tfor (int i = 0; i < E;\
    \ i++) {\r\n\t\tint s, t, c;\r\n\t\tcin >> s >> t >> c;\r\n\t\tg[s].emplace_back(t,\
    \ c);\r\n\t}\r\n\tauto d = Dijkstra(r, g);\r\n\tfor (int i = 0; i < d.size();\
    \ i++) {\r\n\t\t(d[i] == numeric_limits<ll>::max() ? cout << \"INF\" << endl :\
    \ cout << d[i] << endl);\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \r\n#include \"graph/graph.cpp\"\r\n#include \"graph/dijkstra.cpp\"\r\n#include\
    \ <bits/stdc++.h>\r\nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint\
    \ main() {\r\n\tint V, E, r;\r\n\tcin >> V >> E >> r;\r\n\tGraph g(V);\r\n\tfor\
    \ (int i = 0; i < E; i++) {\r\n\t\tint s, t, c;\r\n\t\tcin >> s >> t >> c;\r\n\
    \t\tg[s].emplace_back(t, c);\r\n\t}\r\n\tauto d = Dijkstra(r, g);\r\n\tfor (int\
    \ i = 0; i < d.size(); i++) {\r\n\t\t(d[i] == numeric_limits<ll>::max() ? cout\
    \ << \"INF\" << endl : cout << d[i] << endl);\r\n\t}\r\n}"
  dependsOn:
  - graph/graph.cpp
  - graph/dijkstra.cpp
  isVerificationFile: true
  path: verify/graph/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-03-08 20:03:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/graph/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/GRL_1_A.test.cpp
- /verify/verify/graph/GRL_1_A.test.cpp.html
title: verify/graph/GRL_1_A.test.cpp
---
