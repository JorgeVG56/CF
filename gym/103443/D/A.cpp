#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 998244353;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  ll d, k; cin >> d >> k;
  vector<ll> a(d); for(ll & x : a) cin >> x;

  // 8192 * 4 * 6400
  ll totalMask = (1 << d), maxMask = (1 << 16);
  vector<vector<ll>> dp(totalMask, vector<ll>(k, -1)); dp[0][0] = 0;
  for(ll mask = 0; mask < totalMask; mask++) {
    for(int i = 0; i < k; i++) {
      if(dp[mask][i] == -1) continue;
      for(ll j = 0; j < d; j++) {
        if((mask >> j) & 1) continue;
        ll newMask = mask ^ (1 << j);
        ll newK = (i * 10 + a[j]) % k;
        dp[newMask][newK] = max(dp[newMask][newK], dp[mask][i] * 10ll + a[j]);
      }
    }
  }

  for(int i = k - 1; i >= 0; i--) {
    if(dp[totalMask - 1][i] == -1) continue;
    cout << dp[totalMask - 1][i] << '\n';
    break;
  }

  return 0;
}
