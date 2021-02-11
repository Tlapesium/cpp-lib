---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.cpp
    title: Rolling Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"verify/string/ALDS1_14_B.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\r\n#line 2 \"string/rolling_hash.cpp\"\
    \n\r\n#include <vector>\r\n#include <string>\r\n#include <utility>\r\n\r\nstruct\
    \ RollingHash {\r\n\tusing u64 = unsigned long long;\r\n\tconst u64 mod = (1ULL\
    \ << 61) - 1;\r\n\tconst u64 mask30 = (1ULL << 30) - 1, mask31 = (1ULL << 31)\
    \ - 1, mask61 = mod;\r\n\tu64 calcmod(u64 x) const {\r\n\t\tu64 xu = x >> 61;\r\
    \n\t\tu64 xd = x & mask61;\r\n\t\tu64 ret = xu + xd;\r\n\t\tif (ret >= mod) ret\
    \ -= mod;\r\n\t\treturn ret;\r\n\t}\r\n\tu64 mul(u64 a, u64 b) const {\r\n\t\t\
    u64 au = a >> 31;\r\n\t\tu64 ad = a & mask31;\r\n\t\tu64 bu = b >> 31;\r\n\t\t\
    u64 bd = b & mask31;\r\n\t\tu64 mid = ad * bu + au * bd;\r\n\t\tu64 midu = mid\
    \ >> 30;\r\n\t\tu64 midd = mid & mask30;\r\n\t\treturn au * bu * 2 + midu + (midd\
    \ << 31) + ad * bd;\r\n\t}\r\n\r\n\tconst int base, length;\r\n\tstd::vector<u64>\
    \ hash, power;\r\n\r\n\tRollingHash(const std::string& S, int b) : base(b), length(S.size())\
    \ {\r\n\t\thash.resize(length + 1, 0);\r\n\t\tpower.resize(length + 1, 0);\r\n\
    \t\tpower[0] = 1;\r\n\t\tfor (int i = 0; i < length; i++) {\r\n\t\t\tpower[i +\
    \ 1] = calcmod(mul(power[i], base));\r\n\t\t\thash[i + 1] = calcmod(mul(hash[i],\
    \ base) + S[i]);\r\n\t\t}\r\n\t}\r\n\r\n\tauto get(int l, int r) const {\r\n\t\
    \treturn calcmod(hash[r] + mod * 4 - mul(hash[l], power[r - l]));\r\n\t}\r\n\r\
    \n\tauto concat(const RollingHash& b, int l1, int r1, int l2, int r2) const {\r\
    \n\t\tauto h1 = get(l1, r1), h2 = b.get(l2, r2);\r\n\t\treturn calcmod(calcmod(mul(h1,\
    \ b.power[r2 - l2])) + h2);\r\n\t}\r\n\r\n\tint getLCP(const RollingHash& b, int\
    \ l1, int l2) const {\r\n\t\tint len = std::min(length - l1, b.length - l2);\r\
    \n\t\tint low = -1, high = len + 1;\r\n\t\twhile (high - low > 1) {\r\n\t\t\t\
    int mid = (low + high) / 2;\r\n\t\t\tif (get(l1, l1 + mid) == b.get(l2, l2 + mid))low\
    \ = mid;\r\n\t\t\telse high = mid;\r\n\t\t}\r\n\t\treturn low;\r\n\t}\r\n};\n\
    #line 3 \"verify/string/ALDS1_14_B.test.cpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tstring T, P;\r\
    \n\tcin >> T >> P;\r\n\tRollingHash t(T, 1000000007), p(P, 1000000007);\r\n\t\
    for (int i = 0; i <= int(T.size()) - int(P.size()); i++) {\r\n\t\tif (t.get(i,\
    \ i + P.size()) == p.get(0, P.size()))cout << i << endl;\r\n\t}\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\r\
    \n#include \"string/rolling_hash.cpp\"\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\ntypedef long long ll;\r\n\r\nint main() {\r\n\tstring T, P;\r\n\tcin\
    \ >> T >> P;\r\n\tRollingHash t(T, 1000000007), p(P, 1000000007);\r\n\tfor (int\
    \ i = 0; i <= int(T.size()) - int(P.size()); i++) {\r\n\t\tif (t.get(i, i + P.size())\
    \ == p.get(0, P.size()))cout << i << endl;\r\n\t}\r\n}"
  dependsOn:
  - string/rolling_hash.cpp
  isVerificationFile: true
  path: verify/string/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2021-02-12 07:58:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/string/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/verify/string/ALDS1_14_B.test.cpp
- /verify/verify/string/ALDS1_14_B.test.cpp.html
title: verify/string/ALDS1_14_B.test.cpp
---
