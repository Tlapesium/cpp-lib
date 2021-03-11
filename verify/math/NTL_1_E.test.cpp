#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E"
#include <bits/stdc++.h>
#include "math/extgcd.cpp"
using namespace std;
typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;
	auto [x, y] = extGCD(a, b);
	cout << x << " " << y << endl;
}