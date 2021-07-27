---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.cpp\"\n\r\nstruct Trie {\r\n\tstruct Node {\r\
    \n\t\tint node_size;\r\n\t\tint subtree_size;\r\n\t\tNode* child[26];\r\n\t\t\
    Node() : node_size(0), subtree_size(0) { for (int i = 0; i < 26; i++)child[i]\
    \ = nullptr; }\r\n\t};\r\n\r\n\tNode* root = new Node();\r\n\r\n\tvoid insert(Node*\
    \ node, int str_index, std::string& str) {\r\n\t\tif (str_index == str.size())\
    \ {\r\n\t\t\tnode->node_size++;\r\n\t\t\tnode->subtree_size++;\r\n\t\t}\r\n\t\t\
    else {\r\n\t\t\tauto& to = node->child[str[str_index] - 'a'];\r\n\t\t\tif (!to)to\
    \ = new Node();\r\n\t\t\tinsert(to, str_index + 1, str);\r\n\t\t\tnode->subtree_size++;\r\
    \n\t\t}\r\n\t}\r\n\r\n\tstd::string kth_element(Node* node, int k) {\r\n\t\tif\
    \ (k <= node->node_size)return \"\";\r\n\t\tint sum = node->node_size;\r\n\t\t\
    for (int i = 0; i < 26; i++) {\r\n\t\t\tif (sum + (node->child[i] ? node->child[i]->subtree_size\
    \ : 0) >= k) {\r\n\t\t\t\tstd::string ret = kth_element(node->child[i], k - sum);\r\
    \n\t\t\t\treturn char('a' + i) + ret;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tsum\
    \ += (node->child[i] ? node->child[i]->subtree_size : 0);\r\n\t\t\t}\r\n\t\t}\r\
    \n\t\treturn \"\";\r\n\t}\r\n\r\n\tint prefix_count(Node* node, int str_index,\
    \ std::string& str) {\r\n\t\tif (str_index == str.size()) {\r\n\t\t\treturn node->subtree_size;\r\
    \n\t\t}\r\n\t\telse {\r\n\t\t\tauto& to = node->child[str[str_index] - 'a'];\r\
    \n\t\t\tif (!to)return 0;\r\n\t\t\treturn prefix_count(to, str_index + 1, str);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tvoid insert(std::string& str) {\r\n\t\tinsert(root, 0,\
    \ str);\r\n\t}\r\n\r\n\tstd::string kth_element(int k) {\r\n\t\treturn kth_element(root,\
    \ k);\r\n\t}\r\n\r\n\tint prefix_count(std::string& str) {\r\n\t\treturn prefix_count(root,\
    \ 0, str);\r\n\t}\r\n\r\n};\n"
  code: "#pragma once\r\n\r\nstruct Trie {\r\n\tstruct Node {\r\n\t\tint node_size;\r\
    \n\t\tint subtree_size;\r\n\t\tNode* child[26];\r\n\t\tNode() : node_size(0),\
    \ subtree_size(0) { for (int i = 0; i < 26; i++)child[i] = nullptr; }\r\n\t};\r\
    \n\r\n\tNode* root = new Node();\r\n\r\n\tvoid insert(Node* node, int str_index,\
    \ std::string& str) {\r\n\t\tif (str_index == str.size()) {\r\n\t\t\tnode->node_size++;\r\
    \n\t\t\tnode->subtree_size++;\r\n\t\t}\r\n\t\telse {\r\n\t\t\tauto& to = node->child[str[str_index]\
    \ - 'a'];\r\n\t\t\tif (!to)to = new Node();\r\n\t\t\tinsert(to, str_index + 1,\
    \ str);\r\n\t\t\tnode->subtree_size++;\r\n\t\t}\r\n\t}\r\n\r\n\tstd::string kth_element(Node*\
    \ node, int k) {\r\n\t\tif (k <= node->node_size)return \"\";\r\n\t\tint sum =\
    \ node->node_size;\r\n\t\tfor (int i = 0; i < 26; i++) {\r\n\t\t\tif (sum + (node->child[i]\
    \ ? node->child[i]->subtree_size : 0) >= k) {\r\n\t\t\t\tstd::string ret = kth_element(node->child[i],\
    \ k - sum);\r\n\t\t\t\treturn char('a' + i) + ret;\r\n\t\t\t}\r\n\t\t\telse {\r\
    \n\t\t\t\tsum += (node->child[i] ? node->child[i]->subtree_size : 0);\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\treturn \"\";\r\n\t}\r\n\r\n\tint prefix_count(Node* node, int\
    \ str_index, std::string& str) {\r\n\t\tif (str_index == str.size()) {\r\n\t\t\
    \treturn node->subtree_size;\r\n\t\t}\r\n\t\telse {\r\n\t\t\tauto& to = node->child[str[str_index]\
    \ - 'a'];\r\n\t\t\tif (!to)return 0;\r\n\t\t\treturn prefix_count(to, str_index\
    \ + 1, str);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid insert(std::string& str) {\r\n\t\t\
    insert(root, 0, str);\r\n\t}\r\n\r\n\tstd::string kth_element(int k) {\r\n\t\t\
    return kth_element(root, k);\r\n\t}\r\n\r\n\tint prefix_count(std::string& str)\
    \ {\r\n\t\treturn prefix_count(root, 0, str);\r\n\t}\r\n\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.cpp
  requiredBy: []
  timestamp: '2021-07-25 20:03:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.cpp
layout: document
title: Trie
---

## 説明
文字列の集合を管理するデータ構造。

## 操作
### Trie()
空の Trie を構築する。
### insert(str)
文字列 $str$ を集合に追加する。
### kth_element(k)
辞書順で $k$ 番目の文字列を取得する。$k$ は 1-indexed であることに注意。
### prefix_count(str)
接頭辞が $str$ であるような文字列の個数を返す。