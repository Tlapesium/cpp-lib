#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"
#include "graph/graph.cpp"
#include "graph/dijkstra.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int V, E, r;
	cin >> V >> E >> r;
	WeightedGraph g(V);
	for (int i = 0; i < E; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		g[s].push_back({ t,c });
	}
	auto d = Dijkstra(r, g);
	for (int i = 0; i < d.size(); i++) {
		(d[i] == numeric_limits<ll>::max() ? cout << "INF" << endl : cout << d[i] << endl);
	}
}