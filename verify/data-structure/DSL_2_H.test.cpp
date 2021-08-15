#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"
#include <bits/stdc++.h>
#include "data-structure/lazy_segment_tree.cpp"
using namespace std;
typedef long long ll;

int main() {
	int INF = (1 << 31) - 1;
	auto F = [](int l, int r) {return min(l, r); };
	auto G = [](int m, int op) {return m + op; };
	auto H = [](int a, int b) {return a + b; };
	int N, Q;
	cin >> N >> Q;

	vector<int> v(N, 0);
	auto LST = makeLazySegTree(v, F, G, H, INF, 0);

	for (int i = 0; i < Q; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			int s, t, x;
			cin >> s >> t >> x;
			LST.set(s, t + 1, x);
		}
		else {
			int s, t;
			cin >> s >> t;
			cout << LST.get(s, t + 1) << endl;
		}
	}
}