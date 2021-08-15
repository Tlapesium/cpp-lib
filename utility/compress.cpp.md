---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/utility/AOJ0580.test.cpp
    title: verify/utility/AOJ0580.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/compress.cpp\"\n\r\ntemplate<class T>\r\nstruct\
    \ Compress {\r\n\tstd::vector<T> data;\r\n\tvoid add(T x) {\r\n\t\tdata.push_back(x);\r\
    \n\t}\r\n\tvoid build() {\r\n\t\tstd::sort(data.begin(), data.end());\r\n\t\t\
    data.erase(std::unique(data.begin(), data.end()), data.end());\r\n\t}\r\n\r\n\t\
    const int operator[](int x) const {\r\n\t\treturn std::lower_bound(data.begin(),\
    \ data.end(), x) - data.begin();\r\n\t}\r\n\r\n\tconst T operator()(int k) const\
    \ {\r\n\t\treturn data[k];\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate<class T>\r\nstruct Compress {\r\n\tstd::vector<T>\
    \ data;\r\n\tvoid add(T x) {\r\n\t\tdata.push_back(x);\r\n\t}\r\n\tvoid build()\
    \ {\r\n\t\tstd::sort(data.begin(), data.end());\r\n\t\tdata.erase(std::unique(data.begin(),\
    \ data.end()), data.end());\r\n\t}\r\n\r\n\tconst int operator[](int x) const\
    \ {\r\n\t\treturn std::lower_bound(data.begin(), data.end(), x) - data.begin();\r\
    \n\t}\r\n\r\n\tconst T operator()(int k) const {\r\n\t\treturn data[k];\r\n\t\
    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/compress.cpp
  requiredBy: []
  timestamp: '2021-08-16 07:42:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/utility/AOJ0580.test.cpp
documentation_of: utility/compress.cpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---

## 説明
座標の大小関係を維持しつつ、$N$ 個の座標 $(x_0, x_1, \dots, x_N)$ と整数 $(0, 1, \dots, N-1)$ を対応させる。

## 操作
- :heavy_check_mark: **add(x)** : 整数 $x$ を追加する。
- :heavy_check_mark: **build()** : 構築する。
- :heavy_check_mark: **operator\(\)\[x\]** : 座標 $x$ に対応する整数を返す。
- :heavy_check_mark: **operator(k)** : 整数 $k$ に対応する座標を返す。
