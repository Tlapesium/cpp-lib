#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"
#include <bits/stdc++.h>
#include "data-structure/union_find.cpp"
using namespace std;
typedef long long ll;

int main() {
	int N, Q;
	cin >> N >> Q;
	UnionFind UF(N);
	for (int i = 0; i < Q; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			int x, y, z;
			cin >> x >> y >> z;
			UF.merge(x, y, z);
		}
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			if (UF.issame(x, y)) {
				cout << UF.diff(x, y) << endl;
			}
			else {
				cout << "?" << endl;
			}
		}
	}
}