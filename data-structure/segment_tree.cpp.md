---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/DSL_2_A.test.cpp
    title: verify/data-structure/DSL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segment_tree.cpp\"\n\r\ntemplate <class Monoid,\
    \ class Operator>\r\nstruct SegmentTree {\r\n\tstd::vector<Monoid> dat;\r\n\r\n\
    \tconst Operator op;\r\n\tconst Monoid IE;\r\n\tconst int sz;\r\n\r\n\t// \u5358\
    \u4F4D\u5143\u3067\u521D\u671F\u5316\u3055\u308C\u305F\u30BB\u30B0\u6728\u3092\
    \u69CB\u7BC9 O(N)\r\n\tSegmentTree(int n, Operator F, Monoid IE) : op(F), IE(IE),\
    \ sz(n) { dat.assign(sz * 2 + 1, IE); }\r\n\r\n\t// vector\u3092\u57FA\u306B\u69CB\
    \u7BC9 O(N)\r\n\tSegmentTree(const std::vector<Monoid>& vec, Operator F, Monoid\
    \ IE) : op(F), IE(IE), sz(vec.size()) {\r\n\t\tdat.assign(sz * 2 + 1, IE);\r\n\
    \t\tfor (int i = 0; i < sz; i++) dat[i + sz] = vec[i];\r\n\t\tfor (int i = sz\
    \ - 1; i > 0; i--) dat[i] = op(dat[i << 1 | 0], dat[i << 1 | 1]);\r\n\t}\r\n\r\
    \n\tint size() { return sz; }\r\n\tMonoid operator[] (int idx) { return dat[idx\
    \ + sz]; }\r\n\r\n\t// \u533A\u9593 [l,r) \u306E\u7A4D\u3092\u53D6\u5F97\r\n\t\
    Monoid get(int l, int r) {\r\n\t\tl += sz; r += sz;\r\n\t\tMonoid lm(IE), rm(IE);\r\
    \n\t\twhile (l < r) {\r\n\t\t\tif (l & 1)lm = op(lm, dat[l++]);\r\n\t\t\tif (r\
    \ & 1)rm = op(dat[--r], rm);\r\n\t\t\tl >>= 1; r >>= 1;\r\n\t\t}\r\n\t\treturn\
    \ op(lm, rm);\r\n\t}\r\n\r\n\t// \u8981\u7D20 idx \u3092 x \u306B\u66F4\u65B0\r\
    \n\tvoid set(int idx, Monoid x) {\r\n\t\tidx += sz; dat[idx] = x;\r\n\t\twhile\
    \ (idx > 1) {\r\n\t\t\tidx >>= 1;\r\n\t\t\tdat[idx] = op(dat[idx << 1 | 0], dat[idx\
    \ << 1 | 1]);\r\n\t\t}\r\n\t}\r\n\r\n\t// isOK(fold(l,l+1,...,r-1,r)) == 1 \u3068\
    \u306A\u308B\u6700\u5C0F\u306Er\u3092\u6C42\u3081\u308B\r\n\ttemplate<class DetermineFunc>\r\
    \n\tint search_r(DetermineFunc isOK, int l = 0) {\r\n\t\tif (l == sz)return -1;\r\
    \n\t\tl += sz;\r\n\t\tMonoid sum = IE;\r\n\t\tdo {\r\n\t\t\twhile (l % 2 == 0)l\
    \ >>= 1;\r\n\t\t\tif (isOK(op(sum, dat[l]))) {\r\n\t\t\t\twhile (l < sz) {\r\n\
    \t\t\t\t\tl = 2 * l;\r\n\t\t\t\t\tif (!isOK(op(sum, dat[l]))) {\r\n\t\t\t\t\t\t\
    sum = op(sum, dat[l]);\r\n\t\t\t\t\t\tl++;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\
    \t\treturn l - sz;\r\n\t\t\t}\r\n\t\t\tsum = op(sum, dat[l]);\r\n\t\t\tl++;\r\n\
    \t\t} while ((l & -l) != l);\r\n\t\treturn -1;\r\n\t}\r\n\r\n\tvoid dump() {\r\
    \n\t\tfor (int i = 0; i < sz; i++) std::cout << get(i, i + 1) << (i != sz ? \"\
    \ \" : \"\\n\");\r\n\t}\r\n};\r\n\r\ntemplate<class Monoid, class Operator>\r\n\
    SegmentTree<Monoid, Operator> makeSegTree(int n, Operator F, Monoid IE) {\r\n\t\
    return SegmentTree<Monoid, Operator>(n, F, IE);\r\n}\r\n\r\ntemplate<class Monoid,\
    \ class Operator>\r\nSegmentTree<Monoid, Operator> makeSegTree(const std::vector<Monoid>&\
    \ vec, Operator F, Monoid IE) {\r\n\treturn SegmentTree<Monoid, Operator>(vec,\
    \ F, IE);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <class Monoid, class Operator>\r\nstruct SegmentTree\
    \ {\r\n\tstd::vector<Monoid> dat;\r\n\r\n\tconst Operator op;\r\n\tconst Monoid\
    \ IE;\r\n\tconst int sz;\r\n\r\n\t// \u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\
    \u3055\u308C\u305F\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(N)\r\n\tSegmentTree(int\
    \ n, Operator F, Monoid IE) : op(F), IE(IE), sz(n) { dat.assign(sz * 2 + 1, IE);\
    \ }\r\n\r\n\t// vector\u3092\u57FA\u306B\u69CB\u7BC9 O(N)\r\n\tSegmentTree(const\
    \ std::vector<Monoid>& vec, Operator F, Monoid IE) : op(F), IE(IE), sz(vec.size())\
    \ {\r\n\t\tdat.assign(sz * 2 + 1, IE);\r\n\t\tfor (int i = 0; i < sz; i++) dat[i\
    \ + sz] = vec[i];\r\n\t\tfor (int i = sz - 1; i > 0; i--) dat[i] = op(dat[i <<\
    \ 1 | 0], dat[i << 1 | 1]);\r\n\t}\r\n\r\n\tint size() { return sz; }\r\n\tMonoid\
    \ operator[] (int idx) { return dat[idx + sz]; }\r\n\r\n\t// \u533A\u9593 [l,r)\
    \ \u306E\u7A4D\u3092\u53D6\u5F97\r\n\tMonoid get(int l, int r) {\r\n\t\tl += sz;\
    \ r += sz;\r\n\t\tMonoid lm(IE), rm(IE);\r\n\t\twhile (l < r) {\r\n\t\t\tif (l\
    \ & 1)lm = op(lm, dat[l++]);\r\n\t\t\tif (r & 1)rm = op(dat[--r], rm);\r\n\t\t\
    \tl >>= 1; r >>= 1;\r\n\t\t}\r\n\t\treturn op(lm, rm);\r\n\t}\r\n\r\n\t// \u8981\
    \u7D20 idx \u3092 x \u306B\u66F4\u65B0\r\n\tvoid set(int idx, Monoid x) {\r\n\t\
    \tidx += sz; dat[idx] = x;\r\n\t\twhile (idx > 1) {\r\n\t\t\tidx >>= 1;\r\n\t\t\
    \tdat[idx] = op(dat[idx << 1 | 0], dat[idx << 1 | 1]);\r\n\t\t}\r\n\t}\r\n\r\n\
    \t// isOK(fold(l,l+1,...,r-1,r)) == 1 \u3068\u306A\u308B\u6700\u5C0F\u306Er\u3092\
    \u6C42\u3081\u308B\r\n\ttemplate<class DetermineFunc>\r\n\tint search_r(DetermineFunc\
    \ isOK, int l = 0) {\r\n\t\tif (l == sz)return -1;\r\n\t\tl += sz;\r\n\t\tMonoid\
    \ sum = IE;\r\n\t\tdo {\r\n\t\t\twhile (l % 2 == 0)l >>= 1;\r\n\t\t\tif (isOK(op(sum,\
    \ dat[l]))) {\r\n\t\t\t\twhile (l < sz) {\r\n\t\t\t\t\tl = 2 * l;\r\n\t\t\t\t\t\
    if (!isOK(op(sum, dat[l]))) {\r\n\t\t\t\t\t\tsum = op(sum, dat[l]);\r\n\t\t\t\t\
    \t\tl++;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\treturn l - sz;\r\n\t\t\t}\r\n\t\
    \t\tsum = op(sum, dat[l]);\r\n\t\t\tl++;\r\n\t\t} while ((l & -l) != l);\r\n\t\
    \treturn -1;\r\n\t}\r\n\r\n\tvoid dump() {\r\n\t\tfor (int i = 0; i < sz; i++)\
    \ std::cout << get(i, i + 1) << (i != sz ? \" \" : \"\\n\");\r\n\t}\r\n};\r\n\r\
    \ntemplate<class Monoid, class Operator>\r\nSegmentTree<Monoid, Operator> makeSegTree(int\
    \ n, Operator F, Monoid IE) {\r\n\treturn SegmentTree<Monoid, Operator>(n, F,\
    \ IE);\r\n}\r\n\r\ntemplate<class Monoid, class Operator>\r\nSegmentTree<Monoid,\
    \ Operator> makeSegTree(const std::vector<Monoid>& vec, Operator F, Monoid IE)\
    \ {\r\n\treturn SegmentTree<Monoid, Operator>(vec, F, IE);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment_tree.cpp
  requiredBy: []
  timestamp: '2021-04-04 19:47:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/DSL_2_A.test.cpp
documentation_of: data-structure/segment_tree.cpp
layout: document
title: Segment Tree
---

## 説明
一点更新・区間取得が高速にできるデータ構造。

## 操作
### makeSegTree(n, F, IE)
要素数 $n$ 、$F$ の単位元 $IE$ で初期化されたセグメント木を構築する。$F$ は $2$ つの区間をマージする二項演算を指定する。
### makeSegTree(vec, F, IE)
$vec$ を元にセグメント木を構築する。
### get(l, r)
区間 $[l,r)$ に対して二項演算した結果を返す。
### set(idx, x)
$idx$ 番目の要素を $x$ に更新する。
### search_r(isOK, l)
$[l,r]$ が $isOK$ を満たす最小の $r$ を返す。