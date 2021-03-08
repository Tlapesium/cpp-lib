#pragma once
#include <utility>

auto extGCD(long long a, long long b) {
	long long x = 1, y = 0, u = 0, v = 1;
	while (b != 0) {
		auto j = a % b, k = a / b;
		x -= k * u; y -= k * v;
		std::swap(x, u); std::swap(y, v);
		a = b; b = j;
	}
	return std::make_pair(x, y);
}