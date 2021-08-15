#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include <bits/stdc++.h>
#include "data-structure/segment_tree.cpp"
using namespace std;
typedef long long ll;

int main() {
	int N, Q;
	cin >> N >> Q;
	auto ST = makeSegTree(N, [](ll& l, ll& r) {return l + r; }, 0LL);
	for (int i = 0; i < Q; i++) {
		ll c, x, y;
		cin >> c >> x >> y;
		if (c == 0) ST.set(x - 1, ST[x - 1] + y);
		if (c == 1)cout << ST.get(x - 1, y) << endl;
	}
}