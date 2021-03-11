#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"
#include <bits/stdc++.h>
#include "string/rolling_hash.cpp"
using namespace std;
typedef long long ll;

int main() {
	string T, P;
	cin >> T >> P;
	RollingHash t(T, 1000000007), p(P, 1000000007);
	for (int i = 0; i <= int(T.size()) - int(P.size()); i++) {
		if (t.get(i, i + P.size()) == p.get(0, P.size()))cout << i << endl;
	}
}