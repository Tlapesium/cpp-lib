#pragma once

template <class Monoid, class OperatorMonoid, class Operator, class Apply, class Merge >
struct DynamicLazySegmentTree {
	const Operator op;
	const Apply apply;
	const Merge merge;
	const Monoid IE;
	const OperatorMonoid OpIE;
	const int sz;

	struct Node {
		Monoid dat;
		OperatorMonoid lazy;
		Node* left, * right;
		Node(Monoid ie, OperatorMonoid opie) : dat(ie), lazy(opie), left(nullptr), right(nullptr) {}
	};

	Node* root;

	DynamicLazySegmentTree(int n, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) : op(F), apply(G), merge(H), IE(IE1), OpIE(IE2), sz(n), root(new Node(IE, OpIE)) {}

	// x を伝搬させる
	void propagate(Node* k, int l, int r) {
		k->dat = apply(k->dat, k->lazy, r - l);

		if (!k->left)k->left = new Node(IE, OpIE);
		k->left->lazy = merge(k->lazy, k->left->lazy);

		if (!k->right)k->right = new Node(IE, OpIE);
		k->right->lazy = merge(k->lazy, k->right->lazy);

		k->lazy = OpIE;
	}

	// 区間 [l,r) に x を作用
	void set(int l, int r, OperatorMonoid x, Node* k = nullptr, int a = 0, int b = -1) {
		if (!k)k = root;
		if (b < 0)b = sz;

		propagate(k, a, b);

		if (r <= a || b <= l)return;
		if (l <= a && b <= r) {
			k->lazy = merge(x, k->lazy);
			propagate(k, a, b);
		}
		else {
			set(l, r, x, k->left, a, (a + b) / 2);
			set(l, r, x, k->right, (a + b) / 2, b);
			k->dat = op(k->left->dat, k->right->dat);
		}
	}

	// 区間 [l,r) の積を取得
	Monoid get(int l, int r, Node* k = nullptr, int a = 0, int b = -1) {
		if (!k)k = root;
		if (b < 0)b = sz;

		propagate(k, a, b);

		if (r <= a || b <= l)return IE;
		if (l <= a && b <= r)return k->dat;

		return op(
			get(l, r, k->left, a, (a + b) / 2),
			get(l, r, k->right, (a + b) / 2, b)
		);
	}

	// isOK(fold(l,l+1,...,r-1)) == 1 となる最大のrを求める
	template<class DetermineFunc>
	int max_right(DetermineFunc isOK, int l = 0) {
		propagate(root, 0, sz);
		return max_right(isOK, l, root, 0, sz, IE);
	}

	template<class DetermineFunc>
	int max_right(DetermineFunc isOK, int l, Node* k, int a, int b, Monoid sum) {
		if (isOK(root->dat))return sz;
		if (b - a == 1) return a;

		propagate(k->left, a, (a + b) / 2);
		propagate(k->right, (a + b) / 2, b);

		if (isOK(op(sum, k->left->dat))) {
			sum = op(sum, k->left->dat);
			return max_right(isOK, l, k->right, (a + b) / 2, b, sum);
		}
		else {
			return max_right(isOK, l, k->left, a, (a + b) / 2, sum);
		}
	}

	void dump() {
		for (int i = 0; i < sz; i++)std::cout << get(i, i + 1) << (i == sz ? "\n" : " ");
	}

};

template <class Monoid, class OperatorMonoid, class Operator, class Apply, class Merge >
DynamicLazySegmentTree<Monoid, OperatorMonoid, Operator, Apply, Merge > makeDynamicLazySegTree(int n, Operator F, Apply G, Merge H, Monoid IE1, OperatorMonoid IE2) {
	return DynamicLazySegmentTree<Monoid, OperatorMonoid, Operator, Apply, Merge >(n, F, G, H, IE1, IE2);
}
