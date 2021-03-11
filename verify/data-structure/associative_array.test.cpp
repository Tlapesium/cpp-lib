#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include <bits/stdc++.h>
#include "data-structure/hashmap.cpp"
using namespace std;
typedef long long ll;


int main() {
	HashMap<ll, ll> hm;
	int Q;
	cin >> Q;
	ll t, k, v;
	for (int i = 0; i < Q; i++) {
		cin >> t >> k;
		if (t) {
			cout << hm[k] << endl;
		}
		else {
			cin >> v;
			hm[k] = v;
		}
	}
}