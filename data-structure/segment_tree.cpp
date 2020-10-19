#pragma once
#include <vector>

/**
 * @title Segment Tree
 */

template <class Monoid, class MonoidOp>
struct SegmentTree {
	std::vector<Monoid> dat;

	const MonoidOp F;
	const Monoid E;
	const int sz;

	// 単位元で初期化されたセグ木を構築 O(N)
	SegmentTree(int n, MonoidOp F, Monoid E) : F(F), E(E), sz(n) { dat.assign(sz * 2 + 1, E); }

	// vectorを基に構築 O(N)
	SegmentTree(const std::vector<Monoid>& vec, MonoidOp F, Monoid E) : F(F), E(E), sz(vec.size()) {
		dat.assign(sz * 2 + 1, E);
		for (int i = 0; i < sz; i++) dat[i + sz] = vec[i];
		for (int i = sz - 1; i > 0; i--) dat[i] = F(dat[i << 1 | 0], dat[i << 1 | 1]);
	}

	int size() { return sz; }

	const Monoid& operator[] (int idx) { return dat[idx + sz]; }

	// fold(l,l+1,...,r-1) を返す
	Monoid get(int l, int r) {
		l += sz; r += sz;
		Monoid lm(E), rm(E);
		while (l < r) {
			if (l & 1)lm = F(lm, dat[l++]);
			if (r & 1)rm = F(dat[--r], rm);
			l >>= 1; r >>= 1;
		}
		return F(lm, rm);
	}

	void set(int idx, Monoid x) {
		idx += sz; dat[idx] = x;
		while (idx > 1) {
			idx >>= 1;
			dat[idx] = F(dat[idx << 1 | 0], dat[idx << 1 | 1]);
		}
	}

	template<class DetermineFunc>
	int internal_search(Monoid sum, int i, DetermineFunc isOK) {
		while (i < sz) {
			Monoid tmp = F(sum, dat[i << 1]);
			if (isOK(tmp)) i = i << 1;
			else sum = tmp, i = (i << 1) | 1;
		}
		return i - sz;
	}

	// isOK(fold(l,l+1,...,r-1,r)) == 1 となる最小のrを求める
	template<class DetermineFunc>
	int search_r(DetermineFunc isOK, int l = 0) {
		l += sz;
		int r = sz * 2, tmp = 0;
		Monoid sum = E;
		for (int r_ = r; l < r_; r_ >>= 1, l >>= 1, tmp++) {
			if (l & 1) {
				if (isOK(F(sum, dat[l])))return internal_search(sum, l, isOK);
				sum = F(sum, dat[l]);
				l++;
			}
		}
		for (tmp -= 1; tmp >= 0; tmp--) {
			int r_ = r >> tmp;
			if (r_ & 1) {
				r_--;
				if (isOK(F(sum, dat[r_])))return internal_search(sum, r_, isOK);
				sum = F(sum, dat[r_]);
			}
		}
		return -1;
	}

	void dump() {
		for (int i = 0; i < dat.size(); i++) cout << dat[i] << (i != dat.size() ? " " : "\n");
	}
};

template<class Monoid, class MonoidOp>
SegmentTree<Monoid, MonoidOp> makeSegTree(int n, MonoidOp F, Monoid E) {
	return SegmentTree<Monoid, MonoidOp>(n, F, E);
}

template<class Monoid, class MonoidOp>
SegmentTree<Monoid, MonoidOp> makeSegTree(const std::vector<Monoid>& vec, MonoidOp F, Monoid E) {
	return SegmentTree<Monoid, MonoidOp>(vec, F, E);
}
