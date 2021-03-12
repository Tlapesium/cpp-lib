#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"
#include <bits/stdc++.h>
#include "graph/graph.cpp"
#include "graph/scc.cpp"
using namespace std;
typedef long long ll;

int main() {
	int V, E;
	cin >> V >> E;
	Graph g(V);
	for (int i = 0; i < E; i++) {
		int s, t;
		cin >> s >> t;
		g[s].emplace_back(t);
	}
	StronglyConnectedComponents SCC(g);
	SCC.build();
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int u, v;
		cin >> u >> v;
		cout << (SCC[u] == SCC[v]) << endl;
	}

}