---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/DSL_2_G.test.cpp
    title: verify/data-structure/DSL_2_G.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/dynamic_lazy_segment_tree.cpp\"\n\r\ntemplate\
    \ <class Monoid, class OperatorMonoid, class Operator, class Apply, class Merge\
    \ >\r\nstruct DynamicLazySegmentTree {\r\n\tconst Operator op;\r\n\tconst Apply\
    \ apply;\r\n\tconst Merge merge;\r\n\tconst Monoid IE;\r\n\tconst OperatorMonoid\
    \ OpIE;\r\n\tconst int sz;\r\n\r\n\tstruct Node {\r\n\t\tMonoid dat;\r\n\t\tOperatorMonoid\
    \ lazy;\r\n\t\tNode* left, * right;\r\n\t\tNode(Monoid ie, OperatorMonoid opie)\
    \ : dat(ie), lazy(opie), left(nullptr), right(nullptr) {}\r\n\t};\r\n\r\n\tNode*\
    \ root;\r\n\r\n\tDynamicLazySegmentTree(int n, Operator F, Apply G, Merge H, Monoid\
    \ IE1, OperatorMonoid IE2) : op(F), apply(G), merge(H), IE(IE1), OpIE(IE2), sz(n),\
    \ root(new Node(IE, OpIE)) {}\r\n\r\n\t// x \u3092\u4F1D\u642C\u3055\u305B\u308B\
    \r\n\tvoid propagate(Node* k, int l, int r) {\r\n\t\tk->dat = apply(k->dat, k->lazy,\
    \ r - l);\r\n\r\n\t\tif (!k->left)k->left = new Node(IE, OpIE);\r\n\t\tk->left->lazy\
    \ = merge(k->lazy, k->left->lazy);\r\n\r\n\t\tif (!k->right)k->right = new Node(IE,\
    \ OpIE);\r\n\t\tk->right->lazy = merge(k->lazy, k->right->lazy);\r\n\r\n\t\tk->lazy\
    \ = OpIE;\r\n\t}\r\n\r\n\t// \u533A\u9593 [l,r) \u306B x \u3092\u4F5C\u7528\r\n\
    \tvoid set(int l, int r, OperatorMonoid x, Node* k = nullptr, int a = 0, int b\
    \ = -1) {\r\n\t\tif (!k)k = root;\r\n\t\tif (b < 0)b = sz;\r\n\r\n\t\tpropagate(k,\
    \ a, b);\r\n\r\n\t\tif (r <= a || b <= l)return;\r\n\t\tif (l <= a && b <= r)\
    \ {\r\n\t\t\tk->lazy = merge(x, k->lazy);\r\n\t\t\tpropagate(k, a, b);\r\n\t\t\
    }\r\n\t\telse {\r\n\t\t\tset(l, r, x, k->left, a, (a + b) / 2);\r\n\t\t\tset(l,\
    \ r, x, k->right, (a + b) / 2, b);\r\n\t\t\tk->dat = op(k->left->dat, k->right->dat);\r\
    \n\t\t}\r\n\t}\r\n\r\n\t// \u533A\u9593 [l,r) \u306E\u7A4D\u3092\u53D6\u5F97\r\
    \n\tMonoid get(int l, int r, Node* k = nullptr, int a = 0, int b = -1) {\r\n\t\
    \tif (!k)k = root;\r\n\t\tif (b < 0)b = sz;\r\n\r\n\t\tpropagate(k, a, b);\r\n\
    \r\n\t\tif (r <= a || b <= l)return IE;\r\n\t\tif (l <= a && b <= r)return k->dat;\r\
    \n\r\n\t\treturn op(\r\n\t\t\tget(l, r, k->left, a, (a + b) / 2),\r\n\t\t\tget(l,\
    \ r, k->right, (a + b) / 2, b)\r\n\t\t);\r\n\t}\r\n\r\n\t// isOK(fold(l,l+1,...,r-1))\
    \ == 1 \u3068\u306A\u308B\u6700\u5927\u306Er\u3092\u6C42\u3081\u308B\r\n\ttemplate<class\
    \ DetermineFunc>\r\n\tint max_right(DetermineFunc isOK, int l = 0) {\r\n\t\tpropagate(root,\
    \ 0, sz);\r\n\t\treturn max_right(isOK, l, root, 0, sz, IE);\r\n\t}\r\n\r\n\t\
    template<class DetermineFunc>\r\n\tint max_right(DetermineFunc isOK, int l, Node*\
    \ k, int a, int b, Monoid sum) {\r\n\t\tif (isOK(root->dat))return sz;\r\n\t\t\
    if (b - a == 1) return a;\r\n\r\n\t\tpropagate(k->left, a, (a + b) / 2);\r\n\t\
    \tpropagate(k->right, (a + b) / 2, b);\r\n\r\n\t\tif (isOK(op(sum, k->left->dat)))\
    \ {\r\n\t\t\tsum = op(sum, k->left->dat);\r\n\t\t\treturn max_right(isOK, l, k->right,\
    \ (a + b) / 2, b, sum);\r\n\t\t}\r\n\t\telse {\r\n\t\t\treturn max_right(isOK,\
    \ l, k->left, a, (a + b) / 2, sum);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid dump() {\r\n\
    \t\tfor (int i = 0; i < sz; i++)std::cout << get(i, i + 1) << (i == sz ? \"\\\
    n\" : \" \");\r\n\t}\r\n\r\n};\r\n\r\ntemplate <class Monoid, class OperatorMonoid,\
    \ class Operator, class Apply, class Merge >\r\nDynamicLazySegmentTree<Monoid,\
    \ OperatorMonoid, Operator, Apply, Merge > makeDynamicLazySegTree(int n, Operator\
    \ F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) {\r\n\treturn DynamicLazySegmentTree<Monoid,\
    \ OperatorMonoid, Operator, Apply, Merge >(n, F, G, H, IE1, IE2);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <class Monoid, class OperatorMonoid, class Operator,\
    \ class Apply, class Merge >\r\nstruct DynamicLazySegmentTree {\r\n\tconst Operator\
    \ op;\r\n\tconst Apply apply;\r\n\tconst Merge merge;\r\n\tconst Monoid IE;\r\n\
    \tconst OperatorMonoid OpIE;\r\n\tconst int sz;\r\n\r\n\tstruct Node {\r\n\t\t\
    Monoid dat;\r\n\t\tOperatorMonoid lazy;\r\n\t\tNode* left, * right;\r\n\t\tNode(Monoid\
    \ ie, OperatorMonoid opie) : dat(ie), lazy(opie), left(nullptr), right(nullptr)\
    \ {}\r\n\t};\r\n\r\n\tNode* root;\r\n\r\n\tDynamicLazySegmentTree(int n, Operator\
    \ F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) : op(F), apply(G), merge(H),\
    \ IE(IE1), OpIE(IE2), sz(n), root(new Node(IE, OpIE)) {}\r\n\r\n\t// x \u3092\u4F1D\
    \u642C\u3055\u305B\u308B\r\n\tvoid propagate(Node* k, int l, int r) {\r\n\t\t\
    k->dat = apply(k->dat, k->lazy, r - l);\r\n\r\n\t\tif (!k->left)k->left = new\
    \ Node(IE, OpIE);\r\n\t\tk->left->lazy = merge(k->lazy, k->left->lazy);\r\n\r\n\
    \t\tif (!k->right)k->right = new Node(IE, OpIE);\r\n\t\tk->right->lazy = merge(k->lazy,\
    \ k->right->lazy);\r\n\r\n\t\tk->lazy = OpIE;\r\n\t}\r\n\r\n\t// \u533A\u9593\
    \ [l,r) \u306B x \u3092\u4F5C\u7528\r\n\tvoid set(int l, int r, OperatorMonoid\
    \ x, Node* k = nullptr, int a = 0, int b = -1) {\r\n\t\tif (!k)k = root;\r\n\t\
    \tif (b < 0)b = sz;\r\n\r\n\t\tpropagate(k, a, b);\r\n\r\n\t\tif (r <= a || b\
    \ <= l)return;\r\n\t\tif (l <= a && b <= r) {\r\n\t\t\tk->lazy = merge(x, k->lazy);\r\
    \n\t\t\tpropagate(k, a, b);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tset(l, r, x, k->left,\
    \ a, (a + b) / 2);\r\n\t\t\tset(l, r, x, k->right, (a + b) / 2, b);\r\n\t\t\t\
    k->dat = op(k->left->dat, k->right->dat);\r\n\t\t}\r\n\t}\r\n\r\n\t// \u533A\u9593\
    \ [l,r) \u306E\u7A4D\u3092\u53D6\u5F97\r\n\tMonoid get(int l, int r, Node* k =\
    \ nullptr, int a = 0, int b = -1) {\r\n\t\tif (!k)k = root;\r\n\t\tif (b < 0)b\
    \ = sz;\r\n\r\n\t\tpropagate(k, a, b);\r\n\r\n\t\tif (r <= a || b <= l)return\
    \ IE;\r\n\t\tif (l <= a && b <= r)return k->dat;\r\n\r\n\t\treturn op(\r\n\t\t\
    \tget(l, r, k->left, a, (a + b) / 2),\r\n\t\t\tget(l, r, k->right, (a + b) / 2,\
    \ b)\r\n\t\t);\r\n\t}\r\n\r\n\t// isOK(fold(l,l+1,...,r-1)) == 1 \u3068\u306A\u308B\
    \u6700\u5927\u306Er\u3092\u6C42\u3081\u308B\r\n\ttemplate<class DetermineFunc>\r\
    \n\tint max_right(DetermineFunc isOK, int l = 0) {\r\n\t\tpropagate(root, 0, sz);\r\
    \n\t\treturn max_right(isOK, l, root, 0, sz, IE);\r\n\t}\r\n\r\n\ttemplate<class\
    \ DetermineFunc>\r\n\tint max_right(DetermineFunc isOK, int l, Node* k, int a,\
    \ int b, Monoid sum) {\r\n\t\tif (isOK(root->dat))return sz;\r\n\t\tif (b - a\
    \ == 1) return a;\r\n\r\n\t\tpropagate(k->left, a, (a + b) / 2);\r\n\t\tpropagate(k->right,\
    \ (a + b) / 2, b);\r\n\r\n\t\tif (isOK(op(sum, k->left->dat))) {\r\n\t\t\tsum\
    \ = op(sum, k->left->dat);\r\n\t\t\treturn max_right(isOK, l, k->right, (a + b)\
    \ / 2, b, sum);\r\n\t\t}\r\n\t\telse {\r\n\t\t\treturn max_right(isOK, l, k->left,\
    \ a, (a + b) / 2, sum);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid dump() {\r\n\t\tfor (int\
    \ i = 0; i < sz; i++)std::cout << get(i, i + 1) << (i == sz ? \"\\n\" : \" \"\
    );\r\n\t}\r\n\r\n};\r\n\r\ntemplate <class Monoid, class OperatorMonoid, class\
    \ Operator, class Apply, class Merge >\r\nDynamicLazySegmentTree<Monoid, OperatorMonoid,\
    \ Operator, Apply, Merge > makeDynamicLazySegTree(int n, Operator F, Apply G,\
    \ Merge H, Monoid IE1, OperatorMonoid IE2) {\r\n\treturn DynamicLazySegmentTree<Monoid,\
    \ OperatorMonoid, Operator, Apply, Merge >(n, F, G, H, IE1, IE2);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic_lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-04-25 23:33:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/DSL_2_G.test.cpp
documentation_of: data-structure/dynamic_lazy_segment_tree.cpp
layout: document
title: Dynamic Lazy Segment Tree
---

## 説明
必要な場所だけ作るようにした Lazy Segment Tree。

## 操作
### makeDynamicLazySegTree(n, F, G, H, IE1, IE2)
要素数 $n$ 、$F$ の単位元 $IE1$ で初期化された遅延セグメント木を構築する。

$F$ は $2$ つの区間の要素をマージする二項演算、$G$ は要素に対し作用素を適用する二項演算、$H$ は作用素同士をマージする二項演算(第一引数が後に追加する作用素)を指定する。

$G$ の第三引数には区間の幅が代入される。

$IE2$ は作用素の単位元である。
### get(l, r)
区間 $[l,r)$ に対して二項演算した結果を返す。
### set(l, r, x)
区間 $[l,r)$ に対して $x$ を作用させる。
### max_right(isOK, l)
$[l,r)$ が $isOK$ を満たす最大の $r$ を返す。