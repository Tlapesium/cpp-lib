#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "data-structure/binary_trie.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	BinaryTrie<int, 31> BT;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int t, x;
		cin >> t >> x;
		if (t == 0) {
			if (!BT.find(x)) BT.insert(x);
		}
		if (t == 1) {
			if (BT.find(x)) BT.erase(x);
		}
		if (t == 2) {
			BT.all_xor(x);
			cout << BT.min_element() << endl;
			BT.all_xor(x);
		}
	}
}