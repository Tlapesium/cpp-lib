---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/data-structure/set_xor_min.test.cpp
    title: verify/data-structure/set_xor_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/binary_trie.cpp\"\n\r\ntemplate<class T,\
    \ int MAX_LOG>\r\nstruct BinaryTrie {\r\n\tstruct Node {\r\n\t\tNode* child[2];\r\
    \n\t\tT lazy;\r\n\t\tint size;\r\n\t\tNode() : size(0), lazy(0), child{ nullptr,\
    \ nullptr } {}\r\n\t};\r\n\tNode* root;\r\n\tBinaryTrie() { root = new Node();\
    \ }\r\n\r\n\tvoid insert(const T& x, Node* node, int bit_index) {\r\n\t\tpropagate(node,\
    \ bit_index);\r\n\t\tif (bit_index == -1) {\r\n\t\t\tnode->size++;\r\n\t\t}\r\n\
    \t\telse {\r\n\t\t\tauto& to = node->child[(x >> bit_index) & 1];\r\n\t\t\tif\
    \ (!to) to = new Node();\r\n\t\t\tinsert(x, to, bit_index - 1);\r\n\t\t\tnode->size++;\r\
    \n\t\t}\r\n\t}\r\n\r\n\tvoid erase(const T& x, Node* node, int bit_index) {\r\n\
    \t\tpropagate(node, bit_index);\r\n\t\tif (bit_index == -1) {\r\n\t\t\tnode->size--;\r\
    \n\t\t}\r\n\t\telse {\r\n\t\t\terase(x, node->child[(x >> bit_index) & 1], bit_index\
    \ - 1);\r\n\t\t\tnode->size--;\r\n\t\t}\r\n\t}\r\n\r\n\tT max_element(Node* node,\
    \ int bit_index) {\r\n\t\tpropagate(node, bit_index);\r\n\t\tif (bit_index ==\
    \ -1) return T(0);\r\n\t\tif (node->child[1] && node->child[1]->size) {\r\n\t\t\
    \tT ret = max_element(node->child[1], bit_index - 1);\r\n\t\t\treturn ret | (T(1)\
    \ << bit_index);\r\n\t\t}\r\n\t\telse {\r\n\t\t\treturn max_element(node->child[0],\
    \ bit_index - 1);\r\n\t\t}\r\n\t}\r\n\r\n\tT min_element(Node* node, int bit_index)\
    \ {\r\n\t\tpropagate(node, bit_index);\r\n\t\tif (bit_index == -1) return T(0);\r\
    \n\t\tif (node->child[0] && node->child[0]->size) {\r\n\t\t\treturn min_element(node->child[0],\
    \ bit_index - 1);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tT ret = min_element(node->child[1],\
    \ bit_index - 1);\r\n\t\t\treturn ret | (T(1) << bit_index);\r\n\t\t}\r\n\t}\r\
    \n\r\n\tint count_less(const T& x, Node* node, int bit_index) {\r\n\t\tpropagate(node,\
    \ bit_index);\r\n\t\tif (bit_index == -1) return 0;\r\n\t\tif (x < 0)return 0;\r\
    \n\t\tint ret = 0;\r\n\t\tif ((x >> bit_index) & 1) {\r\n\t\t\tif (node->child[0])\
    \ ret += node->child[0]->size;\r\n\t\t\tif (node->child[1]) ret += count_less(x,\
    \ node->child[1], bit_index - 1);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tif (node->child[0])\
    \ ret += count_less(x, node->child[0], bit_index - 1);\r\n\t\t}\r\n\t\treturn\
    \ ret;\r\n\t}\r\n\r\n\tT kth_element(int k, Node* node, int bit_index) { // 1-indexed\r\
    \n\t\tpropagate(node, bit_index);\r\n\t\tif (bit_index == -1)return T(0);\r\n\t\
    \tif ((node->child[0] ? node->child[0]->size : 0) < k) {\r\n\t\t\tT ret = kth_element(k\
    \ - (node->child[0] ? node->child[0]->size : 0), node->child[1], bit_index - 1);\r\
    \n\t\t\treturn ret | (T(1) << bit_index);\r\n\t\t}\r\n\t\telse {\r\n\t\t\treturn\
    \ kth_element(k, node->child[0], bit_index - 1);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid\
    \ propagate(Node* node, int bit_index) {\r\n\t\tif (bit_index >= 0 && (node->lazy\
    \ >> bit_index) & 1) swap(node->child[0], node->child[1]);\r\n\t\tif (node->child[0])\
    \ node->child[0]->lazy ^= node->lazy;\r\n\t\tif (node->child[1]) node->child[1]->lazy\
    \ ^= node->lazy;\r\n\t\tnode->lazy = T(0);\r\n\t}\r\n\r\n\tvoid insert(const T&\
    \ x) { insert(x, root, MAX_LOG); }\r\n\tvoid erase(const T& x) { erase(x, root,\
    \ MAX_LOG); }\r\n\tT max_element() { return max_element(root, MAX_LOG); }\r\n\t\
    T min_element() { return min_element(root, MAX_LOG); }\r\n\tint count_less(const\
    \ T& x) { return count_less(x, root, MAX_LOG); }\r\n\tT kth_element(int k) { return\
    \ kth_element(k, root, MAX_LOG); }\r\n\tint lower_bound(const T& x) { return count_less(x);\
    \ }\r\n\tint upper_bound(const T& x) { return count_less(x + 1); }\r\n\tint find(const\
    \ T& x) { return upper_bound(x) - lower_bound(x); }\r\n\tvoid all_xor(const T&\
    \ x) { root->lazy ^= x; }\r\n\tint size() { return root->size; };\r\n\r\n};\r\n\
    \t\n"
  code: "#pragma once\r\n\r\ntemplate<class T, int MAX_LOG>\r\nstruct BinaryTrie {\r\
    \n\tstruct Node {\r\n\t\tNode* child[2];\r\n\t\tT lazy;\r\n\t\tint size;\r\n\t\
    \tNode() : size(0), lazy(0), child{ nullptr, nullptr } {}\r\n\t};\r\n\tNode* root;\r\
    \n\tBinaryTrie() { root = new Node(); }\r\n\r\n\tvoid insert(const T& x, Node*\
    \ node, int bit_index) {\r\n\t\tpropagate(node, bit_index);\r\n\t\tif (bit_index\
    \ == -1) {\r\n\t\t\tnode->size++;\r\n\t\t}\r\n\t\telse {\r\n\t\t\tauto& to = node->child[(x\
    \ >> bit_index) & 1];\r\n\t\t\tif (!to) to = new Node();\r\n\t\t\tinsert(x, to,\
    \ bit_index - 1);\r\n\t\t\tnode->size++;\r\n\t\t}\r\n\t}\r\n\r\n\tvoid erase(const\
    \ T& x, Node* node, int bit_index) {\r\n\t\tpropagate(node, bit_index);\r\n\t\t\
    if (bit_index == -1) {\r\n\t\t\tnode->size--;\r\n\t\t}\r\n\t\telse {\r\n\t\t\t\
    erase(x, node->child[(x >> bit_index) & 1], bit_index - 1);\r\n\t\t\tnode->size--;\r\
    \n\t\t}\r\n\t}\r\n\r\n\tT max_element(Node* node, int bit_index) {\r\n\t\tpropagate(node,\
    \ bit_index);\r\n\t\tif (bit_index == -1) return T(0);\r\n\t\tif (node->child[1]\
    \ && node->child[1]->size) {\r\n\t\t\tT ret = max_element(node->child[1], bit_index\
    \ - 1);\r\n\t\t\treturn ret | (T(1) << bit_index);\r\n\t\t}\r\n\t\telse {\r\n\t\
    \t\treturn max_element(node->child[0], bit_index - 1);\r\n\t\t}\r\n\t}\r\n\r\n\
    \tT min_element(Node* node, int bit_index) {\r\n\t\tpropagate(node, bit_index);\r\
    \n\t\tif (bit_index == -1) return T(0);\r\n\t\tif (node->child[0] && node->child[0]->size)\
    \ {\r\n\t\t\treturn min_element(node->child[0], bit_index - 1);\r\n\t\t}\r\n\t\
    \telse {\r\n\t\t\tT ret = min_element(node->child[1], bit_index - 1);\r\n\t\t\t\
    return ret | (T(1) << bit_index);\r\n\t\t}\r\n\t}\r\n\r\n\tint count_less(const\
    \ T& x, Node* node, int bit_index) {\r\n\t\tpropagate(node, bit_index);\r\n\t\t\
    if (bit_index == -1) return 0;\r\n\t\tif (x < 0)return 0;\r\n\t\tint ret = 0;\r\
    \n\t\tif ((x >> bit_index) & 1) {\r\n\t\t\tif (node->child[0]) ret += node->child[0]->size;\r\
    \n\t\t\tif (node->child[1]) ret += count_less(x, node->child[1], bit_index - 1);\r\
    \n\t\t}\r\n\t\telse {\r\n\t\t\tif (node->child[0]) ret += count_less(x, node->child[0],\
    \ bit_index - 1);\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\r\n\tT kth_element(int\
    \ k, Node* node, int bit_index) { // 1-indexed\r\n\t\tpropagate(node, bit_index);\r\
    \n\t\tif (bit_index == -1)return T(0);\r\n\t\tif ((node->child[0] ? node->child[0]->size\
    \ : 0) < k) {\r\n\t\t\tT ret = kth_element(k - (node->child[0] ? node->child[0]->size\
    \ : 0), node->child[1], bit_index - 1);\r\n\t\t\treturn ret | (T(1) << bit_index);\r\
    \n\t\t}\r\n\t\telse {\r\n\t\t\treturn kth_element(k, node->child[0], bit_index\
    \ - 1);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid propagate(Node* node, int bit_index) {\r\
    \n\t\tif (bit_index >= 0 && (node->lazy >> bit_index) & 1) swap(node->child[0],\
    \ node->child[1]);\r\n\t\tif (node->child[0]) node->child[0]->lazy ^= node->lazy;\r\
    \n\t\tif (node->child[1]) node->child[1]->lazy ^= node->lazy;\r\n\t\tnode->lazy\
    \ = T(0);\r\n\t}\r\n\r\n\tvoid insert(const T& x) { insert(x, root, MAX_LOG);\
    \ }\r\n\tvoid erase(const T& x) { erase(x, root, MAX_LOG); }\r\n\tT max_element()\
    \ { return max_element(root, MAX_LOG); }\r\n\tT min_element() { return min_element(root,\
    \ MAX_LOG); }\r\n\tint count_less(const T& x) { return count_less(x, root, MAX_LOG);\
    \ }\r\n\tT kth_element(int k) { return kth_element(k, root, MAX_LOG); }\r\n\t\
    int lower_bound(const T& x) { return count_less(x); }\r\n\tint upper_bound(const\
    \ T& x) { return count_less(x + 1); }\r\n\tint find(const T& x) { return upper_bound(x)\
    \ - lower_bound(x); }\r\n\tvoid all_xor(const T& x) { root->lazy ^= x; }\r\n\t\
    int size() { return root->size; };\r\n\r\n};\r\n\t"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary_trie.cpp
  requiredBy: []
  timestamp: '2021-02-24 23:36:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/data-structure/set_xor_min.test.cpp
documentation_of: data-structure/binary_trie.cpp
layout: document
title: Binary Trie
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