#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
#include "data-structure/sparse_table.cpp"
using namespace std;
typedef long long ll;


int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> v(N);
	for (int i = 0; i < N; i++)cin >> v[i];
	SparseTable ST(v);
	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		cout << ST.get(l, r) << endl;
	}
}