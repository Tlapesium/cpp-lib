#pragma once

template <class Monoid, class Operator>
struct SegmentTree {
	std::vector<Monoid> dat;

	const Operator op;
	const Monoid IE;
	const int sz;

	// 単位元で初期化されたセグ木を構築 O(N)
	SegmentTree(int n, Operator F, Monoid IE) : op(F), IE(IE), sz(n) { dat.assign(sz * 2 + 1, IE); }

	// vectorを基に構築 O(N)
	SegmentTree(const std::vector<Monoid>& vec, Operator F, Monoid IE) : op(F), IE(IE), sz(vec.size()) {
		dat.assign(sz * 2 + 1, IE);
		for (int i = 0; i < sz; i++) dat[i + sz] = vec[i];
		for (int i = sz - 1; i > 0; i--) dat[i] = op(dat[i << 1 | 0], dat[i << 1 | 1]);
	}

	int size() { return sz; }
	const Monoid& operator[] (int idx) { return dat[idx + sz]; }

	// 区間 [l,r) の積を取得
	Monoid get(int l, int r) {
		l += sz; r += sz;
		Monoid lm(IE), rm(IE);
		while (l < r) {
			if (l & 1)lm = op(lm, dat[l++]);
			if (r & 1)rm = op(dat[--r], rm);
			l >>= 1; r >>= 1;
		}
		return op(lm, rm);
	}

	// 要素 idx を x に更新
	void set(int idx, Monoid x) {
		idx += sz; dat[idx] = x;
		while (idx > 1) {
			idx >>= 1;
			dat[idx] = op(dat[idx << 1 | 0], dat[idx << 1 | 1]);
		}
	}

	template<class DetermineFunc>
	int internal_search(Monoid sum, int i, DetermineFunc isOK) {
		while (i < sz) {
			Monoid tmp = op(sum, dat[i << 1]);
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
		Monoid sum = IE;
		for (int r_ = r; l < r_; r_ >>= 1, l >>= 1, tmp++) {
			if (l & 1) {
				if (isOK(op(sum, dat[l])))return internal_search(sum, l, isOK);
				sum = op(sum, dat[l]);
				l++;
			}
		}
		for (tmp -= 1; tmp >= 0; tmp--) {
			int r_ = r >> tmp;
			if (r_ & 1) {
				r_--;
				if (isOK(op(sum, dat[r_])))return internal_search(sum, r_, isOK);
				sum = op(sum, dat[r_]);
			}
		}
		return -1;
	}

	void dump() {
		for (int i = 0; i < dat.size(); i++) std::cout << dat[i] << (i != dat.size() ? " " : "\n");
	}
};

template<class Monoid, class Operator>
SegmentTree<Monoid, Operator> makeSegTree(int n, Operator F, Monoid IE) {
	return SegmentTree<Monoid, Operator>(n, F, IE);
}

template<class Monoid, class Operator>
SegmentTree<Monoid, Operator> makeSegTree(const std::vector<Monoid>& vec, Operator F, Monoid IE) {
	return SegmentTree<Monoid, Operator>(vec, F, IE);
}
