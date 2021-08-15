#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
#include <bits/stdc++.h>
#include "data-structure/lazy_segment_tree.cpp"
using namespace std;
typedef long long ll;

int main() {
	int INF = (1 << 31) - 1;
	auto F = [](ll l, ll r) {return min(l, r); };
	auto G = [](ll m, ll op) {return op == -1 ? m : op; };
	auto H = [](ll a, ll b) {return a == -1 ? b : a; };

	int N, Q;
	cin >> N >> Q;
	auto LST = makeLazySegTree(N, F, G, H, INF, -1LL);

	ll a, b, c, d;
	for (int i = 0; i < Q; i++) {
		cin >> a;
		if (a == 0) {
			cin >> b >> c >> d;
			LST.set(b, c + 1, d);
		}
		if (a == 1) {
			cin >> b >> c;
			cout << LST.get(b, c + 1) << endl;
		}
	}
}