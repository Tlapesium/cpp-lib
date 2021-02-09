---
title: Shortest Path (Bellman-Ford)
documentation_of: //graph/bellman_ford.cpp
---

## 説明
重み付きグラフ $g$ 上で $s$ からの最短距離を全ての頂点に対し求める。
到達できないとき、型の最大値が代入される。また、負閉路が存在するときは空のvectorを返す。