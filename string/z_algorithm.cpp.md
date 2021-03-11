---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/string/z_algorithm.test.cpp
    title: verify/string/z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.cpp\"\n\r\nstd::vector<int> z_algorithm(const\
    \ std::string& S) {\r\n\tstd::vector<int> ret(S.size(), 0);\r\n\tret[0] = S.size();\r\
    \n\tint i = 1, j = 0;\r\n\twhile (i < S.size()) {\r\n\t\twhile (i + j < S.size()\
    \ && S[j] == S[i + j])j++;\r\n\t\tret[i] = j;\r\n\t\tif (j == 0) { i++; continue;\
    \ }\r\n\t\tint k = 1;\r\n\t\twhile (i + k < S.size() && k + ret[k] < j)ret[i +\
    \ k] = ret[k], k++;\r\n\t\ti += k; j -= k;\r\n\t}\r\n\treturn ret;\r\n}\n"
  code: "#pragma once\r\n\r\nstd::vector<int> z_algorithm(const std::string& S) {\r\
    \n\tstd::vector<int> ret(S.size(), 0);\r\n\tret[0] = S.size();\r\n\tint i = 1,\
    \ j = 0;\r\n\twhile (i < S.size()) {\r\n\t\twhile (i + j < S.size() && S[j] ==\
    \ S[i + j])j++;\r\n\t\tret[i] = j;\r\n\t\tif (j == 0) { i++; continue; }\r\n\t\
    \tint k = 1;\r\n\t\twhile (i + k < S.size() && k + ret[k] < j)ret[i + k] = ret[k],\
    \ k++;\r\n\t\ti += k; j -= k;\r\n\t}\r\n\treturn ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.cpp
  requiredBy: []
  timestamp: '2021-03-12 03:55:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/string/z_algorithm.test.cpp
documentation_of: string/z_algorithm.cpp
layout: document
title: Z Algorithm
---

## 説明
文字列 $S$ において、$S$ と $S$ の $i$ 文字目以降の最長共通接頭辞を記録した配列を構築するアルゴリズム。
