#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 998244353;
const int MAXN = 1e6 + 5;

void solve() {
  int x, y; cin >> x >> y;
  int n; cin >> n;

  int buying = n / (x + y);
  int cost = buying * x * 3;
  n -= buying * (x + y);
  cost += min(n, x) * 3;

  cout << cost << '\n';
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while(t--) solve();

  return 0;
}
