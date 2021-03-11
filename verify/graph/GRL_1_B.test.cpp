#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"
#include <bits/stdc++.h>
#include "graph/graph.cpp"
#include "graph/bellman_ford.cpp"
using namespace std;
typedef long long ll;

int main() {
	int V, E, r;
	cin >> V >> E >> r;
	Graph g(V);
	for (int i = 0; i < E; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		g[s].emplace_back(t, c);
	}
	auto d = BellmanFord(r, g);
	if (d.empty())cout << "NEGATIVE CYCLE" << endl;
	else {
		for (int i = 0; i < d.size(); i++) {
			(d[i] == numeric_limits<ll>::max() ? cout << "INF" << endl : cout << d[i] << endl);
		}
	}
}