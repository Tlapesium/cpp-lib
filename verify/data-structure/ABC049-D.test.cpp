#define PROBLEM "https://atcoder.jp/contests/arc065/tasks/arc065_b"
#include <bits/stdc++.h>
#include "data-structure/union_find.cpp"
using namespace std;
typedef long long ll;

int main() {
	int N, K, L;
	cin >> N >> K >> L;
	UnionFind UF1(N), UF2(N);
	for (int i = 0; i < K; i++) {
		int p, q;
		cin >> p >> q;
		UF1.merge(p - 1, q - 1);
	}
	for (int i = 0; i < L; i++) {
		int p, q;
		cin >> p >> q;
		UF2.merge(p - 1, q - 1);
	}
	map<pair<int, int>, int> cnt;
	for (int i = 0; i < N; i++) {
		cnt[{UF1.root(i), UF2.root(i)}]++;
	}
	for (int i = 0; i < N; i++) {
		cout << cnt[{UF1.root(i), UF2.root(i)}] << ' ';
	}
    cout << endl;
}
