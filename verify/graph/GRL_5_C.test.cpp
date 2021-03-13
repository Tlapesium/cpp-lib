#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"
#include <bits/stdc++.h>
#include "graph/graph.cpp"
#include "graph/lca.cpp"
using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	Graph g(N);
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int t;
			cin >> t;
			g[i].emplace_back(t);
			g[t].emplace_back(i);
		}
	}
	LowestCommonAncester LCA(g);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int u, v;
		cin >> u >> v;
		cout << LCA.query(u, v) << endl;
	}
}
