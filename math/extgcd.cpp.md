---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/crt.cpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/math/NTL_1_E.test.cpp
    title: verify/math/NTL_1_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/math/yuki187.test.cpp
    title: verify/math/yuki187.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/extgcd.cpp\"\n#include <utility>\r\n\r\nauto extGCD(long\
    \ long a, long long b) {\r\n\tlong long x = 1, y = 0, u = 0, v = 1;\r\n\twhile\
    \ (b != 0) {\r\n\t\tauto j = a % b, k = a / b;\r\n\t\tx -= k * u; y -= k * v;\r\
    \n\t\tstd::swap(x, u); std::swap(y, v);\r\n\t\ta = b; b = j;\r\n\t}\r\n\treturn\
    \ std::make_pair(x, y);\r\n}\n"
  code: "#pragma once\r\n#include <utility>\r\n\r\nauto extGCD(long long a, long long\
    \ b) {\r\n\tlong long x = 1, y = 0, u = 0, v = 1;\r\n\twhile (b != 0) {\r\n\t\t\
    auto j = a % b, k = a / b;\r\n\t\tx -= k * u; y -= k * v;\r\n\t\tstd::swap(x,\
    \ u); std::swap(y, v);\r\n\t\ta = b; b = j;\r\n\t}\r\n\treturn std::make_pair(x,\
    \ y);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy:
  - math/crt.cpp
  timestamp: '2021-03-09 01:15:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/NTL_1_E.test.cpp
  - verify/math/yuki187.test.cpp
documentation_of: math/extgcd.cpp
layout: document
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---
$ax + by = \mathrm{gcd}(a,b)$ を満たす整数 $(x,y)$ を求める。

$\mathrm{abs}(x) + \mathrm{abs}(y)$ が最小となるものを返し、複数存在する場合は $x \leq y$ であるようなものを返す。