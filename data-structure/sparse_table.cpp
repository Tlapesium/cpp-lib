#pragma once
#include <vector>
#include <functional>

/**
 * @title Sparce Table
 */

template<class T, class Comp = std::less<T> >
struct SparseTable {
	std::vector<std::vector<T>> st;
	const int size;
	const Comp comp;
	SparseTable(const std::vector<T>& v, Comp c = Comp()) : size(v.size()), comp(c) {
		st.resize(size, std::vector<T>(32 - __builtin_clz(size)));
		for (int i = 0; i < size; i++) st[i][0] = v[i];
		for (int i = 1; (1 << i) <= size; i++) {
			for (int j = 0; j + (1 << i) <= size; j++) {
				if (comp(st[j][i - 1], st[j + (1 << (i - 1))][i - 1])) {
					st[j][i] = st[j][i - 1];
				}
				else {
					st[j][i] = st[j + (1 << (i - 1))][i - 1];
				}
			}
		}
	}
	T get(int l, int r) {
		int k = 32 - __builtin_clz(r - l) - 1;
		if (comp(st[l][k], st[r - (1 << k)][k])) {
			return st[l][k];
		}
		else {
			return st[r - (1 << k)][k];
		}
	}
};

template<class T, class Comp>
SparseTable<T, Comp> makeSparseTable(const std::vector<T>& v, Comp c) {
	return SparseTable<T, Comp>(v, c);
}
