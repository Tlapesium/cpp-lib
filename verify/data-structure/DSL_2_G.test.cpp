#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"
#include <bits/stdc++.h>
#include "data-structure/dynamic_lazy_segment_tree.cpp"
using namespace std;
typedef long long ll;

int main() {
	auto F = [](ll a, ll b) {return a + b; };
	auto G = [](ll a, ll b, int size) {return a + b * size; };
	auto H = [](ll a, ll b) {return a + b; };

	int N, Q;
	cin >> N >> Q;
	auto LST = makeDynamicLazySegTree(N, F, G, H, 0LL, 0LL);

	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		if (q == 0) {
			int s, t, x;
			cin >> s >> t >> x;
			LST.set(s - 1, t, x);
		}
		if (q == 1) {
			int s, t;
			cin >> s >> t;
			cout << LST.get(s - 1, t) << endl;
		}
	}
}