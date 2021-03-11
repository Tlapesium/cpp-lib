#pragma once
#include "graph/graph.cpp"

auto BellmanFord(int s, Graph& g) {
	constexpr auto inf = std::numeric_limits<long long>::max();
	std::vector d(g.size(), inf);;
	d[s] = 0;
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g.size(); j++) {
			for (auto&& e : g[j]) {
				if (d[j] != inf && d[e.to] > d[j] + e.cost) {
					d[e.to] = d[j] + e.cost;
					if (i == g.size() - 1)return std::vector<long long>();
				}
			}
		}
	}
	return d;
}