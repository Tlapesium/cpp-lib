#pragma once
#include "graph/graph.cpp"
#include "data-structure/union_find.cpp"

long long kruskal(const Graph& g) {
	UnionFind UF(g.size());
	long long ret = 0;
	std::vector<std::pair<int, Edge>> edges;
	for (int i = 0; i < g.size(); i++)for (auto e : g[i]) {
		edges.push_back({ i,e });
	}
	std::sort(edges.begin(), edges.end(), [](const auto& l, const auto& r) {return l.second.cost < r.second.cost; });
	for (int i = 0; i < edges.size(); i++) {
		if (!UF.issame(edges[i].first, edges[i].second.to) || edges[i].second.cost <= 0) {
			ret += edges[i].second.cost;
			UF.merge(edges[i].first, edges[i].second.to);
		}
	}
	return ret;
}