#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define int ll
const ll INF = 4e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;

  vector<ll> c(n), k(n);
  for(ll & x : c) cin >> x;
  for(ll & x : k) cin >> x;

  ll total = accumulate(begin(c), end(c), 0ll);

  ll ans = 0, fl = 1;
  for(int i = 0; i < n; i++) {
    if(c[i] < k[i]) fl = 0;
    ans = max(ans, total - c[i] + k[i]);
  }

  return 0;
} 