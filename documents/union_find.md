---
title: Union Find
documentation_of: //data-structure/union_find.cpp
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