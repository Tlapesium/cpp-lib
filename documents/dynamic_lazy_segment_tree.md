---
title: Dynamic Lazy Segment Tree
documentation_of: //data-structure/dynamic_lazy_segment_tree.cpp
---

## 説明
必要な場所だけ作るようにした Lazy Segment Tree。

## 操作
- :heavy_check_mark: **makeDynamicLazySegTree(n, F, G, H, IE1, IE2)** : 要素数 $n$ 、$F$ の単位元 $IE1$ で初期化された遅延セグメント木を構築する。

$F$ は $2$ つの区間の要素をマージする二項演算、$G$ は要素に対し作用素を適用する二項演算、$H$ は作用素同士をマージする二項演算(第一引数が後に追加する作用素)を指定する。

$G$ の第三引数には区間の幅が代入される。

$IE2$ は作用素の単位元である。

- :heavy_check_mark: **get(l, r)** : 区間 $[l,r)$ に対して二項演算した結果を返す。
- :heavy_check_mark: **set(l, r, x)** : 区間 $[l,r)$ に対して $x$ を作用させる。
- :question: **max_right(isOK, l)** : $[l,r)$ が $isOK$ を満たす最大の $r$ を返す。