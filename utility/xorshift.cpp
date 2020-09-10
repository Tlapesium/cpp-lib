#pragma once
#include <smmintrin.h>
#include <immintrin.h>

/**
 * @title XORShift
 * @docs utility/xorshift.md
 */

 //need SSE2
struct xorshift_32_4 {
	static unsigned int x[4];
	static int cnt;
	unsigned int operator()() {
		if (cnt != 4) return x[cnt++];
		__m128i a;
		a = _mm_loadu_si128((__m128i*)x);
		a = _mm_xor_si128(a, _mm_slli_epi32(a, 13));
		a = _mm_xor_si128(a, _mm_srli_epi32(a, 17));
		a = _mm_xor_si128(a, _mm_slli_epi32(a, 5));
		_mm_storeu_si128((__m128i*)x, a);
		cnt = 1;
		return x[0];
	}
};
int xorshift_32_4::cnt = 0;
unsigned int xorshift_32_4::x[] = { 0xf247756d, 0x1654caaa, 0xb2f5e564, 0x7d986dd7 };

//need AVX2
struct xorshift_32_8 {
	static unsigned int x[8];
	static int cnt;
	unsigned int operator()() {
		if (cnt != 8) return x[cnt++];
		__m256i a;
		a = _mm256_loadu_si256((__m256i*)x);
		a = _mm256_xor_si256(a, _mm256_slli_epi32(a, 13));
		a = _mm256_xor_si256(a, _mm256_srli_epi32(a, 17));
		a = _mm256_xor_si256(a, _mm256_slli_epi32(a, 5));
		_mm256_storeu_si256((__m256i*)x, a);
		cnt = 1;
		return x[0];
	}
};
int xorshift_32_8::cnt = 0;
unsigned int xorshift_32_8::x[] = { 0xd5eae750, 0xc784b986, 0x16bcf701, 0x65032360, 0xb628094f, 0xd8281e7b, 0xecfa5dc8, 0x3b828203 };

struct xorshift_64_4 {
	static unsigned long long int x[4];
	static int cnt;
	unsigned long long int operator()() {
		if (cnt != 4) return x[cnt++];
		__m256i a;
		a = _mm256_loadu_si256((__m256i*)x);
		a = _mm256_xor_si256(a, _mm256_slli_epi64(a, 7));
		a = _mm256_xor_si256(a, _mm256_srli_epi64(a, 9));
		_mm256_storeu_si256((__m256i*)x, a);
		cnt = 1;
		return x[0];
	}
};

int xorshift_64_4::cnt = 0;
unsigned long long int xorshift_64_4::x[] = { 0xf77bcfb23d5143cfULL, 0xbda154512ac6f703ULL, 0xb2ef653838c2edf3ULL, 0xa7dbfba7cef3c195ULL };
