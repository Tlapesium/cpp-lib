---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/math/yuki1136.test.cpp
    title: verify/math/yuki1136.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.cpp\"\n#include <vector>\r\n#include <initializer_list>\r\
    \n#include <iostream>\r\n\r\ntemplate <class T>\r\nstruct Matrix {\r\npublic:\r\
    \n\tstd::vector<std::vector<T>> v;\r\n\tMatrix() = default;\r\n\tMatrix(int N)\
    \ {\r\n\t\tv = std::vector(N, std::vector(N, T(0)));\r\n\t\tfor (int i = 0; i\
    \ < N; i++)v[i][i] = T(1);\r\n\t}\r\n\tMatrix(int N, int M, T x) {\r\n\t\tv =\
    \ std::vector(N, std::vector(M, x));\r\n\t}\r\n\tMatrix(std::initializer_list<std::initializer_list<long\
    \ long>> list) {\r\n\t\tfor (auto row : list) {\r\n\t\t\tv.push_back(std::vector<T>());\r\
    \n\t\t\tfor (auto x : row) {\r\n\t\t\t\tv.back().push_back(T(x));\r\n\t\t\t}\r\
    \n\t\t}\r\n\t}\r\n\r\n\tint height() const { return v.size(); };\r\n\tint width()\
    \ const { return v[0].size(); };\r\n\r\n\tMatrix& operator=(std::initializer_list<std::initializer_list<long\
    \ long>> list) {\r\n\t\tv.clear();\r\n\t\tfor (auto row : list) {\r\n\t\t\tv.push_back(std::vector<T>());\r\
    \n\t\t\tfor (auto x : row) {\r\n\t\t\t\tv.back().push_back(T(x));\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tMatrix& operator+= (const Matrix&\
    \ r) {\r\n\t\tfor (int i = 0; i < height(); i++)for (int j = 0; j < width(); j++)\
    \ {\r\n\t\t\tv[i][j] += r.v[i][j];\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\
    \tMatrix& operator-= (const Matrix& r) {\r\n\t\tfor (int i = 0; i < height();\
    \ i++)for (int j = 0; j < width(); j++) {\r\n\t\t\tv[i][j] -= r.v[i][j];\r\n\t\
    \t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tMatrix& operator*= (const Matrix& r)\
    \ {\r\n\t\tstd::vector c(height(), std::vector(r.width(), T(0)));\r\n\t\tfor (int\
    \ i = 0; i < height(); i++) {\r\n\t\t\tfor (int k = 0; k < width(); k++) {\r\n\
    \t\t\t\tfor (int j = 0; j < r.width(); j++) {\r\n\t\t\t\t\tc[i][j] += v[i][k]\
    \ * r.v[k][j];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tv = c;\r\n\t\treturn *this;\r\
    \n\t}\r\n\r\n\tvoid dump() {\r\n\t\tfor (int i = 0; i < height(); i++)for (int\
    \ j = 0; j < width(); j++) {\r\n\t\t\tstd::cout << v[i][j] << (j == width() -\
    \ 1 ? \"\\n\" : \" \");\r\n\t\t}\r\n\t}\r\n};\r\ntemplate <class T>\r\nMatrix<T>\
    \ operator+(const Matrix<T>& l, const Matrix<T>& r) { return Matrix<T>(l) += r;\
    \ }\r\ntemplate <class T>\r\nMatrix<T> operator-(const Matrix<T>& l, const Matrix<T>&\
    \ r) { return Matrix<T>(l) -= r; }\r\ntemplate <class T>\r\nMatrix<T> operator*(const\
    \ Matrix<T>& l, const Matrix<T>& r) { return Matrix<T>(l) *= r; }\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <initializer_list>\r\n#include\
    \ <iostream>\r\n\r\ntemplate <class T>\r\nstruct Matrix {\r\npublic:\r\n\tstd::vector<std::vector<T>>\
    \ v;\r\n\tMatrix() = default;\r\n\tMatrix(int N) {\r\n\t\tv = std::vector(N, std::vector(N,\
    \ T(0)));\r\n\t\tfor (int i = 0; i < N; i++)v[i][i] = T(1);\r\n\t}\r\n\tMatrix(int\
    \ N, int M, T x) {\r\n\t\tv = std::vector(N, std::vector(M, x));\r\n\t}\r\n\t\
    Matrix(std::initializer_list<std::initializer_list<long long>> list) {\r\n\t\t\
    for (auto row : list) {\r\n\t\t\tv.push_back(std::vector<T>());\r\n\t\t\tfor (auto\
    \ x : row) {\r\n\t\t\t\tv.back().push_back(T(x));\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\
    \n\r\n\tint height() const { return v.size(); };\r\n\tint width() const { return\
    \ v[0].size(); };\r\n\r\n\tMatrix& operator=(std::initializer_list<std::initializer_list<long\
    \ long>> list) {\r\n\t\tv.clear();\r\n\t\tfor (auto row : list) {\r\n\t\t\tv.push_back(std::vector<T>());\r\
    \n\t\t\tfor (auto x : row) {\r\n\t\t\t\tv.back().push_back(T(x));\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tMatrix& operator+= (const Matrix&\
    \ r) {\r\n\t\tfor (int i = 0; i < height(); i++)for (int j = 0; j < width(); j++)\
    \ {\r\n\t\t\tv[i][j] += r.v[i][j];\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\
    \tMatrix& operator-= (const Matrix& r) {\r\n\t\tfor (int i = 0; i < height();\
    \ i++)for (int j = 0; j < width(); j++) {\r\n\t\t\tv[i][j] -= r.v[i][j];\r\n\t\
    \t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tMatrix& operator*= (const Matrix& r)\
    \ {\r\n\t\tstd::vector c(height(), std::vector(r.width(), T(0)));\r\n\t\tfor (int\
    \ i = 0; i < height(); i++) {\r\n\t\t\tfor (int k = 0; k < width(); k++) {\r\n\
    \t\t\t\tfor (int j = 0; j < r.width(); j++) {\r\n\t\t\t\t\tc[i][j] += v[i][k]\
    \ * r.v[k][j];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tv = c;\r\n\t\treturn *this;\r\
    \n\t}\r\n\r\n\tvoid dump() {\r\n\t\tfor (int i = 0; i < height(); i++)for (int\
    \ j = 0; j < width(); j++) {\r\n\t\t\tstd::cout << v[i][j] << (j == width() -\
    \ 1 ? \"\\n\" : \" \");\r\n\t\t}\r\n\t}\r\n};\r\ntemplate <class T>\r\nMatrix<T>\
    \ operator+(const Matrix<T>& l, const Matrix<T>& r) { return Matrix<T>(l) += r;\
    \ }\r\ntemplate <class T>\r\nMatrix<T> operator-(const Matrix<T>& l, const Matrix<T>&\
    \ r) { return Matrix<T>(l) -= r; }\r\ntemplate <class T>\r\nMatrix<T> operator*(const\
    \ Matrix<T>& l, const Matrix<T>& r) { return Matrix<T>(l) *= r; }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy: []
  timestamp: '2021-02-09 09:27:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/yuki1136.test.cpp
documentation_of: math/matrix.cpp
layout: document
title: Matrix
---
