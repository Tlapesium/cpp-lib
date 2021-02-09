---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/DSL_2_F.test.cpp
    title: verify/data-structure/DSL_2_F.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/lazy_segment_tree.cpp\"\n#include <vector>\r\
    \n#include <iostream>\r\n\r\ntemplate <class Monoid, class OperatorMonoid, class\
    \ Operator, class Apply, class Merge >\r\nstruct LazySegmentTree {\r\n\tstd::vector<Monoid>\
    \ dat;\r\n\tstd::vector<OperatorMonoid> lazy;\r\n\r\n\tconst Operator op;\r\n\t\
    const Apply apply;\r\n\tconst Merge merge;\r\n\tconst Monoid IE;\r\n\tconst OperatorMonoid\
    \ OpIE;\r\n\tconst int sz;\r\n\tint height = 0;\r\n\r\n\r\n\t// \u5358\u4F4D\u5143\
    \u3067\u521D\u671F\u5316\u3055\u308C\u305F\u9045\u5EF6\u30BB\u30B0\u6728\u3092\
    \u69CB\u7BC9 O(N)\r\n\tLazySegmentTree(int n, Operator F, Apply G, Merge H, Monoid\
    \ IE1, OperatorMonoid IE2) : op(F), apply(G), merge(H), IE(IE1), OpIE(IE2), sz(n)\
    \ {\r\n\t\tdat.assign(sz * 2 + 1, IE);\r\n\t\tlazy.assign(sz * 2 + 1, OpIE);\r\
    \n\t\twhile ((1 << height) <= sz)height++;\r\n\t}\r\n\r\n\t// vector\u3092\u57FA\
    \u306B\u69CB\u7BC9 O(N)\r\n\tLazySegmentTree(const std::vector<Monoid>& vec, Operator\
    \ F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) : op(F), apply(G), merge(H),\
    \ IE(IE1), OpIE(IE2), sz(vec.size()) {\r\n\t\tdat.assign(sz * 2 + 1, IE);\r\n\t\
    \tlazy.assign(sz * 2 + 1, OpIE);\r\n\t\twhile ((1 << height) <= sz)height++;\r\
    \n\t\tfor (int i = 0; i < sz; i++) dat[i + sz] = vec[i];\r\n\t\tfor (int i = sz\
    \ - 1; i > 0; i--) dat[i] = op(dat[i << 1 | 0], dat[i << 1 | 1]);\r\n\t}\r\n\r\
    \n\tint size() { return sz; }\r\n\tconst Monoid& operator[] (int idx) { return\
    \ get(idx, idx + 1); }\r\n\r\n\r\n\t// x \u3092\u4F1D\u642C\u3055\u305B\u308B\r\
    \n\tvoid propagate(int x) {\r\n\t\tif (x < sz) {\r\n\t\t\tlazy[x << 1 | 0] = merge(lazy[x],\
    \ lazy[x << 1 | 0]);\r\n\t\t\tlazy[x << 1 | 1] = merge(lazy[x], lazy[x << 1 |\
    \ 1]);\r\n\t\t}\r\n\t\tdat[x << 1 | 0] = apply(dat[x << 1 | 0], lazy[x]);\r\n\t\
    \tdat[x << 1 | 1] = apply(dat[x << 1 | 1], lazy[x]);\r\n\t\tlazy[x] = OpIE;\r\n\
    \t}\r\n\r\n\t// x \u3092\u518D\u8A08\u7B97\u3059\u308B\r\n\tvoid update(int x)\
    \ {\r\n\t\tdat[x] = op(dat[x << 1 | 0], dat[x << 1 | 1]);\r\n\t}\r\n\r\n\t// \u533A\
    \u9593 [l,r) \u306B x \u3092\u4F5C\u7528\r\n\tvoid set(int l, int r, OperatorMonoid\
    \ x) {\r\n\t\tif (l >= r)return;\r\n\t\tl += sz; r += sz;\r\n\r\n\t\tfor (int\
    \ i = height; i >= 1; i--) {\r\n\t\t\tif (((l >> i) << i) != l) propagate(l >>\
    \ i);\r\n\t\t\tif (((r >> i) << i) != r) propagate((r - 1) >> i);\r\n\t\t}\r\n\
    \r\n\t\tfor (int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {\r\n\t\t\tif (l2\
    \ & 1) {\r\n\t\t\t\tif (l2 < sz)lazy[l2] = merge(x, lazy[l2]);\r\n\t\t\t\tdat[l2]\
    \ = apply(dat[l2], x);\r\n\t\t\t\tl2++;\r\n\t\t\t}\r\n\t\t\tif (r2 & 1) {\r\n\t\
    \t\t\tr2--;\r\n\t\t\t\tif (r2 < sz)lazy[r2] = merge(x, lazy[r2]);\r\n\t\t\t\t\
    dat[r2] = apply(dat[r2], x);\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\tfor (int i = 1; i\
    \ <= height; i++) {\r\n\t\t\tif (((l >> i) << i) != l) update(l >> i);\r\n\t\t\
    \tif (((r >> i) << i) != r) update((r - 1) >> i);\r\n\t\t}\r\n\t}\r\n\r\n\t//\
    \ \u533A\u9593 [l,r) \u306E\u7A4D\u3092\u53D6\u5F97\r\n\tMonoid get(int l, int\
    \ r) {\r\n\t\tl += sz; r += sz;\r\n\r\n\t\tfor (int i = height; i >= 1; i--) {\r\
    \n\t\t\tif (((l >> i) << i) != l) propagate(l >> i);\r\n\t\t\tif (((r >> i) <<\
    \ i) != r) propagate(r >> i);\r\n\t\t}\r\n\r\n\t\tMonoid lm(IE), rm(IE);\r\n\t\
    \tfor (int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {\r\n\t\t\tif (l2 & 1)\
    \ lm = op(lm, dat[l2++]);\r\n\t\t\tif (r2 & 1) rm = op(dat[--r2], rm);\r\n\t\t\
    }\r\n\t\treturn op(lm, rm);\r\n\t}\r\n\r\n\tvoid dump() {\r\n\t\tfor (int i =\
    \ 0; i < sz; i++)std::cout << get(i, i + 1) << (i == sz ? \"\\n\" : \" \");\r\n\
    \t}\r\n\r\n\t// TODO: 2\u5206\u63A2\u7D22\u3092\u5B9F\u88C5\u3059\u308B\r\n};\r\
    \n\r\n\r\ntemplate <class Monoid, class OperatorMonoid, class Operator, class\
    \ Apply, class Merge >\r\nLazySegmentTree<Monoid, OperatorMonoid, Operator, Apply,\
    \ Merge > makeLazySegTree(int n, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid\
    \ IE2) {\r\n\treturn LazySegmentTree<Monoid, OperatorMonoid, Operator, Apply,\
    \ Merge >(n, F, G, H, IE1, IE2);\r\n}\r\n\r\ntemplate <class Monoid, class OperatorMonoid,\
    \ class Operator, class Apply, class Merge >\r\nLazySegmentTree<Monoid, OperatorMonoid,\
    \ Operator, Apply, Merge > makeLazySegTree(const std::vector<Monoid>& vec, Operator\
    \ F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) {\r\n\treturn LazySegmentTree<Monoid,\
    \ OperatorMonoid, Operator, Apply, Merge >(vec, F, G, H, IE1, IE2);\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <iostream>\r\n\r\ntemplate\
    \ <class Monoid, class OperatorMonoid, class Operator, class Apply, class Merge\
    \ >\r\nstruct LazySegmentTree {\r\n\tstd::vector<Monoid> dat;\r\n\tstd::vector<OperatorMonoid>\
    \ lazy;\r\n\r\n\tconst Operator op;\r\n\tconst Apply apply;\r\n\tconst Merge merge;\r\
    \n\tconst Monoid IE;\r\n\tconst OperatorMonoid OpIE;\r\n\tconst int sz;\r\n\t\
    int height = 0;\r\n\r\n\r\n\t// \u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\u3055\
    \u308C\u305F\u9045\u5EF6\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(N)\r\n\tLazySegmentTree(int\
    \ n, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) : op(F), apply(G),\
    \ merge(H), IE(IE1), OpIE(IE2), sz(n) {\r\n\t\tdat.assign(sz * 2 + 1, IE);\r\n\
    \t\tlazy.assign(sz * 2 + 1, OpIE);\r\n\t\twhile ((1 << height) <= sz)height++;\r\
    \n\t}\r\n\r\n\t// vector\u3092\u57FA\u306B\u69CB\u7BC9 O(N)\r\n\tLazySegmentTree(const\
    \ std::vector<Monoid>& vec, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid\
    \ IE2) : op(F), apply(G), merge(H), IE(IE1), OpIE(IE2), sz(vec.size()) {\r\n\t\
    \tdat.assign(sz * 2 + 1, IE);\r\n\t\tlazy.assign(sz * 2 + 1, OpIE);\r\n\t\twhile\
    \ ((1 << height) <= sz)height++;\r\n\t\tfor (int i = 0; i < sz; i++) dat[i + sz]\
    \ = vec[i];\r\n\t\tfor (int i = sz - 1; i > 0; i--) dat[i] = op(dat[i << 1 | 0],\
    \ dat[i << 1 | 1]);\r\n\t}\r\n\r\n\tint size() { return sz; }\r\n\tconst Monoid&\
    \ operator[] (int idx) { return get(idx, idx + 1); }\r\n\r\n\r\n\t// x \u3092\u4F1D\
    \u642C\u3055\u305B\u308B\r\n\tvoid propagate(int x) {\r\n\t\tif (x < sz) {\r\n\
    \t\t\tlazy[x << 1 | 0] = merge(lazy[x], lazy[x << 1 | 0]);\r\n\t\t\tlazy[x <<\
    \ 1 | 1] = merge(lazy[x], lazy[x << 1 | 1]);\r\n\t\t}\r\n\t\tdat[x << 1 | 0] =\
    \ apply(dat[x << 1 | 0], lazy[x]);\r\n\t\tdat[x << 1 | 1] = apply(dat[x << 1 |\
    \ 1], lazy[x]);\r\n\t\tlazy[x] = OpIE;\r\n\t}\r\n\r\n\t// x \u3092\u518D\u8A08\
    \u7B97\u3059\u308B\r\n\tvoid update(int x) {\r\n\t\tdat[x] = op(dat[x << 1 | 0],\
    \ dat[x << 1 | 1]);\r\n\t}\r\n\r\n\t// \u533A\u9593 [l,r) \u306B x \u3092\u4F5C\
    \u7528\r\n\tvoid set(int l, int r, OperatorMonoid x) {\r\n\t\tif (l >= r)return;\r\
    \n\t\tl += sz; r += sz;\r\n\r\n\t\tfor (int i = height; i >= 1; i--) {\r\n\t\t\
    \tif (((l >> i) << i) != l) propagate(l >> i);\r\n\t\t\tif (((r >> i) << i) !=\
    \ r) propagate((r - 1) >> i);\r\n\t\t}\r\n\r\n\t\tfor (int l2 = l, r2 = r; l2\
    \ < r2; l2 >>= 1, r2 >>= 1) {\r\n\t\t\tif (l2 & 1) {\r\n\t\t\t\tif (l2 < sz)lazy[l2]\
    \ = merge(x, lazy[l2]);\r\n\t\t\t\tdat[l2] = apply(dat[l2], x);\r\n\t\t\t\tl2++;\r\
    \n\t\t\t}\r\n\t\t\tif (r2 & 1) {\r\n\t\t\t\tr2--;\r\n\t\t\t\tif (r2 < sz)lazy[r2]\
    \ = merge(x, lazy[r2]);\r\n\t\t\t\tdat[r2] = apply(dat[r2], x);\r\n\t\t\t}\r\n\
    \t\t}\r\n\r\n\t\tfor (int i = 1; i <= height; i++) {\r\n\t\t\tif (((l >> i) <<\
    \ i) != l) update(l >> i);\r\n\t\t\tif (((r >> i) << i) != r) update((r - 1) >>\
    \ i);\r\n\t\t}\r\n\t}\r\n\r\n\t// \u533A\u9593 [l,r) \u306E\u7A4D\u3092\u53D6\u5F97\
    \r\n\tMonoid get(int l, int r) {\r\n\t\tl += sz; r += sz;\r\n\r\n\t\tfor (int\
    \ i = height; i >= 1; i--) {\r\n\t\t\tif (((l >> i) << i) != l) propagate(l >>\
    \ i);\r\n\t\t\tif (((r >> i) << i) != r) propagate(r >> i);\r\n\t\t}\r\n\r\n\t\
    \tMonoid lm(IE), rm(IE);\r\n\t\tfor (int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2\
    \ >>= 1) {\r\n\t\t\tif (l2 & 1) lm = op(lm, dat[l2++]);\r\n\t\t\tif (r2 & 1) rm\
    \ = op(dat[--r2], rm);\r\n\t\t}\r\n\t\treturn op(lm, rm);\r\n\t}\r\n\r\n\tvoid\
    \ dump() {\r\n\t\tfor (int i = 0; i < sz; i++)std::cout << get(i, i + 1) << (i\
    \ == sz ? \"\\n\" : \" \");\r\n\t}\r\n\r\n\t// TODO: 2\u5206\u63A2\u7D22\u3092\
    \u5B9F\u88C5\u3059\u308B\r\n};\r\n\r\n\r\ntemplate <class Monoid, class OperatorMonoid,\
    \ class Operator, class Apply, class Merge >\r\nLazySegmentTree<Monoid, OperatorMonoid,\
    \ Operator, Apply, Merge > makeLazySegTree(int n, Operator F, Apply G, Merge H,\
    \ Monoid IE1, OperatorMonoid IE2) {\r\n\treturn LazySegmentTree<Monoid, OperatorMonoid,\
    \ Operator, Apply, Merge >(n, F, G, H, IE1, IE2);\r\n}\r\n\r\ntemplate <class\
    \ Monoid, class OperatorMonoid, class Operator, class Apply, class Merge >\r\n\
    LazySegmentTree<Monoid, OperatorMonoid, Operator, Apply, Merge > makeLazySegTree(const\
    \ std::vector<Monoid>& vec, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid\
    \ IE2) {\r\n\treturn LazySegmentTree<Monoid, OperatorMonoid, Operator, Apply,\
    \ Merge >(vec, F, G, H, IE1, IE2);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-02-09 09:18:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/DSL_2_F.test.cpp
documentation_of: data-structure/lazy_segment_tree.cpp
layout: document
title: Segment Tree
---

## 説明
区間更新・区間取得が高速にできるデータ構造。

## 操作
### makeLazySegTree(int n, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2)
要素数 $n$ 、$F$ の単位元 $IE1$ で初期化された遅延セグメント木を構築する。
$F$ は $2$ つの区間の要素をマージする二項演算、$G$ は要素に対し作用素を適用する二項演算、$H$ は作用素同士をマージする二項演算(第一引数が後に追加する作用素)を指定する。
$IE2$ は作用素の単位元である。
### makeLazySegTree(std::vector<Monoid>& vec, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2)
$vec$ を元に遅延セグメント木を構築する。
### get(int l, int r)
区間 $[l,r)$ に対して二項演算した結果を返す。
### set(int l, int r, OperatorMonoid x)
区間 $[l,r)$ に対して $x$ を作用させる。