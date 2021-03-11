---
title: Sparse Table
documentation_of: //data-structure/sparse_table.cpp
---

## 説明
RMQ を高速に処理できるデータ構造。
比較関数を変更することで最大値クエリも処理できる。

## 操作
### SparseTable(v)
$v$ を元にSparse Tableを構築する。
### get(l, r)
区間 $[l,r)$ の最小値を取得する。
