---
title: HashMap
documentation_of: //data-structure/hashmap.cpp
---

## 説明
開番地法によるハッシュテーブルの実装。キーの重複を許さない。

## 操作
- :heavy_check_mark: **HashMap(N)** : キーの型が $KeyType$ 、値の型が $ValType$ で、バケットサイズが $N$ のハッシュテーブルを構築する。
- :heavy_check_mark: **insert(a, b)** : キーが $a$ 、値が $b$ の要素を追加する。すでにキーが $a$ の要素が存在する場合は追加されない。追加されたかどうかの真偽値を返す。
- :heavy_check_mark: **erase(a)** : キーが $a$ であるような要素を削除する。キーが $a$ であるような要素が存在しない場合は何もしない。削除されたかどうかの真偽値を返す。
- :heavy_check_mark: **contains(a)** : キーが $a$ であるような要素が存在するかどうか返す。
- :question: **at(a)** : キーが $a$ であるような要素の値の参照を取得する。キーが $a$ であるような要素が存在しないとき、例外を投げる。
- :heavy_check_mark: **operator\[\]\(a\)** : キーが $a$ であるような要素の値の参照を取得する。キーが $a$ であるような要素が存在せず要素を追加できるとき、自動で要素が追加される。
- :heavy_check_mark: **size()** : 現在の要素数を取得する。