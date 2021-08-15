#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <bits/stdc++.h>
#include "string/rolling_hash.cpp"
using namespace std;
typedef long long ll;

int main() {
	string S;
	cin >> S;
	RollingHash s(S, 1000000007);
	for (int i = 0; i < S.size(); i++) {
		cout << s.getLCP(s, 0, i) << (i == S.size() - 1 ? "\n" : " ");
	}
}