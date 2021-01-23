---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Matrix
    links: []
  bundledCode: "#line 2 \"math/matrix.cpp\"\n#include <vector>\r\n#include <initializer_list>\r\
    \n#include <iostream>\r\n\r\n/**\r\n * @title Matrix\r\n */\r\n\r\nstruct matrix\
    \ {\r\n\tstd::vector<std::vector<long long>> v;\r\n\tmatrix() = default;\r\n\t\
    matrix(int N, int M) {\r\n\t\tv = std::vector(N, std::vector(M, 0LL));\r\n\t}\r\
    \n\r\n\tmatrix(std::initializer_list<std::initializer_list<long long>> list) {\r\
    \n\t\tfor (auto&& row : list) {\r\n\t\t\tv.push_back(row);\r\n\t\t}\r\n\t}\r\n\
    \tmatrix& operator=(std::initializer_list<std::initializer_list<long long>> list)\
    \ {\r\n\t\tthis->v.clear();\r\n\t\tfor (auto&& row : list) {\r\n\t\t\tthis->v.push_back(row);\r\
    \n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tmatrix& operator+= (const matrix&\
    \ r) {\r\n\t\tfor (int i = 0; i < v.size(); i++)for (int j = 0; j < v[i].size();\
    \ j++) {\r\n\t\t\tv[i][j] += r.v[i][j];\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\
    \n\r\n\tmatrix& operator-= (const matrix& r) {\r\n\t\tfor (int i = 0; i < v.size();\
    \ i++)for (int j = 0; j < v[i].size(); j++) {\r\n\t\t\tv[i][j] -= r.v[i][j];\r\
    \n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tmatrix& operator*= (const matrix&\
    \ r) {\r\n\t\tstd::vector c(v.size(), std::vector(r.v[0].size(), 0LL));\r\n\t\t\
    for (int i = 0; i < v.size(); i++) {\r\n\t\t\tfor (int j = 0; j < r.v[0].size();\
    \ j++) {\r\n\t\t\t\tfor (int k = 0; k < v[0].size(); k++) {\r\n\t\t\t\t\tc[i][j]\
    \ += v[i][k] * r.v[k][j];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tv = c;\r\n\t\
    \treturn *this;\r\n\t}\r\n\r\n\tvoid dump() {\r\n\t\tfor (int i = 0; i < v.size();\
    \ i++)for (int j = 0; j < v[i].size(); j++) {\r\n\t\t\tstd::cout << v[i][j] <<\
    \ (j == v[i].size() - 1 ? \"\\n\" : \" \");\r\n\t\t}\r\n\t}\r\n};\r\n\r\nmatrix\
    \ operator+(const matrix& l, const matrix& r) { return matrix(l) += r; }\r\nmatrix\
    \ operator-(const matrix& l, const matrix& r) { return matrix(l) -= r; }\r\nmatrix\
    \ operator*(const matrix& l, const matrix& r) { return matrix(l) *= r; }\r\n\r\
    \n"
  code: "#pragma once\r\n#include <vector>\r\n#include <initializer_list>\r\n#include\
    \ <iostream>\r\n\r\n/**\r\n * @title Matrix\r\n */\r\n\r\nstruct matrix {\r\n\t\
    std::vector<std::vector<long long>> v;\r\n\tmatrix() = default;\r\n\tmatrix(int\
    \ N, int M) {\r\n\t\tv = std::vector(N, std::vector(M, 0LL));\r\n\t}\r\n\r\n\t\
    matrix(std::initializer_list<std::initializer_list<long long>> list) {\r\n\t\t\
    for (auto&& row : list) {\r\n\t\t\tv.push_back(row);\r\n\t\t}\r\n\t}\r\n\tmatrix&\
    \ operator=(std::initializer_list<std::initializer_list<long long>> list) {\r\n\
    \t\tthis->v.clear();\r\n\t\tfor (auto&& row : list) {\r\n\t\t\tthis->v.push_back(row);\r\
    \n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tmatrix& operator+= (const matrix&\
    \ r) {\r\n\t\tfor (int i = 0; i < v.size(); i++)for (int j = 0; j < v[i].size();\
    \ j++) {\r\n\t\t\tv[i][j] += r.v[i][j];\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\
    \n\r\n\tmatrix& operator-= (const matrix& r) {\r\n\t\tfor (int i = 0; i < v.size();\
    \ i++)for (int j = 0; j < v[i].size(); j++) {\r\n\t\t\tv[i][j] -= r.v[i][j];\r\
    \n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tmatrix& operator*= (const matrix&\
    \ r) {\r\n\t\tstd::vector c(v.size(), std::vector(r.v[0].size(), 0LL));\r\n\t\t\
    for (int i = 0; i < v.size(); i++) {\r\n\t\t\tfor (int j = 0; j < r.v[0].size();\
    \ j++) {\r\n\t\t\t\tfor (int k = 0; k < v[0].size(); k++) {\r\n\t\t\t\t\tc[i][j]\
    \ += v[i][k] * r.v[k][j];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tv = c;\r\n\t\
    \treturn *this;\r\n\t}\r\n\r\n\tvoid dump() {\r\n\t\tfor (int i = 0; i < v.size();\
    \ i++)for (int j = 0; j < v[i].size(); j++) {\r\n\t\t\tstd::cout << v[i][j] <<\
    \ (j == v[i].size() - 1 ? \"\\n\" : \" \");\r\n\t\t}\r\n\t}\r\n};\r\n\r\nmatrix\
    \ operator+(const matrix& l, const matrix& r) { return matrix(l) += r; }\r\nmatrix\
    \ operator-(const matrix& l, const matrix& r) { return matrix(l) -= r; }\r\nmatrix\
    \ operator*(const matrix& l, const matrix& r) { return matrix(l) *= r; }\r\n\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy: []
  timestamp: '2021-01-24 00:08:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix.cpp
- /library/math/matrix.cpp.html
title: Matrix
---
