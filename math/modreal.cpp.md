---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint.cpp\"\n\r\nstruct Modint {\r\n\tlong long val\
    \ = 0, mod = 1000000007;\r\n\tModint(long long x, long long m) : mod(m) { val\
    \ = ((x % mod) + mod) % mod; }\r\n\tModint(long long x) { val = ((x % mod) + mod)\
    \ % mod; }\r\n\r\n\tModint& operator+=(const Modint& r) {\r\n\t\tval = (val +\
    \ r.val >= mod ? val + r.val - mod : val + r.val);\r\n\t\treturn *this;\r\n\t\
    }\r\n\tModint& operator-=(const Modint& r) {\r\n\t\tval = (val - r.val < 0 ? val\
    \ - r.val + mod : val - r.val);\r\n\t\treturn *this;\r\n\t}\r\n\tModint& operator*=(const\
    \ Modint& r) {\r\n\t\tval = (val * r.val) % mod;\r\n\t\treturn *this;\r\n\t}\r\
    \n\tModint& operator/=(const Modint& r) {\r\n\t\tlong long a = r.val, b = mod,\
    \ u = 1, v = 0;\r\n\t\twhile (b) {\r\n\t\t\tlong long t = a / b;\r\n\t\t\ta -=\
    \ t * b; std::swap(a, b);\r\n\t\t\tu -= t * v; std::swap(u, v);\r\n\t\t}\r\n\t\
    \tu %= mod;\r\n\t\tif (u < 0) u += mod;\r\n\t\tval = val * u % mod;\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\r\n};\r\n\r\nModint operator+(const Modint& l, const Modint&\
    \ r) { return Modint(l) += r; }\r\nModint operator-(const Modint& l, const Modint&\
    \ r) { return Modint(l) -= r; }\r\nModint operator*(const Modint& l, const Modint&\
    \ r) { return Modint(l) *= r; }\r\nModint operator/(const Modint& l, const Modint&\
    \ r) { return Modint(l) /= r; }\r\nModint operator+(const Modint& l, const long\
    \ long& r) { return Modint(l) += Modint(r, l.mod); }\r\nModint operator-(const\
    \ Modint& l, const long long& r) { return Modint(l) -= Modint(r, l.mod); }\r\n\
    Modint operator*(const Modint& l, const long long& r) { return Modint(l) *= Modint(r,\
    \ l.mod); }\r\nModint operator/(const Modint& l, const long long& r) { return\
    \ Modint(l) /= Modint(r, l.mod); }\r\nModint operator+(const long long& l, const\
    \ Modint& r) { return Modint(l, r.mod) += r; }\r\nModint operator-(const long\
    \ long& l, const Modint& r) { return Modint(l, r.mod) -= r; }\r\nModint operator*(const\
    \ long long& l, const Modint& r) { return Modint(l, r.mod) *= r; }\r\nModint operator/(const\
    \ long long& l, const Modint& r) { return Modint(l, r.mod) /= r; }\r\n\r\nstd::ostream&\
    \ operator << (std::ostream& stream, const Modint& mi) {\r\n\treturn stream <<\
    \ mi.val;\r\n};\r\nstd::istream& operator >> (std::istream& stream, Modint& mi)\
    \ {\r\n\tlong long tmp;\r\n\tstream >> tmp;\r\n\tmi = Modint(tmp);\r\n\treturn\
    \ stream;\r\n};\r\nModint modpow(Modint x, long long k) {\r\n\tif (k == 0)return\
    \ 1;\r\n\tif (k % 2 == 0) return modpow(x * x, k / 2);\r\n\telse return x * modpow(x,\
    \ k - 1);\r\n}\r\n#line 3 \"math/modreal.cpp\"\n\r\nstruct Modreal {\r\n\tModint\
    \ numerator, denominator;\r\n\tModreal(long long a = 0, long long b = 1) : numerator(a),\
    \ denominator(b) {}\r\n\tModint val() { return numerator / denominator; }\r\n\t\
    Modreal& operator+=(const Modreal& r) {\r\n\t\tauto tmp = numerator * r.denominator\
    \ + r.numerator * denominator;\r\n\t\tdenominator *= r.denominator;\r\n\t\tnumerator\
    \ = tmp;\r\n\t\treturn *this;\r\n\t}\r\n\tModreal& operator-=(const Modreal& r)\
    \ {\r\n\t\tauto tmp = numerator * r.denominator - r.numerator * denominator;\r\
    \n\t\tdenominator *= r.denominator;\r\n\t\tnumerator = tmp;\r\n\t\treturn *this;\r\
    \n\t}\r\n\tModreal& operator*=(const Modreal& r) {\r\n\t\tdenominator *= r.denominator;\r\
    \n\t\tnumerator *= r.numerator;\r\n\t\treturn *this;\r\n\t}\r\n\tModreal& operator/=(const\
    \ Modreal& r) {\r\n\t\tdenominator *= r.numerator;\r\n\t\tnumerator *= r.denominator;\r\
    \n\t\treturn *this;\r\n\t}\r\n\r\n};\r\n\r\nModreal operator+(const Modreal& l,\
    \ const Modreal& r) { return Modreal(l) += r; }\r\nModreal operator-(const Modreal&\
    \ l, const Modreal& r) { return Modreal(l) -= r; }\r\nModreal operator*(const\
    \ Modreal& l, const Modreal& r) { return Modreal(l) *= r; }\r\nModreal operator/(const\
    \ Modreal& l, const Modreal& r) { return Modreal(l) /= r; }\n"
  code: "#pragma once\r\n#include \"math/modint.cpp\"\r\n\r\nstruct Modreal {\r\n\t\
    Modint numerator, denominator;\r\n\tModreal(long long a = 0, long long b = 1)\
    \ : numerator(a), denominator(b) {}\r\n\tModint val() { return numerator / denominator;\
    \ }\r\n\tModreal& operator+=(const Modreal& r) {\r\n\t\tauto tmp = numerator *\
    \ r.denominator + r.numerator * denominator;\r\n\t\tdenominator *= r.denominator;\r\
    \n\t\tnumerator = tmp;\r\n\t\treturn *this;\r\n\t}\r\n\tModreal& operator-=(const\
    \ Modreal& r) {\r\n\t\tauto tmp = numerator * r.denominator - r.numerator * denominator;\r\
    \n\t\tdenominator *= r.denominator;\r\n\t\tnumerator = tmp;\r\n\t\treturn *this;\r\
    \n\t}\r\n\tModreal& operator*=(const Modreal& r) {\r\n\t\tdenominator *= r.denominator;\r\
    \n\t\tnumerator *= r.numerator;\r\n\t\treturn *this;\r\n\t}\r\n\tModreal& operator/=(const\
    \ Modreal& r) {\r\n\t\tdenominator *= r.numerator;\r\n\t\tnumerator *= r.denominator;\r\
    \n\t\treturn *this;\r\n\t}\r\n\r\n};\r\n\r\nModreal operator+(const Modreal& l,\
    \ const Modreal& r) { return Modreal(l) += r; }\r\nModreal operator-(const Modreal&\
    \ l, const Modreal& r) { return Modreal(l) -= r; }\r\nModreal operator*(const\
    \ Modreal& l, const Modreal& r) { return Modreal(l) *= r; }\r\nModreal operator/(const\
    \ Modreal& l, const Modreal& r) { return Modreal(l) /= r; }"
  dependsOn:
  - math/modint.cpp
  isVerificationFile: false
  path: math/modreal.cpp
  requiredBy: []
  timestamp: '2021-08-27 17:21:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modreal.cpp
layout: document
title: Modreal
---

## 説明
有理数ジャッジ用のなにか。