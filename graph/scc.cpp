#pragma once
#include "graph/graph.cpp"

struct StronglyConnectedComponents {
	Graph g, rg;
	std::vector<int> comp;
	std::vector<std::vector<int>> group;

	StronglyConnectedComponents(Graph& g) : g(g), rg(g.size()), comp(g.size(), -1) {
		for (int i = 0; i < g.size(); i++) {
			for (auto&& e : g[i]) {
				rg[e.to].emplace_back(i);
			}
		}
	}

	Graph build() {
		std::vector<int> order, used(g.size(), 0);
		auto dfs = [&](auto&& dfs, int pos) -> void {
			if (used[pos])return;
			used[pos] = true;
			for (auto&& e : g[pos]) dfs(dfs, e.to);
			order.push_back(pos);
		};

		auto rdfs = [&](auto&& rdfs, int pos, int cnt) -> void {
			if (comp[pos] != -1)return;
			comp[pos] = cnt;
			for (auto&& e : rg[pos])rdfs(rdfs, e.to, cnt);
		};

		for (int i = 0; i < g.size(); i++)dfs(dfs, i);
		std::reverse(order.begin(), order.end());
		int cnt = 0;
		for (auto&& v : order)if (comp[v] == -1)rdfs(rdfs, v, cnt), cnt++;

		Graph ret(cnt);
		for (int i = 0; i < g.size(); i++) {
			for (auto&& e : g[i]) {
				int x = comp[i], y = comp[e.to];
				if (x == y)continue;
				ret[x].emplace_back(y, e.cost);
			}
		}

		group.resize(cnt);
		for (int i = 0; i < g.size(); i++) {
			group[comp[i]].push_back(i);
		}

		return ret;
	}

	int operator[] (int k) const {
		return comp[k];
	}
};
