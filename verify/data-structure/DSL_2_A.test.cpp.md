---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segment_tree.cpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"verify/data-structure/DSL_2_A.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\r\n#include\
    \ <bits/stdc++.h>\r\n#line 3 \"data-structure/segment_tree.cpp\"\n\r\n/**\r\n\
    \ * @title Segment Tree\r\n */\r\n\r\ntemplate <class Monoid, class MonoidOp>\r\
    \nstruct SegmentTree {\r\n\tstd::vector<Monoid> dat;\r\n\r\n\tconst MonoidOp F;\r\
    \n\tconst Monoid E;\r\n\tconst int sz;\r\n\r\n\t// \u5358\u4F4D\u5143\u3067\u521D\
    \u671F\u5316\u3055\u308C\u305F\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(N)\r\n\t\
    SegmentTree(int n, MonoidOp F, Monoid E) : F(F), E(E), sz(n) { dat.assign(sz *\
    \ 2 + 1, E); }\r\n\r\n\t// vector\u3092\u57FA\u306B\u69CB\u7BC9 O(N)\r\n\tSegmentTree(const\
    \ std::vector<Monoid>& vec, MonoidOp F, Monoid E) : F(F), E(E), sz(vec.size())\
    \ {\r\n\t\tdat.assign(sz * 2 + 1, E);\r\n\t\tfor (int i = 0; i < sz; i++) dat[i\
    \ + sz] = vec[i];\r\n\t\tfor (int i = sz - 1; i > 0; i--) dat[i] = F(dat[i <<\
    \ 1 | 0], dat[i << 1 | 1]);\r\n\t}\r\n\r\n\tint size() { return sz; }\r\n\r\n\t\
    const Monoid& operator[] (int idx) { return dat[idx + sz]; }\r\n\r\n\t// fold(l,l+1,...,r-1)\
    \ \u3092\u8FD4\u3059\r\n\tMonoid get(int l, int r) {\r\n\t\tl += sz; r += sz;\r\
    \n\t\tMonoid lm(E), rm(E);\r\n\t\twhile (l < r) {\r\n\t\t\tif (l & 1)lm = F(lm,\
    \ dat[l++]);\r\n\t\t\tif (r & 1)rm = F(dat[--r], rm);\r\n\t\t\tl >>= 1; r >>=\
    \ 1;\r\n\t\t}\r\n\t\treturn F(lm, rm);\r\n\t}\r\n\r\n\tvoid set(int idx, Monoid\
    \ x) {\r\n\t\tidx += sz; dat[idx] = x;\r\n\t\twhile (idx > 1) {\r\n\t\t\tidx >>=\
    \ 1;\r\n\t\t\tdat[idx] = F(dat[idx << 1 | 0], dat[idx << 1 | 1]);\r\n\t\t}\r\n\
    \t}\r\n\r\n\ttemplate<class DetermineFunc>\r\n\tint internal_search(Monoid sum,\
    \ int i, DetermineFunc isOK) {\r\n\t\twhile (i < sz) {\r\n\t\t\tMonoid tmp = F(sum,\
    \ dat[i << 1]);\r\n\t\t\tif (isOK(tmp)) i = i << 1;\r\n\t\t\telse sum = tmp, i\
    \ = (i << 1) | 1;\r\n\t\t}\r\n\t\treturn i - sz;\r\n\t}\r\n\r\n\t// isOK(fold(l,l+1,...,r-1,r))\
    \ == 1 \u3068\u306A\u308B\u6700\u5C0F\u306Er\u3092\u6C42\u3081\u308B\r\n\ttemplate<class\
    \ DetermineFunc>\r\n\tint search_r(DetermineFunc isOK, int l = 0) {\r\n\t\tl +=\
    \ sz;\r\n\t\tint r = sz * 2, tmp = 0;\r\n\t\tMonoid sum = E;\r\n\t\tfor (int r_\
    \ = r; l < r_; r_ >>= 1, l >>= 1, tmp++) {\r\n\t\t\tif (l & 1) {\r\n\t\t\t\tif\
    \ (isOK(F(sum, dat[l])))return internal_search(sum, l, isOK);\r\n\t\t\t\tsum =\
    \ F(sum, dat[l]);\r\n\t\t\t\tl++;\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (tmp -= 1; tmp\
    \ >= 0; tmp--) {\r\n\t\t\tint r_ = r >> tmp;\r\n\t\t\tif (r_ & 1) {\r\n\t\t\t\t\
    r_--;\r\n\t\t\t\tif (isOK(F(sum, dat[r_])))return internal_search(sum, r_, isOK);\r\
    \n\t\t\t\tsum = F(sum, dat[r_]);\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn -1;\r\n\t}\r\
    \n\r\n\tvoid dump() {\r\n\t\tfor (int i = 0; i < dat.size(); i++) cout << dat[i]\
    \ << (i != dat.size() ? \" \" : \"\\n\");\r\n\t}\r\n};\r\n\r\ntemplate<class Monoid,\
    \ class MonoidOp>\r\nSegmentTree<Monoid, MonoidOp> makeSegTree(int n, MonoidOp\
    \ F, Monoid E) {\r\n\treturn SegmentTree<Monoid, MonoidOp>(n, F, E);\r\n}\r\n\r\
    \ntemplate<class Monoid, class MonoidOp>\r\nSegmentTree<Monoid, MonoidOp> makeSegTree(const\
    \ std::vector<Monoid>& vec, MonoidOp F, Monoid E) {\r\n\treturn SegmentTree<Monoid,\
    \ MonoidOp>(vec, F, E);\r\n}\r\n#line 4 \"verify/data-structure/DSL_2_A.test.cpp\"\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint N,\
    \ Q;\r\n\tcin >> N >> Q;\r\n\tll INF = (1LL << 31LL) - 1LL;\r\n\tauto ST = makeSegTree(vector(N,\
    \ INF), [](ll& l, ll& r) {return min(l, r); }, INF);\r\n\tfor (int i = 0; i <\
    \ Q; i++) {\r\n\t\tll c, x, y;\r\n\t\tcin >> c >> x >> y;\r\n\t\tif (c == 0) ST.set(x,\
    \ y);\r\n\t\tif (c == 1)cout << ST.get(x, y + 1) << endl;\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \r\n#include <bits/stdc++.h>\r\n#include \"data-structure/segment_tree.cpp\"\r\
    \nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tint N,\
    \ Q;\r\n\tcin >> N >> Q;\r\n\tll INF = (1LL << 31LL) - 1LL;\r\n\tauto ST = makeSegTree(vector(N,\
    \ INF), [](ll& l, ll& r) {return min(l, r); }, INF);\r\n\tfor (int i = 0; i <\
    \ Q; i++) {\r\n\t\tll c, x, y;\r\n\t\tcin >> c >> x >> y;\r\n\t\tif (c == 0) ST.set(x,\
    \ y);\r\n\t\tif (c == 1)cout << ST.get(x, y + 1) << endl;\r\n\t}\r\n}"
  dependsOn:
  - data-structure/segment_tree.cpp
  isVerificationFile: true
  path: verify/data-structure/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-01-24 02:08:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/data-structure/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/DSL_2_A.test.cpp
- /verify/verify/data-structure/DSL_2_A.test.cpp.html
title: verify/data-structure/DSL_2_A.test.cpp
---
