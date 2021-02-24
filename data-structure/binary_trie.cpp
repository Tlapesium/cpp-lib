#pragma once
#include <utility>

template<class T, int MAX_LOG>
struct BinaryTrie {
	struct Node {
		Node* child[2];
		T lazy;
		int size;
		Node() : size(0), lazy(0), child{ nullptr, nullptr } {}
	};
	Node* root;
	BinaryTrie() { root = new Node(); }

	void insert(const T& x, Node* node, int bit_index) {
		propagate(node, bit_index);
		if (bit_index == -1) {
			node->size++;
		}
		else {
			auto& to = node->child[(x >> bit_index) & 1];
			if (!to) to = new Node();
			insert(x, to, bit_index - 1);
			node->size++;
		}
	}

	void erase(const T& x, Node* node, int bit_index) {
		propagate(node, bit_index);
		if (bit_index == -1) {
			node->size--;
		}
		else {
			erase(x, node->child[(x >> bit_index) & 1], bit_index - 1);
			node->size--;
		}
	}

	T max_element(Node* node, int bit_index) {
		propagate(node, bit_index);
		if (bit_index == -1) return T(0);
		if (node->child[1] && node->child[1]->size) {
			T ret = max_element(node->child[1], bit_index - 1);
			return ret | (T(1) << bit_index);
		}
		else {
			return max_element(node->child[0], bit_index - 1);
		}
	}

	T min_element(Node* node, int bit_index) {
		propagate(node, bit_index);
		if (bit_index == -1) return T(0);
		if (node->child[0] && node->child[0]->size) {
			return min_element(node->child[0], bit_index - 1);
		}
		else {
			T ret = min_element(node->child[1], bit_index - 1);
			return ret | (T(1) << bit_index);
		}
	}

	int count_less(const T& x, Node* node, int bit_index) {
		propagate(node, bit_index);
		if (bit_index == -1) return 0;
		if (x < 0)return 0;
		int ret = 0;
		if ((x >> bit_index) & 1) {
			if (node->child[0]) ret += node->child[0]->size;
			if (node->child[1]) ret += count_less(x, node->child[1], bit_index - 1);
		}
		else {
			if (node->child[0]) ret += count_less(x, node->child[0], bit_index - 1);
		}
		return ret;
	}

	T kth_element(int k, Node* node, int bit_index) { // 1-indexed
		propagate(node, bit_index);
		if (bit_index == -1)return T(0);
		if ((node->child[0] ? node->child[0]->size : 0) < k) {
			T ret = kth_element(k - (node->child[0] ? node->child[0]->size : 0), node->child[1], bit_index - 1);
			return ret | (T(1) << bit_index);
		}
		else {
			return kth_element(k, node->child[0], bit_index - 1);
		}
	}

	void propagate(Node* node, int bit_index) {
		if (bit_index >= 0 && (node->lazy >> bit_index) & 1) std::swap(node->child[0], node->child[1]);
		if (node->child[0]) node->child[0]->lazy ^= node->lazy;
		if (node->child[1]) node->child[1]->lazy ^= node->lazy;
		node->lazy = T(0);
	}

	void insert(const T& x) { insert(x, root, MAX_LOG); }
	void erase(const T& x) { erase(x, root, MAX_LOG); }
	T max_element() { return max_element(root, MAX_LOG); }
	T min_element() { return min_element(root, MAX_LOG); }
	int count_less(const T& x) { return count_less(x, root, MAX_LOG); }
	T kth_element(int k) { return kth_element(k, root, MAX_LOG); }
	int lower_bound(const T& x) { return count_less(x); }
	int upper_bound(const T& x) { return count_less(x + 1); }
	int find(const T& x) { return upper_bound(x) - lower_bound(x); }
	void all_xor(const T& x) { root->lazy ^= x; }
	int size() { return root->size; };

};
	