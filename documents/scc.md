---
title: 強連結成分分解
documentation_of: //graph/scc.cpp
---

## 説明
有向グラフ $g$ を強連結成分分解する。

## 操作
- :heavy_check_mark: **StronglyConnectedComponents(g)** : 有向グラフ $g$ で前処理する。
- :heavy_check_mark: **build()** : $g$ を強連結成分分解したグラフを返す。強連結成分の番号はトポロジカル順にふられ、groupには各強連結成分に属する頂点が格納される。
- :heavy_check_mark: **operator\[\]\(k\)** : 頂点 $k$ が属する強連結成分の番号を返す。