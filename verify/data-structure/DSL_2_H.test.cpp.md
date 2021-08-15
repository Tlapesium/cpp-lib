---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/lazy_segment_tree.cpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
  bundledCode: "#line 1 \"verify/data-structure/DSL_2_H.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\r\n#include\
    \ <bits/stdc++.h>\r\n#line 2 \"data-structure/lazy_segment_tree.cpp\"\n\r\ntemplate\
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
    \ dat[i << 1 | 1]);\r\n\t}\r\n\r\n\tint size() { return sz; }\r\n\tMonoid operator[]\
    \ (int idx) { return get(idx, idx + 1); }\r\n\r\n\r\n\t// x \u3092\u4F1D\u642C\
    \u3055\u305B\u308B\r\n\tvoid propagate(int x) {\r\n\t\tif (x < sz) {\r\n\t\t\t\
    lazy[x << 1 | 0] = merge(lazy[x], lazy[x << 1 | 0]);\r\n\t\t\tlazy[x << 1 | 1]\
    \ = merge(lazy[x], lazy[x << 1 | 1]);\r\n\t\t}\r\n\t\tdat[x << 1 | 0] = apply(dat[x\
    \ << 1 | 0], lazy[x]);\r\n\t\tdat[x << 1 | 1] = apply(dat[x << 1 | 1], lazy[x]);\r\
    \n\t\tlazy[x] = OpIE;\r\n\t}\r\n\r\n\t// x \u3092\u518D\u8A08\u7B97\u3059\u308B\
    \r\n\tvoid update(int x) {\r\n\t\tdat[x] = op(dat[x << 1 | 0], dat[x << 1 | 1]);\r\
    \n\t}\r\n\r\n\t// \u533A\u9593 [l,r) \u306B x \u3092\u4F5C\u7528\r\n\tvoid set(int\
    \ l, int r, OperatorMonoid x) {\r\n\t\tif (l >= r)return;\r\n\t\tl += sz; r +=\
    \ sz;\r\n\r\n\t\tfor (int i = height; i >= 1; i--) {\r\n\t\t\tif (((l >> i) <<\
    \ i) != l) propagate(l >> i);\r\n\t\t\tif (((r >> i) << i) != r) propagate((r\
    \ - 1) >> i);\r\n\t\t}\r\n\r\n\t\tfor (int l2 = l, r2 = r; l2 < r2; l2 >>= 1,\
    \ r2 >>= 1) {\r\n\t\t\tif (l2 & 1) {\r\n\t\t\t\tif (l2 < sz)lazy[l2] = merge(x,\
    \ lazy[l2]);\r\n\t\t\t\tdat[l2] = apply(dat[l2], x);\r\n\t\t\t\tl2++;\r\n\t\t\t\
    }\r\n\t\t\tif (r2 & 1) {\r\n\t\t\t\tr2--;\r\n\t\t\t\tif (r2 < sz)lazy[r2] = merge(x,\
    \ lazy[r2]);\r\n\t\t\t\tdat[r2] = apply(dat[r2], x);\r\n\t\t\t}\r\n\t\t}\r\n\r\
    \n\t\tfor (int i = 1; i <= height; i++) {\r\n\t\t\tif (((l >> i) << i) != l) update(l\
    \ >> i);\r\n\t\t\tif (((r >> i) << i) != r) update((r - 1) >> i);\r\n\t\t}\r\n\
    \t}\r\n\r\n\t// \u533A\u9593 [l,r) \u306E\u7A4D\u3092\u53D6\u5F97\r\n\tMonoid\
    \ get(int l, int r) {\r\n\t\tl += sz; r += sz;\r\n\r\n\t\tfor (int i = height;\
    \ i >= 1; i--) {\r\n\t\t\tif (((l >> i) << i) != l) propagate(l >> i);\r\n\t\t\
    \tif (((r >> i) << i) != r) propagate(r >> i);\r\n\t\t}\r\n\r\n\t\tMonoid lm(IE),\
    \ rm(IE);\r\n\t\tfor (int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {\r\n\t\
    \t\tif (l2 & 1) lm = op(lm, dat[l2++]);\r\n\t\t\tif (r2 & 1) rm = op(dat[--r2],\
    \ rm);\r\n\t\t}\r\n\t\treturn op(lm, rm);\r\n\t}\r\n\r\n\t// isOK(fold(l,l+1,...,r-1,r))\
    \ == 1 \u3068\u306A\u308B\u6700\u5C0F\u306Er\u3092\u6C42\u3081\u308B\r\n\ttemplate<class\
    \ DetermineFunc>\r\n\tint search_r(DetermineFunc isOK, int l = 0) {\r\n\t\tif\
    \ (l == sz)return -1;\r\n\t\tl += sz;\r\n\t\tfor (int i = height; i >= 1; i--)\
    \ propagate(l >> i);\r\n\t\tMonoid sum = IE;\r\n\t\tdo {\r\n\t\t\twhile (l % 2\
    \ == 0)l >>= 1;\r\n\t\t\tif (isOK(op(sum, dat[l]))) {\r\n\t\t\t\twhile (l < sz)\
    \ {\r\n\t\t\t\t\tpropagate(l);\r\n\t\t\t\t\tl = 2 * l;\r\n\t\t\t\t\tif (!isOK(op(sum,\
    \ dat[l]))) {\r\n\t\t\t\t\t\tsum = op(sum, dat[l]);\r\n\t\t\t\t\t\tl++;\r\n\t\t\
    \t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\treturn l - sz;\r\n\t\t\t}\r\n\t\t\tsum = op(sum,\
    \ dat[l]);\r\n\t\t\tl++;\r\n\t\t} while ((l & -l) != l);\r\n\t\treturn -1;\r\n\
    \t}\r\n\r\n\tvoid dump() {\r\n\t\tfor (int i = 0; i < sz; i++)std::cout << get(i,\
    \ i + 1) << (i == sz ? \"\\n\" : \" \");\r\n\t}\r\n\r\n};\r\n\r\ntemplate <class\
    \ Monoid, class OperatorMonoid, class Operator, class Apply, class Merge >\r\n\
    LazySegmentTree<Monoid, OperatorMonoid, Operator, Apply, Merge > makeLazySegTree(int\
    \ n, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) {\r\n\treturn\
    \ LazySegmentTree<Monoid, OperatorMonoid, Operator, Apply, Merge >(n, F, G, H,\
    \ IE1, IE2);\r\n}\r\n\r\ntemplate <class Monoid, class OperatorMonoid, class Operator,\
    \ class Apply, class Merge >\r\nLazySegmentTree<Monoid, OperatorMonoid, Operator,\
    \ Apply, Merge > makeLazySegTree(const std::vector<Monoid>& vec, Operator F, Apply\
    \ G, Merge H, Monoid IE1, OperatorMonoid IE2) {\r\n\treturn LazySegmentTree<Monoid,\
    \ OperatorMonoid, Operator, Apply, Merge >(vec, F, G, H, IE1, IE2);\r\n}\r\n#line\
    \ 4 \"verify/data-structure/DSL_2_H.test.cpp\"\nusing namespace std;\r\ntypedef\
    \ long long ll;\r\n\r\nint main() {\r\n\tauto F = [](int l, int r) {return min(l,\
    \ r); };\r\n\tauto G = [](int m, int op) {return m + op; };\r\n\tauto H = [](int\
    \ a, int b) {return a + b; };\r\n\tint N, Q;\r\n\tcin >> N >> Q;\r\n\r\n\tvector<int>\
    \ v(N, 0);\r\n\tauto LST = makeLazySegTree(v, F, G, H, INF, 0);\r\n\r\n\tfor (int\
    \ i = 0; i < Q; i++) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {\r\n\
    \t\t\tint s, t, x;\r\n\t\t\tcin >> s >> t >> x;\r\n\t\t\tLST.set(s, t + 1, x);\r\
    \n\t\t}\r\n\t\telse {\r\n\t\t\tint s, t;\r\n\t\t\tcin >> s >> t;\r\n\t\t\tcout\
    \ << LST.get(s, t + 1) << endl;\r\n\t\t}\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \r\n#include <bits/stdc++.h>\r\n#include \"data-structure/lazy_segment_tree.cpp\"\
    \r\nusing namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tauto\
    \ F = [](int l, int r) {return min(l, r); };\r\n\tauto G = [](int m, int op) {return\
    \ m + op; };\r\n\tauto H = [](int a, int b) {return a + b; };\r\n\tint N, Q;\r\
    \n\tcin >> N >> Q;\r\n\r\n\tvector<int> v(N, 0);\r\n\tauto LST = makeLazySegTree(v,\
    \ F, G, H, INF, 0);\r\n\r\n\tfor (int i = 0; i < Q; i++) {\r\n\t\tint t;\r\n\t\
    \tcin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint s, t, x;\r\n\t\t\tcin >> s >> t\
    \ >> x;\r\n\t\t\tLST.set(s, t + 1, x);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tint s,\
    \ t;\r\n\t\t\tcin >> s >> t;\r\n\t\t\tcout << LST.get(s, t + 1) << endl;\r\n\t\
    \t}\r\n\t}\r\n}"
  dependsOn:
  - data-structure/lazy_segment_tree.cpp
  isVerificationFile: true
  path: verify/data-structure/DSL_2_H.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 07:12:47+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/data-structure/DSL_2_H.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/DSL_2_H.test.cpp
- /verify/verify/data-structure/DSL_2_H.test.cpp.html
title: verify/data-structure/DSL_2_H.test.cpp
---
