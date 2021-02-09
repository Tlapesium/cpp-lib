---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/static_rmq.test.cpp
    title: verify/data-structure/static_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sparse_table.cpp\"\n#include <vector>\r\n\
    #include <functional>\r\n\r\ntemplate<class T, class Comp = std::less<T> >\r\n\
    struct SparseTable {\r\n\tstd::vector<std::vector<T>> st;\r\n\tconst int size;\r\
    \n\tconst Comp comp;\r\n\tSparseTable(const std::vector<T>& v, Comp c = Comp())\
    \ : size(v.size()), comp(c) {\r\n\t\tst.resize(size, std::vector<T>(32 - __builtin_clz(size)));\r\
    \n\t\tfor (int i = 0; i < size; i++) st[i][0] = v[i];\r\n\t\tfor (int i = 1; (1\
    \ << i) <= size; i++) {\r\n\t\t\tfor (int j = 0; j + (1 << i) <= size; j++) {\r\
    \n\t\t\t\tif (comp(st[j][i - 1], st[j + (1 << (i - 1))][i - 1])) {\r\n\t\t\t\t\
    \tst[j][i] = st[j][i - 1];\r\n\t\t\t\t}\r\n\t\t\t\telse {\r\n\t\t\t\t\tst[j][i]\
    \ = st[j + (1 << (i - 1))][i - 1];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\
    \tT get(int l, int r) {\r\n\t\tint k = 32 - __builtin_clz(r - l) - 1;\r\n\t\t\
    if (comp(st[l][k], st[r - (1 << k)][k])) {\r\n\t\t\treturn st[l][k];\r\n\t\t}\r\
    \n\t\telse {\r\n\t\t\treturn st[r - (1 << k)][k];\r\n\t\t}\r\n\t}\r\n};\r\n\r\n\
    template<class T, class Comp>\r\nSparseTable<T, Comp> makeSparseTable(const std::vector<T>&\
    \ v, Comp c) {\r\n\treturn SparseTable<T, Comp>(v, c);\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <functional>\r\n\r\ntemplate<class\
    \ T, class Comp = std::less<T> >\r\nstruct SparseTable {\r\n\tstd::vector<std::vector<T>>\
    \ st;\r\n\tconst int size;\r\n\tconst Comp comp;\r\n\tSparseTable(const std::vector<T>&\
    \ v, Comp c = Comp()) : size(v.size()), comp(c) {\r\n\t\tst.resize(size, std::vector<T>(32\
    \ - __builtin_clz(size)));\r\n\t\tfor (int i = 0; i < size; i++) st[i][0] = v[i];\r\
    \n\t\tfor (int i = 1; (1 << i) <= size; i++) {\r\n\t\t\tfor (int j = 0; j + (1\
    \ << i) <= size; j++) {\r\n\t\t\t\tif (comp(st[j][i - 1], st[j + (1 << (i - 1))][i\
    \ - 1])) {\r\n\t\t\t\t\tst[j][i] = st[j][i - 1];\r\n\t\t\t\t}\r\n\t\t\t\telse\
    \ {\r\n\t\t\t\t\tst[j][i] = st[j + (1 << (i - 1))][i - 1];\r\n\t\t\t\t}\r\n\t\t\
    \t}\r\n\t\t}\r\n\t}\r\n\tT get(int l, int r) {\r\n\t\tint k = 32 - __builtin_clz(r\
    \ - l) - 1;\r\n\t\tif (comp(st[l][k], st[r - (1 << k)][k])) {\r\n\t\t\treturn\
    \ st[l][k];\r\n\t\t}\r\n\t\telse {\r\n\t\t\treturn st[r - (1 << k)][k];\r\n\t\t\
    }\r\n\t}\r\n};\r\n\r\ntemplate<class T, class Comp>\r\nSparseTable<T, Comp> makeSparseTable(const\
    \ std::vector<T>& v, Comp c) {\r\n\treturn SparseTable<T, Comp>(v, c);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.cpp
  requiredBy: []
  timestamp: '2021-02-09 09:18:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/static_rmq.test.cpp
documentation_of: data-structure/sparse_table.cpp
layout: document
title: Sparse Table
---

## 説明
RMQ を高速に処理できるデータ構造。
比較関数を変更することで最大値クエリも処理できる。

## 操作
### SparseTable(std::vector<T>& v)
$v$ を元にSparse Tableを構築する。
### get(int l, int r)
区間 $[l,r)$ の最小値を取得する。
