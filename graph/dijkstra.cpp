#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include "graph/graph.cpp"

/**
 * @title Shortest Path (Dijkstra)
 */

auto Dijkstra(int s, WeightedGraph& g) {
	constexpr auto inf = std::numeric_limits<long long>::max();
	using P = std::pair<long long, int>;
	std::priority_queue<P, std::vector<P>, std::greater<P>> q;
	std::vector d(g.size(), inf);
	d[s] = 0;
	q.push({ 0,s });

	while (q.size()) {
		auto [cost, pos] = q.top(); q.pop();
		if (d[pos] < cost)continue;
		for (auto&& e : g[pos]) {
			if (d[e.first] > d[pos] + e.second) {
				d[e.first] = d[pos] + e.second;
				q.push({ d[e.first] , e.first });
			}
		}
	}
	return d;
}