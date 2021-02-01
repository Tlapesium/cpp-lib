#define PROBLEM "https://yukicoder.me/problems/no/1136"
#include "math/modint.cpp"
#include "math/matrix.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using modmat = Matrix<Modint>;

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