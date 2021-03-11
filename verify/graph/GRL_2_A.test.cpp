#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"
#include <bits/stdc++.h>
#include "graph/graph.cpp"
#include "graph/kruskal.cpp"
using namespace std;
typedef long long ll;

int main() {
	int V, E;
	cin >> V >> E;
	Graph g(V);
	for (int i = 0; i < E; i++) {
		int s, t, w;
		cin >> s >> t >> w;
		g[s].emplace_back(t, w);
		g[t].emplace_back(s, w);
	}
	cout << kruskal(g) << endl;
}