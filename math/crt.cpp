#pragma once
#include <vector>
#include <numeric>
#include <limits>
#include "math/extgcd.cpp"

long long crt(std::vector<long long>& b, std::vector<long long>& m, long long mod = std::numeric_limits<long long>::max()) {
	auto pmod = [&](long long a, long long m) {
		a = a % m;
		return (a < 0 ? a + m : a);
	};
	auto modinv = [&](long long a, long long m) {
		auto [x, y] = extGCD(a, m);
		return pmod(x, m);
	};
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < i; j++) {
			long long g = std::gcd(m[i], m[j]);
			if ((b[i] - b[j]) % g != 0)return -1;
			m[i] /= g; m[j] /= g;
			long long gi = std::gcd(m[i], g), gj = g / gi;
			do {
				g = std::gcd(gi, gj);
				gi *= g, gj /= g;
			} while (g != 1);
			m[i] *= gi, m[j] *= gj;
			b[i] %= m[i], b[j] %= m[j];
		}
	}
	m.push_back(mod);
	std::vector<long long> tmp1(m.size(), 1), tmp2(m.size(), 0);
	for (int k = 0; k < b.size(); k++) {
		long long t = pmod((b[k] - tmp2[k]) * modinv(tmp1[k], m[k]), m[k]);
		for (int i = k + 1; i < m.size(); i++) {
			tmp2[i] = (tmp2[i] + tmp1[i] * t) % m[i];
			tmp1[i] = (tmp1[i] * m[k]) % m[i];
		}
	}
	return tmp2.back();
}
