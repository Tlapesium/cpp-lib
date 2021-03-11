#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include <bits/stdc++.h>
#include "data-structure/li_chao_tree.cpp"
using namespace std;
typedef long long ll;

constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
int main() {
    LiChaoTree<ll, -INF, INF> LCT;
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        LCT.add_line(a, b);
    }
    for (int i = 0; i < Q; i++) {
        ll t;
        cin >> t;
        if (t == 0) {
            ll a, b;
            cin >> a >> b;
            LCT.add_line(a, b);
        }
        else {
            ll p;
            cin >> p;
            cout << LCT.query(p) << endl;
        }
    }
}