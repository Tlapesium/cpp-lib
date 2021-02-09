#pragma once
#include <vector>
#include <utility>
#include <limits>
#include "graph/graph.cpp"

auto BellmanFord(int s, WeightedGraph& g) {
	constexpr auto inf = std::numeric_limits<long long>::max();
	std::vector d(g.size(), inf);;
	d[s] = 0;
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g.size(); j++) {
			for (auto&& e : g[j]) {
				if (d[j] != inf && d[e.first] > d[j] + e.second) {
					d[e.first] = d[j] + e.second;
					if (i == g.size() - 1)return std::vector<long long>();
				}
			}
		}
	}
	return d;
}

