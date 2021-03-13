---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.cpp
    title: "\u6728\u306E\u76F4\u5F84"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"verify/graph/tree_diameter.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tree_diameter\"\r\n#include <bits/stdc++.h>\r\n\
    #line 2 \"graph/graph.cpp\"\n\r\nstruct Edge {\r\n\tint to; long long cost;\r\n\
    \tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int to, long long cost) : to(to),\
    \ cost(cost) {}\r\n};\r\nusing Graph = std::vector<std::vector<Edge>>;\n#line\
    \ 3 \"graph/tree_diameter.cpp\"\n\r\nauto tree_diameter(const Graph& g) {\r\n\t\
    std::vector<long long> dist(g.size(), 0);\r\n\tstd::vector<int> v;\r\n\tauto dfs\
    \ = [&](auto&& dfs, int pos, int par, long long d, int dest) -> bool {\r\n\t\t\
    bool flag = pos == dest;\r\n\t\tfor (auto&& e : g[pos]) {\r\n\t\t\tif (e.to ==\
    \ par)continue;\r\n\t\t\tflag |= dfs(dfs, e.to, pos, d + e.cost, dest);\r\n\t\t\
    \tdist[e.to] = d + e.cost;\r\n\t\t}\r\n\t\tif (flag)v.push_back(pos);\r\n\t\t\
    return flag;\r\n\t};\r\n\tdfs(dfs, 0, -1, 0, -1);\r\n\tint p = std::max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\r\n\tdist[p] = 0;\r\n\tdfs(dfs, p, -1, 0, -1);\r\
    \n\tint q = std::max_element(dist.begin(), dist.end()) - dist.begin();\r\n\tdfs(dfs,\
    \ p, -1, 0, q);\r\n\treturn std::make_pair(*std::max_element(dist.begin(), dist.end()),\
    \ v);\r\n}\n#line 5 \"verify/graph/tree_diameter.test.cpp\"\nusing namespace std;\r\
    \ntypedef long long ll;\r\n\r\nint main() {\r\n\tint N;\r\n\tcin >> N;\r\n\tGraph\
    \ g(N);\r\n\tfor (int i = 0; i < N - 1; i++) {\r\n\t\tint a, b, c;\r\n\t\tcin\
    \ >> a >> b >> c;\r\n\t\tg[a].emplace_back(b, c);\r\n\t\tg[b].emplace_back(a,\
    \ c);\r\n\t}\r\n\tauto ret = tree_diameter(g);\r\n\tcout << ret.first << \" \"\
    \ << ret.second.size() << endl;\r\n\tfor (int i = 0; i < ret.second.size(); i++)\
    \ {\r\n\t\tcout << ret.second[i] << (i == ret.second.size() - 1 ? \"\\n\" : \"\
    \ \");\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\r\n#include\
    \ <bits/stdc++.h>\r\n#include \"graph/graph.cpp\"\r\n#include \"graph/tree_diameter.cpp\"\
    \r\nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint\
    \ N;\r\n\tcin >> N;\r\n\tGraph g(N);\r\n\tfor (int i = 0; i < N - 1; i++) {\r\n\
    \t\tint a, b, c;\r\n\t\tcin >> a >> b >> c;\r\n\t\tg[a].emplace_back(b, c);\r\n\
    \t\tg[b].emplace_back(a, c);\r\n\t}\r\n\tauto ret = tree_diameter(g);\r\n\tcout\
    \ << ret.first << \" \" << ret.second.size() << endl;\r\n\tfor (int i = 0; i <\
    \ ret.second.size(); i++) {\r\n\t\tcout << ret.second[i] << (i == ret.second.size()\
    \ - 1 ? \"\\n\" : \" \");\r\n\t}\r\n}"
  dependsOn:
  - graph/graph.cpp
  - graph/tree_diameter.cpp
  isVerificationFile: true
  path: verify/graph/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2021-03-14 00:25:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/tree_diameter.test.cpp
- /verify/verify/graph/tree_diameter.test.cpp.html
title: verify/graph/tree_diameter.test.cpp
---
