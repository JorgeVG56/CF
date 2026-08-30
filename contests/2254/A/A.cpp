#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int a, b, c; cin >> a >> b >> c;

    int mn = min({a, b, c}), mx = max({a, b, c});
    int md = a + b + c - mn - mx;
    cout << min(md - mn, mx - md) << '\n';
  }

  return 0;
}