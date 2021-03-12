#define PROBLEM "https://judge.yosupo.jp/problem/scc"
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

	cout << SCC.group.size() << endl;
	for (int i = 0; i < SCC.group.size(); i++) {
		cout << SCC.group[i].size() << " ";
		for (int j = 0; j < SCC.group[i].size(); j++) {
			cout << SCC.group[i][j] << (j == SCC.group[i].size() - 1 ? "\n" : " ");
		}
	}
}