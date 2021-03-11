#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "graph/graph.cpp"
#include "graph/lca.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N, Q;
	cin >> N >> Q;
	Graph g(N);
	for (int i = 1; i < N; i++) {
		int p;
		cin >> p;
		g[i].emplace_back(p);
		g[p].emplace_back(i);
	}
	LowestCommonAncester LCA(g);
	for (int i = 0; i < Q; i++) {
		int u, v;
		cin >> u >> v;
		cout << LCA.query(u, v) << endl;
	}
}