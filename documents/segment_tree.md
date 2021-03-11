---
title: Segment Tree
documentation_of: //data-structure/segment_tree.cpp
---

## 説明
一点更新・区間取得が高速にできるデータ構造。

## 操作
### makeSegTree(n, F, IE)
要素数 $n$ 、$F$ の単位元 $IE$ で初期化されたセグメント木を構築する。$F$ は $2$ つの区間をマージする二項演算を指定する。
### makeSegTree(vec, F, IE)
$vec$ を元にセグメント木を構築する。
### get(l, r)
区間 $[l,r)$ に対して二項演算した結果を返す。
### set(idx, x)
$idx$ 番目の要素を $x$ に更新する。
### search_r(isOK, l)
$[l,r]$ が $isOK$ を満たす最小の $r$ を返す。