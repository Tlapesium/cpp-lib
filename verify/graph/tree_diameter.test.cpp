#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
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
	auto ret = tree_diameter(g);
	cout << ret.first << " " << ret.second.size() << endl;
	for (int i = 0; i < ret.second.size(); i++) {
		cout << ret.second[i] << (i == ret.second.size() - 1 ? "\n" : " ");
	}
}
