---
title: 座標圧縮
documentation_of: //utility/compress.cpp
---

## 説明
座標の大小関係を維持しつつ、$N$ 個の座標 $(x_0, x_1, \dots, x_N)$ と整数 $(0, 1, \dots, N-1)$ を対応させる。

## 操作
- :heavy_check_mark: **add(x)** : 整数 $x$ を追加する。
- :heavy_check_mark: **build()** : 構築する。
- :heavy_check_mark: **operator\(\)\[x\]** : 座標 $x$ に対応する整数を返す。
- :question: **operator(k)** : 整数 $k$ に対応する座標を返す。
