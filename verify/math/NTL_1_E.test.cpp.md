---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
  bundledCode: "#line 1 \"verify/math/NTL_1_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\
    \r\n#include <bits/stdc++.h>\r\n#line 2 \"math/extgcd.cpp\"\n\r\nauto extGCD(long\
    \ long a, long long b) {\r\n\tlong long x = 1, y = 0, u = 0, v = 1;\r\n\twhile\
    \ (b != 0) {\r\n\t\tauto j = a % b, k = a / b;\r\n\t\tx -= k * u; y -= k * v;\r\
    \n\t\tstd::swap(x, u); std::swap(y, v);\r\n\t\ta = b; b = j;\r\n\t}\r\n\treturn\
    \ std::make_pair(x, y);\r\n}\n#line 4 \"verify/math/NTL_1_E.test.cpp\"\nusing\
    \ namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tll a, b;\r\n\
    \tcin >> a >> b;\r\n\tauto [x, y] = extGCD(a, b);\r\n\tcout << x << \" \" << y\
    \ << endl;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E\"\r\n\
    #include <bits/stdc++.h>\r\n#include \"math/extgcd.cpp\"\r\nusing namespace std;\r\
    \ntypedef long long ll;\r\n\r\nint main() {\r\n\tll a, b;\r\n\tcin >> a >> b;\r\
    \n\tauto [x, y] = extGCD(a, b);\r\n\tcout << x << \" \" << y << endl;\r\n}"
  dependsOn:
  - math/extgcd.cpp
  isVerificationFile: true
  path: verify/math/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 03:00:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/verify/math/NTL_1_E.test.cpp
- /verify/verify/math/NTL_1_E.test.cpp.html
title: verify/math/NTL_1_E.test.cpp
---
