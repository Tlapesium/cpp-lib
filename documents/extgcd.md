---
title: 拡張ユークリッドの互除法
documentation_of: //math/extgcd.cpp
---

## 説明
$ax + by = \mathrm{gcd}(a,b)$ を満たす整数 $(x,y)$ を求める。

$\mathrm{abs}(x) + \mathrm{abs}(y)$ が最小となるものを返し、複数存在する場合は $x \leq y$ であるようなものを返す。