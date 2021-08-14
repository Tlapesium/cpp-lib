#define PROBLEM "https://atcoder.jp/contests/abc194/tasks/abc194_e"
#include <bits/stdc++.h>
#include "data-structure/binary_trie.cpp"
using namespace std;
typedef long long ll;

int main() {	
	BinaryTrie<int, 30> BT;
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < M; i++)BT.insert(A[i]);
	int ans = BT.mex();
	for (int i = 0; i < N - M; i++) {
		BT.erase(A[i]);
		BT.insert(A[i + M]);
		ans = min(ans, BT.mex());
	}
	cout << ans << endl;
}