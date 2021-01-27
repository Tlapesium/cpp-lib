#pragma once
#include <vector>
#include <iostream>

/**
 * @title Lazy Segment Tree
 */

template <class Monoid, class OperatorMonoid, class Operator, class Apply, class Merge >
struct LazySegmentTree {
	std::vector<Monoid> dat;
	std::vector<OperatorMonoid> lazy;

	const Operator op;
	const Apply apply;
	const Merge merge;
	const Monoid IE;
	const OperatorMonoid OpIE;
	const int sz;
	int height = 0;


	// 単位元で初期化された遅延セグ木を構築 O(N)
	LazySegmentTree(int n, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) : op(F), apply(G), merge(H), IE(IE1), OpIE(IE2), sz(n) {
		dat.assign(sz * 2 + 1, IE);
		lazy.assign(sz * 2 + 1, OpIE);
		while ((1 << height) <= sz)height++;
	}

	// vectorを基に構築 O(N)
	LazySegmentTree(const std::vector<Monoid>& vec, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) : op(F), apply(G), merge(H), IE(IE1), OpIE(IE2), sz(vec.size()) {
		dat.assign(sz * 2 + 1, IE);
		lazy.assign(sz * 2 + 1, OpIE);
		while ((1 << height) <= sz)height++;
		for (int i = 0; i < sz; i++) dat[i + sz] = vec[i];
		for (int i = sz - 1; i > 0; i--) dat[i] = op(dat[i << 1 | 0], dat[i << 1 | 1]);
	}

	int size() { return sz; }
	const Monoid& operator[] (int idx) { return get(idx, idx + 1); }


	// x を伝搬させる
	void propagate(int x) {
		if (x < sz) {
			lazy[x << 1 | 0] = merge(lazy[x], lazy[x << 1 | 0]);
			lazy[x << 1 | 1] = merge(lazy[x], lazy[x << 1 | 1]);
		}
		dat[x << 1 | 0] = apply(dat[x << 1 | 0], lazy[x]);
		dat[x << 1 | 1] = apply(dat[x << 1 | 1], lazy[x]);
		lazy[x] = OpIE;
	}

	// x を再計算する
	void update(int x) {
		dat[x] = op(dat[x << 1 | 0], dat[x << 1 | 1]);
	}

	// 区間 [l,r) に x を作用
	void set(int l, int r, OperatorMonoid x) {
		if (l >= r)return;
		l += sz; r += sz;

		for (int i = height; i >= 1; i--) {
			if (((l >> i) << i) != l) propagate(l >> i);
			if (((r >> i) << i) != r) propagate((r - 1) >> i);
		}

		for (int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {
			if (l2 & 1) {
				if (l2 < sz)lazy[l2] = merge(x, lazy[l2]);
				dat[l2] = apply(dat[l2], x);
				l2++;
			}
			if (r2 & 1) {
				r2--;
				if (r2 < sz)lazy[r2] = merge(x, lazy[r2]);
				dat[r2] = apply(dat[r2], x);
			}
		}

		for (int i = 1; i <= height; i++) {
			if (((l >> i) << i) != l) update(l >> i);
			if (((r >> i) << i) != r) update((r - 1) >> i);
		}
	}

	// 区間 [l,r) の積を取得
	Monoid get(int l, int r) {
		l += sz; r += sz;

		for (int i = height; i >= 1; i--) {
			if (((l >> i) << i) != l) propagate(l >> i);
			if (((r >> i) << i) != r) propagate(r >> i);
		}

		Monoid lm(IE), rm(IE);
		for (int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {
			if (l2 & 1) lm = op(lm, dat[l2++]);
			if (r2 & 1) rm = op(dat[--r2], rm);
		}
		return op(lm, rm);
	}

	void dump() {
		for (int i = 0; i < sz; i++)std::cout << get(i, i + 1) << (i == sz ? "\n" : " ");
	}

	// TODO: 2分探索を実装する
};


template <class Monoid, class OperatorMonoid, class Operator, class Apply, class Merge >
LazySegmentTree<Monoid, OperatorMonoid, Operator, Apply, Merge > makeLazySegTree(int n, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) {
	return LazySegmentTree<Monoid, OperatorMonoid, Operator, Apply, Merge >(n, F, G, H, IE1, IE2);
}

template <class Monoid, class OperatorMonoid, class Operator, class Apply, class Merge >
LazySegmentTree<Monoid, OperatorMonoid, Operator, Apply, Merge > makeLazySegTree(const std::vector<Monoid>& vec, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) {
	return LazySegmentTree<Monoid, OperatorMonoid, Operator, Apply, Merge >(vec, F, G, H, IE1, IE2);
}
