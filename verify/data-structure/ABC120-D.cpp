#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include <bits/stdc++.h>
#include "data-structure/union_find.cpp"
using namespace std;
typedef long long ll;

int main() {
	ll N, M;
	cin >> N >> M;
	UnionFind uf(N);
	vector<pair<int, int>> e(M);
	vector<ll> ans(M);
	for (int i = 0; i < M; i++) {
		cin >> e[i].first >> e[i].second;
		e[i].first--; e[i].second--;
	}
	ll tmp = N * (N - 1) / 2;;
	for (int i = M - 1; i >= 0; i--) {
		ans[i] = tmp;
		if (uf.issame(e[i].first, e[i].second))continue;
		tmp -= ll(uf.size(e[i].first)) * ll(uf.size(e[i].second));
		uf.merge(e[i].first, e[i].second);
	}
	for (int i = 0; i < M; i++)cout << ans[i] << endl;
}