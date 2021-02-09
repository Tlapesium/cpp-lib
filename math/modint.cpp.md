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
  bundledCode: "#line 2 \"math/modint.cpp\"\n#include <iostream>\r\n#include <cstdio>\r\
    \n#include <utility>\r\n\r\nstruct Modint {\r\n\tlong long val = 0, mod = 1000000007;\r\
    \n\tModint(long long x, long long m) : mod(m) { val = ((x % mod) + mod) % mod;\
    \ }\r\n\tModint(long long x) { val = ((x % mod) + mod) % mod; }\r\n\r\n\tModint&\
    \ operator+=(const Modint& r) {\r\n\t\tval = (val + r.val >= mod ? val + r.val\
    \ - mod : val + r.val);\r\n\t\treturn *this;\r\n\t}\r\n\tModint& operator-=(const\
    \ Modint& r) {\r\n\t\tval = (val - r.val < 0 ? val - r.val + mod : val - r.val);\r\
    \n\t\treturn *this;\r\n\t}\r\n\tModint& operator*=(const Modint& r) {\r\n\t\t\
    val = (val * r.val) % mod;\r\n\t\treturn *this;\r\n\t}\r\n\tModint& operator/=(const\
    \ Modint& r) {\r\n\t\tlong long a = r.val, b = mod, u = 1, v = 0;\r\n\t\twhile\
    \ (b) {\r\n\t\t\tlong long t = a / b;\r\n\t\t\ta -= t * b; std::swap(a, b);\r\n\
    \t\t\tu -= t * v; std::swap(u, v);\r\n\t\t}\r\n\t\tu %= mod;\r\n\t\tif (u < 0)\
    \ u += mod;\r\n\t\tval = val * u % mod;\r\n\t\treturn *this;\r\n\t}\r\n\r\n\t\
    Modint& operator ++ () noexcept { val++; return *this; }\r\n\tModint& operator\
    \ -- () noexcept { val--; return *this; }\r\n\tModint operator ++ (int) noexcept\
    \ { auto tmp = *this; val++; return tmp; }\r\n\tModint operator -- (int) noexcept\
    \ { auto tmp = *this; val--; return tmp; }\r\n\r\n};\r\n\r\nModint operator+(const\
    \ Modint& l, const Modint& r) { return Modint(l) += r; }\r\nModint operator-(const\
    \ Modint& l, const Modint& r) { return Modint(l) -= r; }\r\nModint operator*(const\
    \ Modint& l, const Modint& r) { return Modint(l) *= r; }\r\nModint operator/(const\
    \ Modint& l, const Modint& r) { return Modint(l) /= r; }\r\nModint operator+(const\
    \ Modint& l, const long long& r) { return Modint(l) += Modint(r, l.mod); }\r\n\
    Modint operator-(const Modint& l, const long long& r) { return Modint(l) -= Modint(r,\
    \ l.mod); }\r\nModint operator*(const Modint& l, const long long& r) { return\
    \ Modint(l) *= Modint(r, l.mod); }\r\nModint operator/(const Modint& l, const\
    \ long long& r) { return Modint(l) /= Modint(r, l.mod); }\r\nModint operator+(const\
    \ long long& l, const Modint& r) { return Modint(l, r.mod) += r; }\r\nModint operator-(const\
    \ long long& l, const Modint& r) { return Modint(l, r.mod) -= r; }\r\nModint operator*(const\
    \ long long& l, const Modint& r) { return Modint(l, r.mod) *= r; }\r\nModint operator/(const\
    \ long long& l, const Modint& r) { return Modint(l, r.mod) /= r; }\r\n\r\nstd::ostream&\
    \ operator << (std::ostream& stream, const Modint& mi) {\r\n\treturn stream <<\
    \ mi.val;\r\n};\r\nstd::istream& operator >> (std::istream& stream, Modint& mi)\
    \ {\r\n\tlong long tmp;\r\n\tstream >> tmp;\r\n\tmi = Modint(tmp);\r\n\treturn\
    \ stream;\r\n};\r\nModint modpow(Modint x, int k) {\r\n\tif (k == 0)return 1;\r\
    \n\tif (k % 2 == 0) return modpow(x * x, k / 2);\r\n\telse return x * modpow(x,\
    \ k - 1);\r\n}\r\n"
  code: "#pragma once\r\n#include <iostream>\r\n#include <cstdio>\r\n#include <utility>\r\
    \n\r\nstruct Modint {\r\n\tlong long val = 0, mod = 1000000007;\r\n\tModint(long\
    \ long x, long long m) : mod(m) { val = ((x % mod) + mod) % mod; }\r\n\tModint(long\
    \ long x) { val = ((x % mod) + mod) % mod; }\r\n\r\n\tModint& operator+=(const\
    \ Modint& r) {\r\n\t\tval = (val + r.val >= mod ? val + r.val - mod : val + r.val);\r\
    \n\t\treturn *this;\r\n\t}\r\n\tModint& operator-=(const Modint& r) {\r\n\t\t\
    val = (val - r.val < 0 ? val - r.val + mod : val - r.val);\r\n\t\treturn *this;\r\
    \n\t}\r\n\tModint& operator*=(const Modint& r) {\r\n\t\tval = (val * r.val) %\
    \ mod;\r\n\t\treturn *this;\r\n\t}\r\n\tModint& operator/=(const Modint& r) {\r\
    \n\t\tlong long a = r.val, b = mod, u = 1, v = 0;\r\n\t\twhile (b) {\r\n\t\t\t\
    long long t = a / b;\r\n\t\t\ta -= t * b; std::swap(a, b);\r\n\t\t\tu -= t * v;\
    \ std::swap(u, v);\r\n\t\t}\r\n\t\tu %= mod;\r\n\t\tif (u < 0) u += mod;\r\n\t\
    \tval = val * u % mod;\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tModint& operator ++\
    \ () noexcept { val++; return *this; }\r\n\tModint& operator -- () noexcept {\
    \ val--; return *this; }\r\n\tModint operator ++ (int) noexcept { auto tmp = *this;\
    \ val++; return tmp; }\r\n\tModint operator -- (int) noexcept { auto tmp = *this;\
    \ val--; return tmp; }\r\n\r\n};\r\n\r\nModint operator+(const Modint& l, const\
    \ Modint& r) { return Modint(l) += r; }\r\nModint operator-(const Modint& l, const\
    \ Modint& r) { return Modint(l) -= r; }\r\nModint operator*(const Modint& l, const\
    \ Modint& r) { return Modint(l) *= r; }\r\nModint operator/(const Modint& l, const\
    \ Modint& r) { return Modint(l) /= r; }\r\nModint operator+(const Modint& l, const\
    \ long long& r) { return Modint(l) += Modint(r, l.mod); }\r\nModint operator-(const\
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
    \ stream;\r\n};\r\nModint modpow(Modint x, int k) {\r\n\tif (k == 0)return 1;\r\
    \n\tif (k % 2 == 0) return modpow(x * x, k / 2);\r\n\telse return x * modpow(x,\
    \ k - 1);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy: []
  timestamp: '2021-02-09 09:27:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/yuki1136.test.cpp
documentation_of: math/modint.cpp
layout: document
title: Modint
---
