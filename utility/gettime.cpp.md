---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: documents/gettime.md
    document_title: getTime
    links: []
  bundledCode: "#line 1 \"utility/gettime.cpp\"\n#include <chrono>\r\n\r\n/**\r\n\
    \ * @title getTime\r\n * @docs documents/gettime.md\r\n */\r\n\r\nlong long getTime()\
    \ {\r\n\treturn std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();\r\
    \n}\r\n"
  code: "#include <chrono>\r\n\r\n/**\r\n * @title getTime\r\n * @docs documents/gettime.md\r\
    \n */\r\n\r\nlong long getTime() {\r\n\treturn std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/gettime.cpp
  requiredBy: []
  timestamp: '2020-09-12 18:00:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/gettime.cpp
layout: document
redirect_from:
- /library/utility/gettime.cpp
- /library/utility/gettime.cpp.html
title: getTime
---

## 説明
現在時刻をミリ秒単位で取得する。