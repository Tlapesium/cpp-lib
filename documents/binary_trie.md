---
title: Binary Trie
documentation_of: //data-structure/binary_trie.cpp
---

## 説明
非負整数の集合に対して様々な操作ができるデータ構造。

## 操作
### BinaryTrie()
空の Binary Trie を構築する。MAX_LOG は入る値の $2$ 進数での最大桁数を指定する。
### insert(const T& x)
値 $x$ を集合に追加する。
### erase(const T& x)
値 $x$ を集合から削除する。存在しない値を削除しようとするとこわれるので注意。
### max_element()
集合内の最大値を取得する。
### min_element()
集合内の最小値を取得する。
### count_less(const T& x)
集合に含まれる値のうち、$x$ 未満であるものの個数を数える。
### kth_element(int k)
昇順で $k$ 番目の値を取得する。$k$ は 1-indexed であることに注意。
### lower_bound(const T& x)
集合内で $x$ 以上の最小の要素の番号を取得する。
### upper_bound(const T& x)
集合内で $x$ より大きい最小の要素の番号を取得する。
### find(const T& x)
集合に含まれる $x$ の個数を取得する。
### all_xor(const T& x)
全要素を $x$ と xor を取った値に変更する。
### size()
集合に含まれる値の個数を取得する。