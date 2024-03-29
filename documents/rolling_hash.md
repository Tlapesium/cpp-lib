---
title: Rolling Hash
documentation_of: //string/rolling_hash.cpp
---

## 説明
ハッシュを用いて文字列の一致判定を高速に行うアルゴリズム。

## 操作
- :heavy_check_mark: **RollingHash(S, b)** : 文字列 $S$ からハッシュテーブルを構築する。$b$ にはハッシュの基数を指定する。
- :heavy_check_mark: **get(l, r)** : 区間 $[l,r)$ のハッシュを求める。
- :question: **concat(b, l1, r1, l2, r2)** : 区間 $[l1,r1)$ と、ハッシュテーブル $b$ の区間 $[l2,r2)$ を結合したもののハッシュを求める。
- :heavy_check_mark: **getLCP(b, l1, l2)** : $l1$ から始まる区間と、ハッシュテーブル $b$ の $l2$ から始まる区間の最長共通接頭辞の長さを求める。