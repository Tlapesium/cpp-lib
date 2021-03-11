#pragma once
#include "graph/graph.cpp"
#include "data-structure/sparse_table.cpp"

struct LowestCommonAncester {
	SparseTable<std::pair<int, int>> ST;
	std::vector<int> in;
	LowestCommonAncester(const Graph& g) {
		std::vector<std::pair<int, int>> tmp;
		in.resize(g.size());
		auto dfs = [&](auto&& dfs, int pos, int par, int depth) -> void {
			if (par == -1) tmp.push_back({ 0,pos });
			in[pos] = tmp.size();
			for (auto&& e : g[pos]) {
				if (e.to == par)continue;
				tmp.push_back({ depth + 1, e.to });
				dfs(dfs, e.to, pos, depth + 1);
				tmp.push_back({ depth,pos });
			}
		};
		dfs(dfs, 0, -1, 0);
		ST = SparseTable<std::pair<int, int>>(tmp);
	}

	int query(int u, int v) {
		return ST.get(std::min(in[u], in[v]) - 1, std::max(in[u], in[v])).second;
	}
};