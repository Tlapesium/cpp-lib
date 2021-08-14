#pragma once

struct UnionFind {
private:
	std::vector<int> siz, par;
	std::vector<long long> wei;
	int f_s;
public:
	UnionFind(int size) : f_s(size) {
		siz.assign(size, 1);
		wei.assign(size, 0);
		par.assign(size, 0);
		for (int i = 0; i < size; i++)par[i] = i;
	}
	bool merge(int x, int y, long long w = 0) {
		w += weight(x); w -= weight(y);
		x = root(x); y = root(y);
		if (x == y)return false;
		if (siz[x] < siz[y])std::swap(x, y), w = -w;
		siz[x] += siz[y];
		par[y] = x;
		wei[y] = w;
		f_s--;
		return true;
	}
	long long weight(int x) {
		root(x);
		return wei[x];
	}
	int root(int k) {
		if (par[k] == k)return k;
		int tmp = root(par[k]);
		wei[k] += wei[par[k]];
		return par[k] = tmp;
	}
	bool issame(int x, int y) {
		return root(x) == root(y);
	}
	long long diff(int x, int y) {
		return weight(y) - weight(x);
	}
	int size(int x) {
		return siz[root(x)];
	}
	int forest_size() {
		return f_s;
	}
};