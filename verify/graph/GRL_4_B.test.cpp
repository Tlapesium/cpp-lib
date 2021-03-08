#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"
#include "graph/graph.cpp"
#include "graph/topological_sort.cpp"
#include <bits/stdc++.h>
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
	for (int i = 0; i < sorted.size(); i++) {
		cout << sorted[i] << endl;
	}
}