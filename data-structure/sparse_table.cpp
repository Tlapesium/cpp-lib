#pragma once
#include <vector>
#include <functional>

template<class T, class Comp = std::less<T> >
struct SparseTable {
	std::vector<std::vector<T>> st;
	int size;
	SparseTable() = default;
	SparseTable(const std::vector<T>& v) : size(v.size()) {
		st.resize(size, std::vector<T>(32 - __builtin_clz(size)));
		for (int i = 0; i < size; i++) st[i][0] = v[i];
		for (int i = 1; (1 << i) <= size; i++) {
			for (int j = 0; j + (1 << i) <= size; j++) {
				st[j][i] = Comp()(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]) ? st[j][i - 1] : st[j + (1 << (i - 1))][i - 1];
			}
		}
	}
	T get(int l, int r) {
		int k = 32 - __builtin_clz(r - l) - 1;
		return Comp()(st[l][k], st[r - (1 << k)][k]) ? st[l][k] : st[r - (1 << k)][k];
	}
};