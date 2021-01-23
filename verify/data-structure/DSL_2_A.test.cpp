#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include <bits/stdc++.h>
#include "data-structure/segment_tree.cpp"
using namespace std;
typedef long long ll;

int main() {
	int N, Q;
	cin >> N >> Q;
	ll INF = (1LL << 31LL) - 1LL;
	auto ST = makeSegTree(vector(N, INF), [](ll& l, ll& r) {return min(l, r); }, INF);
	for (int i = 0; i < Q; i++) {
		ll c, x, y;
		cin >> c >> x >> y;
		if (c == 0) ST.set(x, y);
		if (c == 1)cout << ST.get(x, y + 1) << endl;
	}
}