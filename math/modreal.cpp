#pragma once
#include "math/modint.cpp"

struct Modreal {
	Modint numerator, denominator;
	Modreal(long long a = 0, long long b = 1) : numerator(a), denominator(b) {}
	Modint val() { return numerator / denominator; }
	Modreal& operator+=(const Modreal& r) {
		auto tmp = numerator * r.denominator + r.numerator * denominator;
		denominator *= r.denominator;
		numerator = tmp;
		return *this;
	}
	Modreal& operator-=(const Modreal& r) {
		auto tmp = numerator * r.denominator - r.numerator * denominator;
		denominator *= r.denominator;
		numerator = tmp;
		return *this;
	}
	Modreal& operator*=(const Modreal& r) {
		denominator *= r.denominator;
		numerator *= r.numerator;
		return *this;
	}
	Modreal& operator/=(const Modreal& r) {
		denominator *= r.numerator;
		numerator *= r.denominator;
		return *this;
	}

};

Modreal operator+(const Modreal& l, const Modreal& r) { return Modreal(l) += r; }
Modreal operator-(const Modreal& l, const Modreal& r) { return Modreal(l) -= r; }
Modreal operator*(const Modreal& l, const Modreal& r) { return Modreal(l) *= r; }
Modreal operator/(const Modreal& l, const Modreal& r) { return Modreal(l) /= r; }