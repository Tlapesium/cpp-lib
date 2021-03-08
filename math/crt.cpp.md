---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/math/yuki187.test.cpp
    title: verify/math/yuki187.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/crt.cpp\"\n#include <vector>\r\n#include <numeric>\r\
    \n#include <limits>\r\n#include <initializer_list>\r\n#line 2 \"math/extgcd.cpp\"\
    \n#include <utility>\r\n\r\nauto extGCD(long long a, long long b) {\r\n\tlong\
    \ long x = 1, y = 0, u = 0, v = 1;\r\n\twhile (b != 0) {\r\n\t\tauto j = a % b,\
    \ k = a / b;\r\n\t\tx -= k * u; y -= k * v;\r\n\t\tstd::swap(x, u); std::swap(y,\
    \ v);\r\n\t\ta = b; b = j;\r\n\t}\r\n\treturn std::make_pair(x, y);\r\n}\n#line\
    \ 7 \"math/crt.cpp\"\n\r\nlong long crt(std::vector<long long>& b, std::vector<long\
    \ long>& m, long long mod = std::numeric_limits<long long>::max()) {\r\n\tauto\
    \ pmod = [&](long long a, long long m) {\r\n\t\ta = a % m;\r\n\t\treturn (a <\
    \ 0 ? a + m : a);\r\n\t};\r\n\tauto modinv = [&](long long a, long long m) {\r\
    \n\t\tauto [x, y] = extGCD(a, m);\r\n\t\treturn pmod(x, m);\r\n\t};\r\n\tfor (int\
    \ i = 0; i < b.size(); i++) {\r\n\t\tfor (int j = 0; j < i; j++) {\r\n\t\t\tlong\
    \ long g = std::gcd(m[i], m[j]);\r\n\t\t\tif ((b[i] - b[j]) % g != 0)return -1;\r\
    \n\t\t\tm[i] /= g; m[j] /= g;\r\n\t\t\tlong long gi = std::gcd(m[i], g), gj =\
    \ g / gi;\r\n\t\t\tdo {\r\n\t\t\t\tg = std::gcd(gi, gj);\r\n\t\t\t\tgi *= g, gj\
    \ /= g;\r\n\t\t\t} while (g != 1);\r\n\t\t\tm[i] *= gi, m[j] *= gj;\r\n\t\t\t\
    b[i] %= m[i], b[j] %= m[j];\r\n\t\t}\r\n\t}\r\n\tm.push_back(mod);\r\n\tstd::vector<long\
    \ long> tmp1(m.size(), 1), tmp2(m.size(), 0);\r\n\tfor (int k = 0; k < b.size();\
    \ k++) {\r\n\t\tlong long t = pmod((b[k] - tmp2[k]) * modinv(tmp1[k], m[k]), m[k]);\r\
    \n\t\tfor (int i = k + 1; i < m.size(); i++) {\r\n\t\t\ttmp2[i] = (tmp2[i] + tmp1[i]\
    \ * t) % m[i];\r\n\t\t\ttmp1[i] = (tmp1[i] * m[k]) % m[i];\r\n\t\t}\r\n\t}\r\n\
    \treturn tmp2.back();\r\n}\r\n\r\nlong long crt(std::initializer_list<long long>\
    \ b, std::initializer_list<long long> m, long long mod = std::numeric_limits<long\
    \ long>::max()) {\r\n\tstd::vector<long long> b_(b), m_(m);\r\n\treturn crt(b_,\
    \ m_, mod);\r\n}\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <numeric>\r\n#include <limits>\r\
    \n#include <initializer_list>\r\n#include \"math/extgcd.cpp\"\r\n\r\nlong long\
    \ crt(std::vector<long long>& b, std::vector<long long>& m, long long mod = std::numeric_limits<long\
    \ long>::max()) {\r\n\tauto pmod = [&](long long a, long long m) {\r\n\t\ta =\
    \ a % m;\r\n\t\treturn (a < 0 ? a + m : a);\r\n\t};\r\n\tauto modinv = [&](long\
    \ long a, long long m) {\r\n\t\tauto [x, y] = extGCD(a, m);\r\n\t\treturn pmod(x,\
    \ m);\r\n\t};\r\n\tfor (int i = 0; i < b.size(); i++) {\r\n\t\tfor (int j = 0;\
    \ j < i; j++) {\r\n\t\t\tlong long g = std::gcd(m[i], m[j]);\r\n\t\t\tif ((b[i]\
    \ - b[j]) % g != 0)return -1;\r\n\t\t\tm[i] /= g; m[j] /= g;\r\n\t\t\tlong long\
    \ gi = std::gcd(m[i], g), gj = g / gi;\r\n\t\t\tdo {\r\n\t\t\t\tg = std::gcd(gi,\
    \ gj);\r\n\t\t\t\tgi *= g, gj /= g;\r\n\t\t\t} while (g != 1);\r\n\t\t\tm[i] *=\
    \ gi, m[j] *= gj;\r\n\t\t\tb[i] %= m[i], b[j] %= m[j];\r\n\t\t}\r\n\t}\r\n\tm.push_back(mod);\r\
    \n\tstd::vector<long long> tmp1(m.size(), 1), tmp2(m.size(), 0);\r\n\tfor (int\
    \ k = 0; k < b.size(); k++) {\r\n\t\tlong long t = pmod((b[k] - tmp2[k]) * modinv(tmp1[k],\
    \ m[k]), m[k]);\r\n\t\tfor (int i = k + 1; i < m.size(); i++) {\r\n\t\t\ttmp2[i]\
    \ = (tmp2[i] + tmp1[i] * t) % m[i];\r\n\t\t\ttmp1[i] = (tmp1[i] * m[k]) % m[i];\r\
    \n\t\t}\r\n\t}\r\n\treturn tmp2.back();\r\n}\r\n\r\nlong long crt(std::initializer_list<long\
    \ long> b, std::initializer_list<long long> m, long long mod = std::numeric_limits<long\
    \ long>::max()) {\r\n\tstd::vector<long long> b_(b), m_(m);\r\n\treturn crt(b_,\
    \ m_, mod);\r\n}"
  dependsOn:
  - math/extgcd.cpp
  isVerificationFile: false
  path: math/crt.cpp
  requiredBy: []
  timestamp: '2021-03-09 01:37:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/yuki187.test.cpp
documentation_of: math/crt.cpp
layout: document
title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---

