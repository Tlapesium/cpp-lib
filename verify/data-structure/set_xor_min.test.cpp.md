---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary_trie.cpp
    title: Binary Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/data-structure/set_xor_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\r\n#line 2 \"data-structure/binary_trie.cpp\"\
    \n#include <utility>\r\n\r\ntemplate<class T, int MAX_LOG>\r\nstruct BinaryTrie\
    \ {\r\n\tstruct Node {\r\n\t\tNode* child[2];\r\n\t\tT lazy;\r\n\t\tint size;\r\
    \n\t\tNode() : size(0), lazy(0), child{ nullptr, nullptr } {}\r\n\t};\r\n\tNode*\
    \ root;\r\n\tBinaryTrie() { root = new Node(); }\r\n\r\n\tvoid insert(const T&\
    \ x, Node* node, int bit_index) {\r\n\t\tpropagate(node, bit_index);\r\n\t\tif\
    \ (bit_index == -1) {\r\n\t\t\tnode->size++;\r\n\t\t}\r\n\t\telse {\r\n\t\t\t\
    auto& to = node->child[(x >> bit_index) & 1];\r\n\t\t\tif (!to) to = new Node();\r\
    \n\t\t\tinsert(x, to, bit_index - 1);\r\n\t\t\tnode->size++;\r\n\t\t}\r\n\t}\r\
    \n\r\n\tvoid erase(const T& x, Node* node, int bit_index) {\r\n\t\tpropagate(node,\
    \ bit_index);\r\n\t\tif (bit_index == -1) {\r\n\t\t\tnode->size--;\r\n\t\t}\r\n\
    \t\telse {\r\n\t\t\terase(x, node->child[(x >> bit_index) & 1], bit_index - 1);\r\
    \n\t\t\tnode->size--;\r\n\t\t}\r\n\t}\r\n\r\n\tT max_element(Node* node, int bit_index)\
    \ {\r\n\t\tpropagate(node, bit_index);\r\n\t\tif (bit_index == -1) return T(0);\r\
    \n\t\tif (node->child[1] && node->child[1]->size) {\r\n\t\t\tT ret = max_element(node->child[1],\
    \ bit_index - 1);\r\n\t\t\treturn ret | (T(1) << bit_index);\r\n\t\t}\r\n\t\t\
    else {\r\n\t\t\treturn max_element(node->child[0], bit_index - 1);\r\n\t\t}\r\n\
    \t}\r\n\r\n\tT min_element(Node* node, int bit_index) {\r\n\t\tpropagate(node,\
    \ bit_index);\r\n\t\tif (bit_index == -1) return T(0);\r\n\t\tif (node->child[0]\
    \ && node->child[0]->size) {\r\n\t\t\treturn min_element(node->child[0], bit_index\
    \ - 1);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tT ret = min_element(node->child[1], bit_index\
    \ - 1);\r\n\t\t\treturn ret | (T(1) << bit_index);\r\n\t\t}\r\n\t}\r\n\r\n\tint\
    \ count_less(const T& x, Node* node, int bit_index) {\r\n\t\tpropagate(node, bit_index);\r\
    \n\t\tif (bit_index == -1) return 0;\r\n\t\tif (x < 0)return 0;\r\n\t\tint ret\
    \ = 0;\r\n\t\tif ((x >> bit_index) & 1) {\r\n\t\t\tif (node->child[0]) ret +=\
    \ node->child[0]->size;\r\n\t\t\tif (node->child[1]) ret += count_less(x, node->child[1],\
    \ bit_index - 1);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tif (node->child[0]) ret += count_less(x,\
    \ node->child[0], bit_index - 1);\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\r\n\t\
    T kth_element(int k, Node* node, int bit_index) { // 1-indexed\r\n\t\tpropagate(node,\
    \ bit_index);\r\n\t\tif (bit_index == -1)return T(0);\r\n\t\tif ((node->child[0]\
    \ ? node->child[0]->size : 0) < k) {\r\n\t\t\tT ret = kth_element(k - (node->child[0]\
    \ ? node->child[0]->size : 0), node->child[1], bit_index - 1);\r\n\t\t\treturn\
    \ ret | (T(1) << bit_index);\r\n\t\t}\r\n\t\telse {\r\n\t\t\treturn kth_element(k,\
    \ node->child[0], bit_index - 1);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid propagate(Node*\
    \ node, int bit_index) {\r\n\t\tif (bit_index >= 0 && (node->lazy >> bit_index)\
    \ & 1) std::swap(node->child[0], node->child[1]);\r\n\t\tif (node->child[0]) node->child[0]->lazy\
    \ ^= node->lazy;\r\n\t\tif (node->child[1]) node->child[1]->lazy ^= node->lazy;\r\
    \n\t\tnode->lazy = T(0);\r\n\t}\r\n\r\n\tvoid insert(const T& x) { insert(x, root,\
    \ MAX_LOG); }\r\n\tvoid erase(const T& x) { erase(x, root, MAX_LOG); }\r\n\tT\
    \ max_element() { return max_element(root, MAX_LOG); }\r\n\tT min_element() {\
    \ return min_element(root, MAX_LOG); }\r\n\tint count_less(const T& x) { return\
    \ count_less(x, root, MAX_LOG); }\r\n\tT kth_element(int k) { return kth_element(k,\
    \ root, MAX_LOG); }\r\n\tint lower_bound(const T& x) { return count_less(x); }\r\
    \n\tint upper_bound(const T& x) { return count_less(x + 1); }\r\n\tint find(const\
    \ T& x) { return upper_bound(x) - lower_bound(x); }\r\n\tvoid all_xor(const T&\
    \ x) { root->lazy ^= x; }\r\n\tint size() { return root->size; };\r\n\r\n};\r\n\
    \t\n#line 3 \"verify/data-structure/set_xor_min.test.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tBinaryTrie<int,\
    \ 31> BT;\r\n\tint Q;\r\n\tcin >> Q;\r\n\tfor (int i = 0; i < Q; i++) {\r\n\t\t\
    int t, x;\r\n\t\tcin >> t >> x;\r\n\t\tif (t == 0) {\r\n\t\t\tif (!BT.find(x))\
    \ BT.insert(x);\r\n\t\t}\r\n\t\tif (t == 1) {\r\n\t\t\tif (BT.find(x)) BT.erase(x);\r\
    \n\t\t}\r\n\t\tif (t == 2) {\r\n\t\t\tBT.all_xor(x);\r\n\t\t\tcout << BT.min_element()\
    \ << endl;\r\n\t\t\tBT.all_xor(x);\r\n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\r\n#include\
    \ \"data-structure/binary_trie.cpp\"\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tBinaryTrie<int, 31> BT;\r\
    \n\tint Q;\r\n\tcin >> Q;\r\n\tfor (int i = 0; i < Q; i++) {\r\n\t\tint t, x;\r\
    \n\t\tcin >> t >> x;\r\n\t\tif (t == 0) {\r\n\t\t\tif (!BT.find(x)) BT.insert(x);\r\
    \n\t\t}\r\n\t\tif (t == 1) {\r\n\t\t\tif (BT.find(x)) BT.erase(x);\r\n\t\t}\r\n\
    \t\tif (t == 2) {\r\n\t\t\tBT.all_xor(x);\r\n\t\t\tcout << BT.min_element() <<\
    \ endl;\r\n\t\t\tBT.all_xor(x);\r\n\t\t}\r\n\t}\r\n}"
  dependsOn:
  - data-structure/binary_trie.cpp
  isVerificationFile: true
  path: verify/data-structure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 00:05:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/set_xor_min.test.cpp
- /verify/verify/data-structure/set_xor_min.test.cpp.html
title: verify/data-structure/set_xor_min.test.cpp
---
