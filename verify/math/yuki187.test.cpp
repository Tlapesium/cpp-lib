#define PROBLEM "https://yukicoder.me/problems/no/187"
#include "math/crt.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	bool flag = false;
	vector<ll> b(N), m(N);
	for (int i = 0; i < N; i++) {
		cin >> b[i] >> m[i];
		if (b[i])flag = true;
	}
	ll ans = crt(b, m, 1000000007);
	if (ans != -1 && !flag) {
		ans = 1;
		for (int i = 0; i < N; i++)ans = (ans * m[i]) % 1000000007;
	}
	cout << ans << endl;
}