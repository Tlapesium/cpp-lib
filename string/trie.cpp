#pragma once

struct Trie {
	struct Node {
		int node_size;
		int subtree_size;
		Node* child[26];
		Node() : node_size(0), subtree_size(0) { for (int i = 0; i < 26; i++)child[i] = nullptr; }
	};

	Node* root = new Node();

	void insert(Node* node, int str_index, std::string& str) {
		if (str_index == str.size()) {
			node->node_size++;
			node->subtree_size++;
		}
		else {
			auto& to = node->child[str[str_index] - 'a'];
			if (!to)to = new Node();
			insert(to, str_index + 1, str);
			node->subtree_size++;
		}
	}

	std::string kth_element(Node* node, int k) {
		if (k <= node->node_size)return "";
		int sum = node->node_size;
		for (int i = 0; i < 26; i++) {
			if (sum + (node->child[i] ? node->child[i]->subtree_size : 0) >= k) {
				std::string ret = kth_element(node->child[i], k - sum);
				return char('a' + i) + ret;
			}
			else {
				sum += (node->child[i] ? node->child[i]->subtree_size : 0);
			}
		}
		return "";
	}

	int prefix_count(Node* node, int str_index, std::string& str) {
		if (str_index == str.size()) {
			return node->subtree_size;
		}
		else {
			auto& to = node->child[str[str_index] - 'a'];
			if (!to)return 0;
			return prefix_count(to, str_index + 1, str);
		}
	}

	void insert(std::string& str) {
		insert(root, 0, str);
	}

	std::string kth_element(int k) {
		return kth_element(root, k);
	}

	int prefix_count(std::string& str) {
		return prefix_count(root, 0, str);
	}

};