---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.cpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 (Kruskal)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/DSL_1_A.test.cpp
    title: verify/data-structure/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/DSL_1_B.test.cpp
    title: verify/data-structure/DSL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/graph/GRL_2_A.test.cpp
    title: verify/graph/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/union_find.cpp\"\n#include <vector>\r\n#include\
    \ <utility>\r\n\r\nstruct UnionFind {\r\n\tstd::vector<int> siz, par;\r\n\tstd::vector<long\
    \ long> wei;\r\n\tint f_s;\r\n\r\n\tUnionFind(int size) : f_s(size) {\r\n\t\t\
    siz.assign(size, 1);\r\n\t\twei.assign(size, 0);\r\n\t\tpar.assign(size, 0);\r\
    \n\t\tfor (int i = 0; i < size; i++)par[i] = i;\r\n\t}\r\n\tbool merge(int x,\
    \ int y, long long w = 0) {\r\n\t\tw += weight(x); w -= weight(y);\r\n\t\tx =\
    \ root(x); y = root(y);\r\n\t\tif (x == y)return false;\r\n\t\tif (siz[x] < siz[y])std::swap(x,\
    \ y), w = -w;\r\n\t\tsiz[x] += siz[y];\r\n\t\tpar[y] = x;\r\n\t\twei[y] = w;\r\
    \n\t\tf_s--;\r\n\t\treturn true;\r\n\t}\r\n\tlong long weight(int x) {\r\n\t\t\
    root(x);\r\n\t\treturn wei[x];\r\n\t}\r\n\tint root(int k) {\r\n\t\tif (par[k]\
    \ == k)return k;\r\n\t\tint tmp = root(par[k]);\r\n\t\twei[k] += wei[par[k]];\r\
    \n\t\treturn par[k] = tmp;\r\n\t}\r\n\tbool issame(int x, int y) {\r\n\t\treturn\
    \ root(x) == root(y);\r\n\t}\r\n\tlong long diff(int x, int y) {\r\n\t\treturn\
    \ weight(y) - weight(x);\r\n\t}\r\n\tint size(int x) {\r\n\t\treturn siz[x];\r\
    \n\t}\r\n\tint forest_size() {\r\n\t\treturn f_s;\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <utility>\r\n\r\nstruct UnionFind\
    \ {\r\n\tstd::vector<int> siz, par;\r\n\tstd::vector<long long> wei;\r\n\tint\
    \ f_s;\r\n\r\n\tUnionFind(int size) : f_s(size) {\r\n\t\tsiz.assign(size, 1);\r\
    \n\t\twei.assign(size, 0);\r\n\t\tpar.assign(size, 0);\r\n\t\tfor (int i = 0;\
    \ i < size; i++)par[i] = i;\r\n\t}\r\n\tbool merge(int x, int y, long long w =\
    \ 0) {\r\n\t\tw += weight(x); w -= weight(y);\r\n\t\tx = root(x); y = root(y);\r\
    \n\t\tif (x == y)return false;\r\n\t\tif (siz[x] < siz[y])std::swap(x, y), w =\
    \ -w;\r\n\t\tsiz[x] += siz[y];\r\n\t\tpar[y] = x;\r\n\t\twei[y] = w;\r\n\t\tf_s--;\r\
    \n\t\treturn true;\r\n\t}\r\n\tlong long weight(int x) {\r\n\t\troot(x);\r\n\t\
    \treturn wei[x];\r\n\t}\r\n\tint root(int k) {\r\n\t\tif (par[k] == k)return k;\r\
    \n\t\tint tmp = root(par[k]);\r\n\t\twei[k] += wei[par[k]];\r\n\t\treturn par[k]\
    \ = tmp;\r\n\t}\r\n\tbool issame(int x, int y) {\r\n\t\treturn root(x) == root(y);\r\
    \n\t}\r\n\tlong long diff(int x, int y) {\r\n\t\treturn weight(y) - weight(x);\r\
    \n\t}\r\n\tint size(int x) {\r\n\t\treturn siz[x];\r\n\t}\r\n\tint forest_size()\
    \ {\r\n\t\treturn f_s;\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union_find.cpp
  requiredBy:
  - graph/kruskal.cpp
  timestamp: '2021-03-10 02:08:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/DSL_1_B.test.cpp
  - verify/data-structure/DSL_1_A.test.cpp
  - verify/graph/GRL_2_A.test.cpp
documentation_of: data-structure/union_find.cpp
layout: document
title: Union Find
---

## 説明
集合に関する操作を高速で行えるデータ構造。

## 操作
### UnionFind(N)
$N$ 要素で初期化された Union Find 木 を構築する。
### merge(x,y)
$x$ を含む集合と $y$ を含む集合をマージする。
### merge(x,y,w)
$\mathrm{weight}(y) = \mathrm{weight}(x) + w$ を満たすように、$x$ を含む集合と $y$ を含む集合をマージする。
### issame(x,y)
$x$ と $y$ が同じ集合に属するかを判定する。
### diff(x,y)
$\mathrm{weight}(y) - \mathrm{weight}(x)$ を求める。

$x$ と $y$ が同じ集合に属さないとき、意味のない値を返すので注意。
### size(x)
$x$ を含む集合の要素数を取得する。
### forest_size()
集合の個数を取得する。