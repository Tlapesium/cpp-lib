---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/lca.cpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/static_rmq.test.cpp
    title: verify/data-structure/static_rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_5_C.test.cpp
    title: verify/graph/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/lca.test.cpp
    title: verify/graph/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sparse_table.cpp\"\n\r\ntemplate<class T,\
    \ class Comp = std::less<T> >\r\nstruct SparseTable {\r\n\tstd::vector<std::vector<T>>\
    \ st;\r\n\tint size;\r\n\tSparseTable() = default;\r\n\tSparseTable(const std::vector<T>&\
    \ v) : size(v.size()) {\r\n\t\tst.resize(size, std::vector<T>(32 - __builtin_clz(size)));\r\
    \n\t\tfor (int i = 0; i < size; i++) st[i][0] = v[i];\r\n\t\tfor (int i = 1; (1\
    \ << i) <= size; i++) {\r\n\t\t\tfor (int j = 0; j + (1 << i) <= size; j++) {\r\
    \n\t\t\t\tst[j][i] = Comp()(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]) ? st[j][i\
    \ - 1] : st[j + (1 << (i - 1))][i - 1];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tT get(int\
    \ l, int r) {\r\n\t\tint k = 32 - __builtin_clz(r - l) - 1;\r\n\t\treturn Comp()(st[l][k],\
    \ st[r - (1 << k)][k]) ? st[l][k] : st[r - (1 << k)][k];\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate<class T, class Comp = std::less<T> >\r\nstruct\
    \ SparseTable {\r\n\tstd::vector<std::vector<T>> st;\r\n\tint size;\r\n\tSparseTable()\
    \ = default;\r\n\tSparseTable(const std::vector<T>& v) : size(v.size()) {\r\n\t\
    \tst.resize(size, std::vector<T>(32 - __builtin_clz(size)));\r\n\t\tfor (int i\
    \ = 0; i < size; i++) st[i][0] = v[i];\r\n\t\tfor (int i = 1; (1 << i) <= size;\
    \ i++) {\r\n\t\t\tfor (int j = 0; j + (1 << i) <= size; j++) {\r\n\t\t\t\tst[j][i]\
    \ = Comp()(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]) ? st[j][i - 1] : st[j\
    \ + (1 << (i - 1))][i - 1];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tT get(int l, int r)\
    \ {\r\n\t\tint k = 32 - __builtin_clz(r - l) - 1;\r\n\t\treturn Comp()(st[l][k],\
    \ st[r - (1 << k)][k]) ? st[l][k] : st[r - (1 << k)][k];\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.cpp
  requiredBy:
  - graph/lca.cpp
  timestamp: '2021-03-12 03:00:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/static_rmq.test.cpp
  - verify/graph/GRL_5_C.test.cpp
  - verify/graph/lca.test.cpp
documentation_of: data-structure/sparse_table.cpp
layout: document
title: Sparse Table
---

## 説明
RMQ を高速に処理できるデータ構造。
比較関数を変更することで最大値クエリも処理できる。

## 操作
- :heavy_check_mark: **SparseTable(v)** : $v$ を元にSparse Tableを構築する。
- :heavy_check_mark: **get(l, r)** : 区間 $[l,r)$ の最小値を取得する。
