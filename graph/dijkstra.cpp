#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include "graph/graph.cpp"

auto Dijkstra(int s, Graph& g) {
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
			if (d[e.to] > d[pos] + e.cost) {
				d[e.to] = d[pos] + e.cost;
				q.push({ d[e.to] , e.to });
			}
		}
	}
	return d;
}
