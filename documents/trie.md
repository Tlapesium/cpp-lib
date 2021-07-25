---
title: Trie
documentation_of: //string/trie.cpp
---

## 説明
文字列の集合を管理するデータ構造。

## 操作
### BinaryTrie()
空の Trie を構築する。
### insert(str)
文字列 $str$ を集合に追加する。
### kth_element(k)
辞書順で $k$ 番目の文字列を取得する。$k$ は 1-indexed であることに注意。
### prefix_count(str)
接頭辞が $str$ であるような文字列の個数を返す。