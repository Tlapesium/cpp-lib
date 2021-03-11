#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"
#include <bits/stdc++.h>
#include "graph/graph.cpp"
#include "graph/topological_sort.cpp"
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
	auto sorted = topological_sort(g);
	cout << (sorted.size() == 0 ? 1 : 0) << endl;
}