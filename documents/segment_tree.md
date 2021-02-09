---
title: Segment Tree
documentation_of: //data-structure/segment_tree.cpp
---

## 説明
一点更新・区間取得が高速にできるデータ構造。

## 操作
### makeSegTree(int n, Operator F, Monoid IE)
要素数 $n$ 、$F$ の単位元 $IE$ で初期化されたセグメント木を構築する。$F$ は $2$ つの区間をマージする二項演算を指定する。
### makeSegTree(std::vector<Monoid>& vec, Operator F, Monoid IE)
$vec$ を元にセグメント木を構築する。
### get(int l, int r)
区間 $[l,r)$ に対して二項演算した結果を返す。
### set(int idx, Monoid x)
$idx$ 番目の要素を $x$ に更新する。
### search_r(DetermineFunc isOK, int l)
$[l,r]$ が $isOK$ を満たす最小の $r$ を返す。