---
title: Lazy Segment Tree
documentation_of: //data-structure/lazy_segment_tree.cpp
---

## 説明
区間更新・区間取得が高速にできるデータ構造。

## 操作
### makeLazySegTree(n, F, G, H, IE1, IE2)
要素数 $n$ 、$F$ の単位元 $IE1$ で初期化された遅延セグメント木を構築する。

$F$ は $2$ つの区間の要素をマージする二項演算、$G$ は要素に対し作用素を適用する二項演算、$H$ は作用素同士をマージする二項演算(第一引数が後に追加する作用素)を指定する。

$IE2$ は作用素の単位元である。
### makeLazySegTree(vec, F, G, H, IE1, IE2)
$vec$ を元に遅延セグメント木を構築する。
### get(l, r)
区間 $[l,r)$ に対して二項演算した結果を返す。
### set(l, r, x)
区間 $[l,r)$ に対して $x$ を作用させる。
### search_r(isOK, l)
$[l,r]$ が $isOK$ を満たす最小の $r$ を返す。