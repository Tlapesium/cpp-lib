---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/string/ALDS1_14_B.test.cpp
    title: verify/string/ALDS1_14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/string/z_algorithm_2.test.cpp
    title: verify/string/z_algorithm_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.cpp\"\n\r\nstruct RollingHash {\r\n\t\
    using u64 = unsigned long long;\r\n\tconst u64 mod = (1ULL << 61) - 1;\r\n\tconst\
    \ u64 mask30 = (1ULL << 30) - 1, mask31 = (1ULL << 31) - 1, mask61 = mod;\r\n\t\
    u64 calcmod(u64 x) const {\r\n\t\tu64 xu = x >> 61;\r\n\t\tu64 xd = x & mask61;\r\
    \n\t\tu64 ret = xu + xd;\r\n\t\tif (ret >= mod) ret -= mod;\r\n\t\treturn ret;\r\
    \n\t}\r\n\tu64 mul(u64 a, u64 b) const {\r\n\t\tu64 au = a >> 31;\r\n\t\tu64 ad\
    \ = a & mask31;\r\n\t\tu64 bu = b >> 31;\r\n\t\tu64 bd = b & mask31;\r\n\t\tu64\
    \ mid = ad * bu + au * bd;\r\n\t\tu64 midu = mid >> 30;\r\n\t\tu64 midd = mid\
    \ & mask30;\r\n\t\treturn au * bu * 2 + midu + (midd << 31) + ad * bd;\r\n\t}\r\
    \n\r\n\tconst int base, length;\r\n\tstd::vector<u64> hash, power;\r\n\r\n\tRollingHash(const\
    \ std::string& S, int b) : base(b), length(S.size()) {\r\n\t\thash.resize(length\
    \ + 1, 0);\r\n\t\tpower.resize(length + 1, 0);\r\n\t\tpower[0] = 1;\r\n\t\tfor\
    \ (int i = 0; i < length; i++) {\r\n\t\t\tpower[i + 1] = calcmod(mul(power[i],\
    \ base));\r\n\t\t\thash[i + 1] = calcmod(mul(hash[i], base) + S[i]);\r\n\t\t}\r\
    \n\t}\r\n\r\n\tauto get(int l, int r) const {\r\n\t\treturn calcmod(hash[r] +\
    \ mod * 4 - mul(hash[l], power[r - l]));\r\n\t}\r\n\r\n\tauto concat(const RollingHash&\
    \ b, int l1, int r1, int l2, int r2) const {\r\n\t\tauto h1 = get(l1, r1), h2\
    \ = b.get(l2, r2);\r\n\t\treturn calcmod(calcmod(mul(h1, b.power[r2 - l2])) +\
    \ h2);\r\n\t}\r\n\r\n\tint getLCP(const RollingHash& b, int l1, int l2) const\
    \ {\r\n\t\tint len = std::min(length - l1, b.length - l2);\r\n\t\tint low = -1,\
    \ high = len + 1;\r\n\t\twhile (high - low > 1) {\r\n\t\t\tint mid = (low + high)\
    \ / 2;\r\n\t\t\tif (get(l1, l1 + mid) == b.get(l2, l2 + mid))low = mid;\r\n\t\t\
    \telse high = mid;\r\n\t\t}\r\n\t\treturn low;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\nstruct RollingHash {\r\n\tusing u64 = unsigned long long;\r\
    \n\tconst u64 mod = (1ULL << 61) - 1;\r\n\tconst u64 mask30 = (1ULL << 30) - 1,\
    \ mask31 = (1ULL << 31) - 1, mask61 = mod;\r\n\tu64 calcmod(u64 x) const {\r\n\
    \t\tu64 xu = x >> 61;\r\n\t\tu64 xd = x & mask61;\r\n\t\tu64 ret = xu + xd;\r\n\
    \t\tif (ret >= mod) ret -= mod;\r\n\t\treturn ret;\r\n\t}\r\n\tu64 mul(u64 a,\
    \ u64 b) const {\r\n\t\tu64 au = a >> 31;\r\n\t\tu64 ad = a & mask31;\r\n\t\t\
    u64 bu = b >> 31;\r\n\t\tu64 bd = b & mask31;\r\n\t\tu64 mid = ad * bu + au *\
    \ bd;\r\n\t\tu64 midu = mid >> 30;\r\n\t\tu64 midd = mid & mask30;\r\n\t\treturn\
    \ au * bu * 2 + midu + (midd << 31) + ad * bd;\r\n\t}\r\n\r\n\tconst int base,\
    \ length;\r\n\tstd::vector<u64> hash, power;\r\n\r\n\tRollingHash(const std::string&\
    \ S, int b) : base(b), length(S.size()) {\r\n\t\thash.resize(length + 1, 0);\r\
    \n\t\tpower.resize(length + 1, 0);\r\n\t\tpower[0] = 1;\r\n\t\tfor (int i = 0;\
    \ i < length; i++) {\r\n\t\t\tpower[i + 1] = calcmod(mul(power[i], base));\r\n\
    \t\t\thash[i + 1] = calcmod(mul(hash[i], base) + S[i]);\r\n\t\t}\r\n\t}\r\n\r\n\
    \tauto get(int l, int r) const {\r\n\t\treturn calcmod(hash[r] + mod * 4 - mul(hash[l],\
    \ power[r - l]));\r\n\t}\r\n\r\n\tauto concat(const RollingHash& b, int l1, int\
    \ r1, int l2, int r2) const {\r\n\t\tauto h1 = get(l1, r1), h2 = b.get(l2, r2);\r\
    \n\t\treturn calcmod(calcmod(mul(h1, b.power[r2 - l2])) + h2);\r\n\t}\r\n\r\n\t\
    int getLCP(const RollingHash& b, int l1, int l2) const {\r\n\t\tint len = std::min(length\
    \ - l1, b.length - l2);\r\n\t\tint low = -1, high = len + 1;\r\n\t\twhile (high\
    \ - low > 1) {\r\n\t\t\tint mid = (low + high) / 2;\r\n\t\t\tif (get(l1, l1 +\
    \ mid) == b.get(l2, l2 + mid))low = mid;\r\n\t\t\telse high = mid;\r\n\t\t}\r\n\
    \t\treturn low;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.cpp
  requiredBy: []
  timestamp: '2021-03-12 03:00:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/string/ALDS1_14_B.test.cpp
  - verify/string/z_algorithm_2.test.cpp
documentation_of: string/rolling_hash.cpp
layout: document
title: Rolling Hash
---

## 説明
ハッシュを用いて文字列の一致判定を高速に行うアルゴリズム。

## 操作
- :heavy_check_mark: **RollingHash(S, b)** : 文字列 $S$ からハッシュテーブルを構築する。$b$ にはハッシュの基数を指定する。
- :heavy_check_mark: **get(l, r)** : 区間 $[l,r)$ のハッシュを求める。
- :question: **concat(b, l1, r1, l2, r2)** : 区間 $[l1,r1)$ と、ハッシュテーブル $b$ の区間 $[l2,r2)$ を結合したもののハッシュを求める。
- :heavy_check_mark: **getLCP(b, l1, l2)** : $l1$ から始まる区間と、ハッシュテーブル $b$ の $l2$ から始まる区間の最長共通接頭辞の長さを求める。