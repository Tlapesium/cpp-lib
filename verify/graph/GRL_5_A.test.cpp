#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"
#include <bits/stdc++.h>
#include "graph/graph.cpp"
#include "graph/tree_diameter.cpp"
using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	Graph g(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	cout << tree_diameter(g).first << endl;
}
