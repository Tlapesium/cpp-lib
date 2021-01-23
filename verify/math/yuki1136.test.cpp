#define PROBLEM "https://yukicoder.me/problems/no/1136"
#include <bits/stdc++.h>
#include "math/matrix.cpp"
using namespace std;
typedef long long ll;

constexpr int MOD = 1000000007;

struct modmat : public matrix {
	using matrix::matrix;
	modmat& operator*= (const modmat& r) {
		std::vector c(height(), std::vector(r.width(), 0LL));
		for (int i = 0; i < height(); i++) {
			for (int j = 0; j < r.width(); j++) {
				for (int k = 0; k < width(); k++) {
					c[i][j] += v[i][k] * r.v[k][j] % MOD;
					c[i][j] %= MOD;
				}
			}
		}
		v = c;
		return *this;
	}
};

modmat operator*(const modmat& l, const modmat& r) { return modmat(l) *= r; }

modmat matpow(const modmat& x, ll n) {
	if (n == 0)return modmat(x.height());
	if (n % 2 == 0) {
		modmat tmp = matpow(x, n / 2);
		return tmp * tmp;
	}
	else {
		return x * matpow(x, n - 1);
	}
}

int main() {
	ll N;
	cin >> N;
	auto m = matpow(modmat{ {0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0} }, N);
	m = m * modmat{ {1},{0},{0},{0} };
	cout << m.v[0][0] << endl;
}