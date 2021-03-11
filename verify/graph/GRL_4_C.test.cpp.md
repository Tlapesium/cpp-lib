---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.cpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: "\u30B0\u30E9\u30D5\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/lca.cpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "#line 1 \"verify/graph/GRL_4_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\
    \r\n#include <bits/stdc++.h>\r\n#line 2 \"graph/graph.cpp\"\n\r\nstruct Edge {\r\
    \n\tint to; long long cost;\r\n\tEdge(int to) : to(to), cost(1) {};\r\n\tEdge(int\
    \ to, long long cost) : to(to), cost(cost) {}\r\n};\r\nusing Graph = std::vector<std::vector<Edge>>;\n\
    #line 2 \"data-structure/sparse_table.cpp\"\n\r\ntemplate<class T, class Comp\
    \ = std::less<T> >\r\nstruct SparseTable {\r\n\tstd::vector<std::vector<T>> st;\r\
    \n\tint size;\r\n\tSparseTable() = default;\r\n\tSparseTable(const std::vector<T>&\
    \ v) : size(v.size()) {\r\n\t\tst.resize(size, std::vector<T>(32 - __builtin_clz(size)));\r\
    \n\t\tfor (int i = 0; i < size; i++) st[i][0] = v[i];\r\n\t\tfor (int i = 1; (1\
    \ << i) <= size; i++) {\r\n\t\t\tfor (int j = 0; j + (1 << i) <= size; j++) {\r\
    \n\t\t\t\tst[j][i] = Comp()(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]) ? st[j][i\
    \ - 1] : st[j + (1 << (i - 1))][i - 1];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tT get(int\
    \ l, int r) {\r\n\t\tint k = 32 - __builtin_clz(r - l) - 1;\r\n\t\treturn Comp()(st[l][k],\
    \ st[r - (1 << k)][k]) ? st[l][k] : st[r - (1 << k)][k];\r\n\t}\r\n};\n#line 4\
    \ \"graph/lca.cpp\"\n\r\nstruct LowestCommonAncester {\r\n\tSparseTable<std::pair<int,\
    \ int>> ST;\r\n\tstd::vector<int> in;\r\n\tLowestCommonAncester(const Graph& g)\
    \ {\r\n\t\tstd::vector<std::pair<int, int>> tmp;\r\n\t\tin.resize(g.size());\r\
    \n\t\tauto dfs = [&](auto&& dfs, int pos, int par, int depth) -> void {\r\n\t\t\
    \tif (par == -1) tmp.push_back({ 0,pos });\r\n\t\t\tin[pos] = tmp.size();\r\n\t\
    \t\tfor (auto&& e : g[pos]) {\r\n\t\t\t\tif (e.to == par)continue;\r\n\t\t\t\t\
    tmp.push_back({ depth + 1, e.to });\r\n\t\t\t\tdfs(dfs, e.to, pos, depth + 1);\r\
    \n\t\t\t\ttmp.push_back({ depth,pos });\r\n\t\t\t}\r\n\t\t};\r\n\t\tdfs(dfs, 0,\
    \ -1, 0);\r\n\t\tST = SparseTable<std::pair<int, int>>(tmp);\r\n\t}\r\n\r\n\t\
    int query(int u, int v) {\r\n\t\treturn ST.get(std::min(in[u], in[v]) - 1, std::max(in[u],\
    \ in[v])).second;\r\n\t}\r\n};\n#line 5 \"verify/graph/GRL_4_C.test.cpp\"\nusing\
    \ namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint N;\r\n\t\
    cin >> N;\r\n\tGraph g(N);\r\n\tfor (int i = 0; i < N; i++) {\r\n\t\tint k;\r\n\
    \t\tcin >> k;\r\n\t\tfor (int j = 0; j < k; j++) {\r\n\t\t\tint t;\r\n\t\t\tcin\
    \ >> t;\r\n\t\t\tg[i].emplace_back(t);\r\n\t\t\tg[t].emplace_back(i);\r\n\t\t\
    }\r\n\t}\r\n\tLowestCommonAncester LCA(g);\r\n\tint Q;\r\n\tcin >> Q;\r\n\tfor\
    \ (int i = 0; i < Q; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\tcout\
    \ << LCA.query(u, v) << endl;\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\r\n\
    #include <bits/stdc++.h>\r\n#include \"graph/graph.cpp\"\r\n#include \"graph/lca.cpp\"\
    \r\nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint\
    \ N;\r\n\tcin >> N;\r\n\tGraph g(N);\r\n\tfor (int i = 0; i < N; i++) {\r\n\t\t\
    int k;\r\n\t\tcin >> k;\r\n\t\tfor (int j = 0; j < k; j++) {\r\n\t\t\tint t;\r\
    \n\t\t\tcin >> t;\r\n\t\t\tg[i].emplace_back(t);\r\n\t\t\tg[t].emplace_back(i);\r\
    \n\t\t}\r\n\t}\r\n\tLowestCommonAncester LCA(g);\r\n\tint Q;\r\n\tcin >> Q;\r\n\
    \tfor (int i = 0; i < Q; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\t\
    cout << LCA.query(u, v) << endl;\r\n\t}\r\n}"
  dependsOn:
  - graph/graph.cpp
  - graph/lca.cpp
  - data-structure/sparse_table.cpp
  isVerificationFile: true
  path: verify/graph/GRL_4_C.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 03:00:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/GRL_4_C.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/GRL_4_C.test.cpp
- /verify/verify/graph/GRL_4_C.test.cpp.html
title: verify/graph/GRL_4_C.test.cpp
---
