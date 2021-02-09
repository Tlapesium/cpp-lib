---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/xorshift.cpp\"\n#include <smmintrin.h>\r\n#include\
    \ <immintrin.h>\r\n\r\n //need SSE2\r\nstruct xorshift_32_4 {\r\n\tstatic unsigned\
    \ int x[4];\r\n\tstatic int cnt;\r\n\tunsigned int operator()() {\r\n\t\tif (cnt\
    \ != 4) return x[cnt++];\r\n\t\t__m128i a;\r\n\t\ta = _mm_loadu_si128((__m128i*)x);\r\
    \n\t\ta = _mm_xor_si128(a, _mm_slli_epi32(a, 13));\r\n\t\ta = _mm_xor_si128(a,\
    \ _mm_srli_epi32(a, 17));\r\n\t\ta = _mm_xor_si128(a, _mm_slli_epi32(a, 5));\r\
    \n\t\t_mm_storeu_si128((__m128i*)x, a);\r\n\t\tcnt = 1;\r\n\t\treturn x[0];\r\n\
    \t}\r\n};\r\nint xorshift_32_4::cnt = 0;\r\nunsigned int xorshift_32_4::x[] =\
    \ { 0xf247756d, 0x1654caaa, 0xb2f5e564, 0x7d986dd7 };\r\n\r\n//need AVX2\r\nstruct\
    \ xorshift_32_8 {\r\n\tstatic unsigned int x[8];\r\n\tstatic int cnt;\r\n\tunsigned\
    \ int operator()() {\r\n\t\tif (cnt != 8) return x[cnt++];\r\n\t\t__m256i a;\r\
    \n\t\ta = _mm256_loadu_si256((__m256i*)x);\r\n\t\ta = _mm256_xor_si256(a, _mm256_slli_epi32(a,\
    \ 13));\r\n\t\ta = _mm256_xor_si256(a, _mm256_srli_epi32(a, 17));\r\n\t\ta = _mm256_xor_si256(a,\
    \ _mm256_slli_epi32(a, 5));\r\n\t\t_mm256_storeu_si256((__m256i*)x, a);\r\n\t\t\
    cnt = 1;\r\n\t\treturn x[0];\r\n\t}\r\n};\r\nint xorshift_32_8::cnt = 0;\r\nunsigned\
    \ int xorshift_32_8::x[] = { 0xd5eae750, 0xc784b986, 0x16bcf701, 0x65032360, 0xb628094f,\
    \ 0xd8281e7b, 0xecfa5dc8, 0x3b828203 };\r\n\r\nstruct xorshift_64_4 {\r\n\tstatic\
    \ unsigned long long int x[4];\r\n\tstatic int cnt;\r\n\tunsigned long long int\
    \ operator()() {\r\n\t\tif (cnt != 4) return x[cnt++];\r\n\t\t__m256i a;\r\n\t\
    \ta = _mm256_loadu_si256((__m256i*)x);\r\n\t\ta = _mm256_xor_si256(a, _mm256_slli_epi64(a,\
    \ 7));\r\n\t\ta = _mm256_xor_si256(a, _mm256_srli_epi64(a, 9));\r\n\t\t_mm256_storeu_si256((__m256i*)x,\
    \ a);\r\n\t\tcnt = 1;\r\n\t\treturn x[0];\r\n\t}\r\n};\r\n\r\nint xorshift_64_4::cnt\
    \ = 0;\r\nunsigned long long int xorshift_64_4::x[] = { 0xf77bcfb23d5143cfULL,\
    \ 0xbda154512ac6f703ULL, 0xb2ef653838c2edf3ULL, 0xa7dbfba7cef3c195ULL };\r\n"
  code: "#pragma once\r\n#include <smmintrin.h>\r\n#include <immintrin.h>\r\n\r\n\
    \ //need SSE2\r\nstruct xorshift_32_4 {\r\n\tstatic unsigned int x[4];\r\n\tstatic\
    \ int cnt;\r\n\tunsigned int operator()() {\r\n\t\tif (cnt != 4) return x[cnt++];\r\
    \n\t\t__m128i a;\r\n\t\ta = _mm_loadu_si128((__m128i*)x);\r\n\t\ta = _mm_xor_si128(a,\
    \ _mm_slli_epi32(a, 13));\r\n\t\ta = _mm_xor_si128(a, _mm_srli_epi32(a, 17));\r\
    \n\t\ta = _mm_xor_si128(a, _mm_slli_epi32(a, 5));\r\n\t\t_mm_storeu_si128((__m128i*)x,\
    \ a);\r\n\t\tcnt = 1;\r\n\t\treturn x[0];\r\n\t}\r\n};\r\nint xorshift_32_4::cnt\
    \ = 0;\r\nunsigned int xorshift_32_4::x[] = { 0xf247756d, 0x1654caaa, 0xb2f5e564,\
    \ 0x7d986dd7 };\r\n\r\n//need AVX2\r\nstruct xorshift_32_8 {\r\n\tstatic unsigned\
    \ int x[8];\r\n\tstatic int cnt;\r\n\tunsigned int operator()() {\r\n\t\tif (cnt\
    \ != 8) return x[cnt++];\r\n\t\t__m256i a;\r\n\t\ta = _mm256_loadu_si256((__m256i*)x);\r\
    \n\t\ta = _mm256_xor_si256(a, _mm256_slli_epi32(a, 13));\r\n\t\ta = _mm256_xor_si256(a,\
    \ _mm256_srli_epi32(a, 17));\r\n\t\ta = _mm256_xor_si256(a, _mm256_slli_epi32(a,\
    \ 5));\r\n\t\t_mm256_storeu_si256((__m256i*)x, a);\r\n\t\tcnt = 1;\r\n\t\treturn\
    \ x[0];\r\n\t}\r\n};\r\nint xorshift_32_8::cnt = 0;\r\nunsigned int xorshift_32_8::x[]\
    \ = { 0xd5eae750, 0xc784b986, 0x16bcf701, 0x65032360, 0xb628094f, 0xd8281e7b,\
    \ 0xecfa5dc8, 0x3b828203 };\r\n\r\nstruct xorshift_64_4 {\r\n\tstatic unsigned\
    \ long long int x[4];\r\n\tstatic int cnt;\r\n\tunsigned long long int operator()()\
    \ {\r\n\t\tif (cnt != 4) return x[cnt++];\r\n\t\t__m256i a;\r\n\t\ta = _mm256_loadu_si256((__m256i*)x);\r\
    \n\t\ta = _mm256_xor_si256(a, _mm256_slli_epi64(a, 7));\r\n\t\ta = _mm256_xor_si256(a,\
    \ _mm256_srli_epi64(a, 9));\r\n\t\t_mm256_storeu_si256((__m256i*)x, a);\r\n\t\t\
    cnt = 1;\r\n\t\treturn x[0];\r\n\t}\r\n};\r\n\r\nint xorshift_64_4::cnt = 0;\r\
    \nunsigned long long int xorshift_64_4::x[] = { 0xf77bcfb23d5143cfULL, 0xbda154512ac6f703ULL,\
    \ 0xb2ef653838c2edf3ULL, 0xa7dbfba7cef3c195ULL };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/xorshift.cpp
  requiredBy: []
  timestamp: '2021-02-09 09:18:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/xorshift.cpp
layout: document
title: XORShift
---
## 説明
SIMDを用いて高速化したXORShift。<br>
乱数がボトルネックになることはあんまりない気がするが、早くて困ることはなさそう。

### xorshift_32_4
周期が $2^{32} - 1$ の32bit乱数を生成する。SSE2が必要。

### xorshift_32_8
周期が $2^{32} - 1$ の32bit乱数を生成する。AVX2が必要。

### xorshift_64_4
周期が $2^{64} - 1$ の64bit乱数を生成する。AVX2が必要。

## ベンチマーク
$10^9$ 回の生成に掛かった時間を計測。

| アルゴリズム  | 実行時間 | 拡張命令セット | 
| ------------- | :------- | :------------- | 
| [xorshift_32](https://ja.wikipedia.org/wiki/Xorshift)   | 1796ms   |                | 
| xorshift_32_4 | 932ms    | SSE2           | 
| xorshift_32_8 | 612ms    | AVX2           | 
| [xorshift_64](https://ja.wikipedia.org/wiki/Xorshift)   | 1220ms   |                | 
| xorshift_64_4 | 844ms    | AVX2           | 