#pragma once
#include <vector>
#include <algorithm>
#include "graph/graph.cpp"

auto topological_sort(const Graph& g) {
	bool cycle_flag = false;
	std::vector<int> ret, used(g.size(), 0);

	auto dfs = [&](auto&& dfs, const Graph& g, int pos) -> void {
		if (used[pos] == 1) cycle_flag = true;
		else if (used[pos] == 0) {
			used[pos] = 1;
			for (int i = 0; i < g[pos].size(); i++) {
				dfs(dfs, g, g[pos][i].to);
			}
			used[pos] = 2;
			ret.push_back(pos);
		}
	};

	for (int i = 0; i < g.size(); i++) {
		if (used[i] == 0)dfs(dfs, g, i);
		if (cycle_flag)return std::vector<int>();
	}
	std::reverse(ret.begin(), ret.end());
	return ret;
}