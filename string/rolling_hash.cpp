#pragma once

#include <vector>
#include <string>
#include <utility>

struct RollingHash {
	using u64 = unsigned long long;
	const u64 mod = (1ULL << 61) - 1;
	const u64 mask30 = (1ULL << 30) - 1, mask31 = (1ULL << 31) - 1, mask61 = mod;
	u64 calcmod(u64 x) const {
		u64 xu = x >> 61;
		u64 xd = x & mask61;
		u64 ret = xu + xd;
		if (ret >= mod) ret -= mod;
		return ret;
	}
	u64 mul(u64 a, u64 b) const {
		u64 au = a >> 31;
		u64 ad = a & mask31;
		u64 bu = b >> 31;
		u64 bd = b & mask31;
		u64 mid = ad * bu + au * bd;
		u64 midu = mid >> 30;
		u64 midd = mid & mask30;
		return au * bu * 2 + midu + (midd << 31) + ad * bd;
	}

	const int base, length;
	std::vector<u64> hash, power;

	RollingHash(const std::string& S, int b) : base(b), length(S.size()) {
		hash.resize(length + 1, 0);
		power.resize(length + 1, 0);
		power[0] = 1;
		for (int i = 0; i < length; i++) {
			power[i + 1] = calcmod(mul(power[i], base));
			hash[i + 1] = calcmod(mul(hash[i], base) + S[i]);
		}
	}

	auto get(int l, int r) const {
		return calcmod(hash[r] + mod * 4 - mul(hash[l], power[r - l]));
	}

	auto concat(const RollingHash& b, int l1, int r1, int l2, int r2) const {
		auto h1 = get(l1, r1), h2 = b.get(l2, r2);
		return calcmod(calcmod(mul(h1, b.power[r2 - l2])) + h2);
	}

	int getLCP(const RollingHash& b, int l1, int l2) const {
		int len = std::min(length - l1, b.length - l2);
		int low = -1, high = len + 1;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (get(l1, l1 + mid) == b.get(l2, l2 + mid))low = mid;
			else high = mid;
		}
		return low;
	}
};