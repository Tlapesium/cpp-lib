#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0580"
#include <bits/stdc++.h>
#include "utility/compress.cpp"
using namespace std;
typedef long long ll;

int main() {
	int N, K;
	cin >> N >> K;
	vector<pair<tuple<ll, ll, ll>, tuple<ll, ll, ll>>> fish;
	Compress<ll> X, Y, Z;
	vector count(N * 2, vector(N * 2, vector(N * 2, 0)));
	for (int i = 0; i < N; i++) {
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		X.add(x1); Y.add(y1); Z.add(z1);
		X.add(x2); Y.add(y2); Z.add(z2);
		fish.push_back({ {x1,y1,z1},{x2,y2,z2} });
	}
	X.build(); Y.build(); Z.build();
	for (int i = 0; i < N; i++) {
		auto [p1, p2] = fish[i];
		auto [x1, y1, z1] = p1;
		auto [x2, y2, z2] = p2;
		for (int x = X[x1]; x < X[x2]; x++) {
			for (int y = Y[y1]; y < Y[y2]; y++) {
				for (int z = Z[z1]; z < Z[z2]; z++) {
					count[x][y][z]++;
				}
			}
		}
	}
	ll ans = 0;
	for (int x = 0; x < 2 * N; x++)for (int y = 0; y < 2 * N; y++)for (int z = 0; z < 2 * N; z++) {
		if (count[x][y][z] >= K) {
			ans += (X(x + 1) - X(x)) * (Y(y + 1) - Y(y)) * (Z(z + 1) - Z(z));
		}
	}
	cout << ans << endl;
}