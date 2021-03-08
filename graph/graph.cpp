#pragma once
#include <vector>

struct Edge {
	int to; long long cost;
	Edge(int to) : to(to), cost(1) {};
	Edge(int to, long long cost) : to(to), cost(cost) {}
};
using Graph = std::vector<std::vector<Edge>>;