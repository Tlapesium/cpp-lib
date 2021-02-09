---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/gettime.cpp\"\n#include <chrono>\r\n\r\nlong long\
    \ getTime() {\r\n\treturn std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();\r\
    \n}\r\n"
  code: "#include <chrono>\r\n\r\nlong long getTime() {\r\n\treturn std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/gettime.cpp
  requiredBy: []
  timestamp: '2021-02-09 09:18:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/gettime.cpp
layout: document
title: getTime
---

## 説明
現在時刻をミリ秒単位で取得する。