#pragma once
#include "graph/graph.cpp"

auto tree_diameter(const Graph& g) {
	std::vector<long long> dist(g.size(), 0);
	std::vector<int> v;
	auto dfs = [&](auto&& dfs, int pos, int par, long long d, int dest) -> bool {
		bool flag = pos == dest;
		for (auto&& e : g[pos]) {
			if (e.to == par)continue;
			flag |= dfs(dfs, e.to, pos, d + e.cost, dest);
			dist[e.to] = d + e.cost;
		}
		if (flag)v.push_back(pos);
		return flag;
	};
	dfs(dfs, 0, -1, 0, -1);
	int p = std::max_element(dist.begin(), dist.end()) - dist.begin();
	dist[p] = 0;
	dfs(dfs, p, -1, 0, -1);
	int q = std::max_element(dist.begin(), dist.end()) - dist.begin();
	dfs(dfs, p, -1, 0, q);
	return std::make_pair(*std::max_element(dist.begin(), dist.end()), v);
}