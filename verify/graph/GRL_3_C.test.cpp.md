---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/scc.cpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
  bundledCode: "#line 1 \"verify/graph/GRL_3_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\
    \r\n#include <bits/stdc++.h>\r\n#line 2 \"graph/graph.cpp\"\n\r\nstruct Edge {\r\
    \n\tint to; long long cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int\
    \ to, long long cost) : to(to), cost(cost) {}\r\n};\r\nusing Graph = std::vector<std::vector<Edge>>;\n\
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
    \ comp[k];\r\n\t}\r\n};\r\n#line 5 \"verify/graph/GRL_3_C.test.cpp\"\nusing namespace\
    \ std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint V, E;\r\n\tcin >>\
    \ V >> E;\r\n\tGraph g(V);\r\n\tfor (int i = 0; i < E; i++) {\r\n\t\tint s, t;\r\
    \n\t\tcin >> s >> t;\r\n\t\tg[s].emplace_back(t);\r\n\t}\r\n\tStronglyConnectedComponents\
    \ SCC(g);\r\n\tSCC.build();\r\n\tint Q;\r\n\tcin >> Q;\r\n\tfor (int i = 0; i\
    \ < Q; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\tcout << (SCC[u] ==\
    \ SCC[v]) << endl;\r\n\t}\r\n\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\r\n\
    #include <bits/stdc++.h>\r\n#include \"graph/graph.cpp\"\r\n#include \"graph/scc.cpp\"\
    \r\nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint\
    \ V, E;\r\n\tcin >> V >> E;\r\n\tGraph g(V);\r\n\tfor (int i = 0; i < E; i++)\
    \ {\r\n\t\tint s, t;\r\n\t\tcin >> s >> t;\r\n\t\tg[s].emplace_back(t);\r\n\t\
    }\r\n\tStronglyConnectedComponents SCC(g);\r\n\tSCC.build();\r\n\tint Q;\r\n\t\
    cin >> Q;\r\n\tfor (int i = 0; i < Q; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u\
    \ >> v;\r\n\t\tcout << (SCC[u] == SCC[v]) << endl;\r\n\t}\r\n\r\n}"
  dependsOn:
  - graph/graph.cpp
  - graph/scc.cpp
  isVerificationFile: true
  path: verify/graph/GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 22:46:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/GRL_3_C.test.cpp
- /verify/verify/graph/GRL_3_C.test.cpp.html
title: verify/graph/GRL_3_C.test.cpp
---
