#pragma once
#include <iostream>
#include <cstdio>
#include <utility>

/**
 * @title Modint
 */

struct Modint {
	long long val = 0, mod = 1000000007;
	Modint(long long x, long long m) : mod(m) { val = ((x % mod) + mod) % mod; }
	Modint(long long x) { val = ((x % mod) + mod) % mod; }

	Modint& operator+=(const Modint& r) {
		val = (val + r.val >= mod ? val + r.val - mod : val + r.val);
		return *this;
	}
	Modint& operator-=(const Modint& r) {
		val = (val - r.val < 0 ? val - r.val + mod : val - r.val);
		return *this;
	}
	Modint& operator*=(const Modint& r) {
		val = (val * r.val) % mod;
		return *this;
	}
	Modint& operator/=(const Modint& r) {
		long long a = r.val, b = mod, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		u %= mod;
		if (u < 0) u += mod;
		val = val * u % mod;
		return *this;
	}

	Modint& operator ++ () noexcept { val++; return *this; }
	Modint& operator -- () noexcept { val--; return *this; }
	Modint operator ++ (int) noexcept { auto tmp = *this; val++; return tmp; }
	Modint operator -- (int) noexcept { auto tmp = *this; val--; return tmp; }

};

Modint operator+(const Modint& l, const Modint& r) { return Modint(l) += r; }
Modint operator-(const Modint& l, const Modint& r) { return Modint(l) -= r; }
Modint operator*(const Modint& l, const Modint& r) { return Modint(l) *= r; }
Modint operator/(const Modint& l, const Modint& r) { return Modint(l) /= r; }
Modint operator+(const Modint& l, const long long& r) { return Modint(l) += Modint(r, l.mod); }
Modint operator-(const Modint& l, const long long& r) { return Modint(l) -= Modint(r, l.mod); }
Modint operator*(const Modint& l, const long long& r) { return Modint(l) *= Modint(r, l.mod); }
Modint operator/(const Modint& l, const long long& r) { return Modint(l) /= Modint(r, l.mod); }
Modint operator+(const long long& l, const Modint& r) { return Modint(l, r.mod) += r; }
Modint operator-(const long long& l, const Modint& r) { return Modint(l, r.mod) -= r; }
Modint operator*(const long long& l, const Modint& r) { return Modint(l, r.mod) *= r; }
Modint operator/(const long long& l, const Modint& r) { return Modint(l, r.mod) /= r; }

std::ostream& operator << (std::ostream& stream, const Modint& mi) {
	return stream << mi.val;
};
std::istream& operator >> (std::istream& stream, Modint& mi) {
	long long tmp;
	stream >> tmp;
	mi = Modint(tmp);
	return stream;
};
Modint modpow(Modint x, int k) {
	if (k == 0)return 1;
	if (k % 2 == 0) return modpow(x * x, k / 2);
	else return x * modpow(x, k - 1);
}
