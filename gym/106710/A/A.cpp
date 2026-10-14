#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n, q; cin >> n >> q;

  vector<ll> a(n); for(ll & x : a) cin >> x;
  vector<ll> dp(n); dp[n - 1] = a[n - 1];

  ll curSum = a[n - 1];
  for(int i = n - 2; i >= 0; i--) {
    curSum = max(a[i], curSum + a[i]);
    dp[i] = max(curSum, dp[i + 1]);
  }

  for(int i = 0; i < q; i++) {
    int x; cin >> x;
    cout << dp[x] << '\n';
  }

  return 0;
}
