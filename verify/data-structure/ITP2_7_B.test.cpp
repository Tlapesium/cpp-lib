#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP2_7_B"
#include <bits/stdc++.h>
#include "data-structure/hashmap.cpp"
using namespace std;
typedef long long ll;

int main() {
	int Q;
	cin >> Q;
	HashMap<int, int> m;
	for (int i = 0; i < Q; i++) {
		int t, x;
		cin >> t >> x;
		if (t == 0) {
			m.insert(x, 1);
			cout << m.size() << endl;
		}
		else if (t == 1) {
			cout << m.contains(x) << endl;
		}
		else {
			m.erase(x);
		}
	}
}