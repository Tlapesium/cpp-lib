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
    PROBLEM: https://atcoder.jp/contests/abc194/tasks/abc194_e
    links:
    - https://atcoder.jp/contests/abc194/tasks/abc194_e
  bundledCode: "#line 1 \"verify/data-structure/ABC194-E.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc194/tasks/abc194_e\"\r\n#include <bits/stdc++.h>\r\
    \n#line 2 \"data-structure/binary_trie.cpp\"\n\r\ntemplate<class T, int MAX_LOG>\r\
    \nstruct BinaryTrie {\r\n\tstruct Node {\r\n\t\tNode* child[2];\r\n\t\tT lazy;\r\
    \n\t\tint size;\r\n\t\tbool filled;\r\n\t\tNode() : child{ nullptr, nullptr },\
    \ lazy(0), size(0), filled(false) {}\r\n\t};\r\n\tNode* root;\r\n\tBinaryTrie()\
    \ { root = new Node(); }\r\n\r\n\tvoid insert(const T& x, Node* node, int bit_index)\
    \ {\r\n\t\tpropagate(node, bit_index);\r\n\t\tif (bit_index == -1) {\r\n\t\t\t\
    node->size++;\r\n\t\t\tnode->filled = true;\r\n\t\t}\r\n\t\telse {\r\n\t\t\tauto&\
    \ to = node->child[(x >> bit_index) & 1];\r\n\t\t\tif (!to) to = new Node();\r\
    \n\t\t\tinsert(x, to, bit_index - 1);\r\n\t\t\tnode->size++;\r\n\t\t\tnode->filled\
    \ = (node->child[0] && node->child[0]->filled) && (node->child[1] && node->child[1]->filled);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tvoid erase(const T& x, Node* node, int bit_index) {\r\n\
    \t\tpropagate(node, bit_index);\r\n\t\tif (bit_index == -1) {\r\n\t\t\tnode->size--;\r\
    \n\t\t\tnode->filled = node->size > 0;\r\n\t\t}\r\n\t\telse {\r\n\t\t\terase(x,\
    \ node->child[(x >> bit_index) & 1], bit_index - 1);\r\n\t\t\tnode->size--;\r\n\
    \t\t\tnode->filled = (node->child[0] && node->child[0]->filled) && (node->child[1]\
    \ && node->child[1]->filled);\r\n\t\t}\r\n\t}\r\n\r\n\tT max_element(Node* node,\
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
    \n\t\tpropagate(node, bit_index);\r\n\t\tif (bit_index == -1) return T(0);\r\n\
    \t\tif ((node->child[0] ? node->child[0]->size : 0) < k) {\r\n\t\t\tT ret = kth_element(k\
    \ - (node->child[0] ? node->child[0]->size : 0), node->child[1], bit_index - 1);\r\
    \n\t\t\treturn ret | (T(1) << bit_index);\r\n\t\t}\r\n\t\telse {\r\n\t\t\treturn\
    \ kth_element(k, node->child[0], bit_index - 1);\r\n\t\t}\r\n\t}\r\n\r\n\tT mex(Node*\
    \ node, int bit_index) {\r\n\t\tpropagate(node, bit_index);\r\n\t\tif (bit_index\
    \ == -1 || !node->child[0]) return 0;\r\n\t\tif (node->child[0]->filled) {\r\n\
    \t\t\tT ret = T(1) << bit_index;\r\n\t\t\tif (node->child[1])ret |= mex(node->child[1],\
    \ bit_index - 1);\r\n\t\t\treturn ret;\r\n\t\t}\r\n\t\telse {\r\n\t\t\treturn\
    \ mex(node->child[0], bit_index - 1);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid propagate(Node*\
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
    \ T& x) { return upper_bound(x) - lower_bound(x); }\r\n\tT mex() { return mex(root,\
    \ MAX_LOG); }\r\n\tvoid all_xor(const T& x) { root->lazy ^= x; }\r\n\tint size()\
    \ { return root->size; };\r\n\r\n};\n#line 4 \"verify/data-structure/ABC194-E.test.cpp\"\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\t\r\n\tBinaryTrie<int,\
    \ 30> BT;\r\n\tint N, M;\r\n\tcin >> N >> M;\r\n\tvector<int> A(N);\r\n\tfor (int\
    \ i = 0; i < N; i++)cin >> A[i];\r\n\tfor (int i = 0; i < M; i++)BT.insert(A[i]);\r\
    \n\tint ans = BT.mex();\r\n\tfor (int i = 0; i < N - M; i++) {\r\n\t\tBT.erase(A[i]);\r\
    \n\t\tBT.insert(A[i + M]);\r\n\t\tans = min(ans, BT.mex());\r\n\t}\r\n\tcout <<\
    \ ans << endl;\r\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc194/tasks/abc194_e\"\r\n\
    #include <bits/stdc++.h>\r\n#include \"data-structure/binary_trie.cpp\"\r\nusing\
    \ namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\t\r\n\tBinaryTrie<int,\
    \ 30> BT;\r\n\tint N, M;\r\n\tcin >> N >> M;\r\n\tvector<int> A(N);\r\n\tfor (int\
    \ i = 0; i < N; i++)cin >> A[i];\r\n\tfor (int i = 0; i < M; i++)BT.insert(A[i]);\r\
    \n\tint ans = BT.mex();\r\n\tfor (int i = 0; i < N - M; i++) {\r\n\t\tBT.erase(A[i]);\r\
    \n\t\tBT.insert(A[i + M]);\r\n\t\tans = min(ans, BT.mex());\r\n\t}\r\n\tcout <<\
    \ ans << endl;\r\n}"
  dependsOn:
  - data-structure/binary_trie.cpp
  isVerificationFile: true
  path: verify/data-structure/ABC194-E.test.cpp
  requiredBy: []
  timestamp: '2021-08-15 07:02:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/ABC194-E.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/ABC194-E.test.cpp
- /verify/verify/data-structure/ABC194-E.test.cpp.html
title: verify/data-structure/ABC194-E.test.cpp
---
