---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.cpp
    title: Z Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/string/z_algorithm.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/zalgorithm\"\r\n#include <bits/stdc++.h>\r\n#line\
    \ 2 \"string/z_algorithm.cpp\"\n\r\nstd::vector<int> z_algorithm(const std::string&\
    \ S) {\r\n\tstd::vector<int> ret(S.size(), 0);\r\n\tret[0] = S.size();\r\n\tint\
    \ i = 1, j = 0;\r\n\twhile (i < S.size()) {\r\n\t\twhile (i + j < S.size() &&\
    \ S[j] == S[i + j])j++;\r\n\t\tret[i] = j;\r\n\t\tif (j == 0) { i++; continue;\
    \ }\r\n\t\tint k = 1;\r\n\t\twhile (i + k < S.size() && k + ret[k] < j)ret[i +\
    \ k] = ret[k], k++;\r\n\t\ti += k; j -= k;\r\n\t}\r\n\treturn ret;\r\n}\n#line\
    \ 4 \"verify/string/z_algorithm.test.cpp\"\nusing namespace std;\r\ntypedef long\
    \ long ll;\r\n\r\nint main() {\r\n\tstring S;\r\n\tcin >> S;\r\n\tauto v = z_algorithm(S);\r\
    \n\tfor (int i = 0; i < v.size(); i++)cout << v[i] << (i == v.size() - 1 ? \"\\\
    n\" : \" \");\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n#include\
    \ <bits/stdc++.h>\r\n#include \"string/z_algorithm.cpp\"\r\nusing namespace std;\r\
    \ntypedef long long ll;\r\n\r\nint main() {\r\n\tstring S;\r\n\tcin >> S;\r\n\t\
    auto v = z_algorithm(S);\r\n\tfor (int i = 0; i < v.size(); i++)cout << v[i] <<\
    \ (i == v.size() - 1 ? \"\\n\" : \" \");\r\n}"
  dependsOn:
  - string/z_algorithm.cpp
  isVerificationFile: true
  path: verify/string/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 03:55:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/string/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/string/z_algorithm.test.cpp
- /verify/verify/string/z_algorithm.test.cpp.html
title: verify/string/z_algorithm.test.cpp
---
