---
title: Li Chao Tree
documentation_of: //data-structure/li_chao_tree.cpp
---

## 説明
直線 $ax+b$ の追加クエリと、ある点 $x$ での最小値クエリを高速に処理できるデータ構造。

## 操作
### LiChaoTree()
Li Chao Tree を構築する。
$x_min$ には $x$ の最小値、$x_max$ には $x$ の最大値を指定する。
### add_line(T a, T b)
直線 $ax+b$ を追加する。
### add_segment(T l, T r, T a, T b)
区間 $[l,r)$ に線分 $ax+b$ を追加する。
### query(T x)
$x$ における最小値を取得する。
