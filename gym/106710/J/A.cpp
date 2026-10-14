#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n, k; cin >> n >> k;

  vector<ll> a(n); for(ll & x : a) cin >> x;

  vector<ll> preffix(n); preffix[0] = a[0];
  for(int i = 1; i < n; i++) preffix[i] = preffix[i - 1] + a[i];

  auto sum = [&](int l, int r) -> ll {
    return preffix[r] - (l == 0 ? 0 : preffix[l - 1]);
  };

  auto cost = [&](int l, int r) -> ll {
    int m = (l + r) >> 1;
    return (m - l + 1) * a[m] - sum(l, m) + sum(m, r) - (r - m + 1) * a[m];
  };
  
  vector<vector<ll>> dp(n, vector<ll>(k + 1, INF)); 
  for(int i = 0; i < n; i++) dp[i][1] = cost(0, i);
  
  auto solve = [&](auto & self, int l, int r, int optL, int optR, int j) -> void {
    if(r < l) return;
    int m = (l + r) >> 1;
    int bestP = optL;
    for(int i = optL + 1; i <= min(m - 1, optR); i++) {
      if(dp[i][j - 1] + cost(i + 1, m) < dp[bestP][j - 1] + cost(bestP + 1, m))
        bestP = i;
    }
    dp[m][j] = dp[bestP][j - 1] + cost(bestP + 1, m);
    self(self, l, m - 1, optL, bestP, j);
    self(self, m + 1, r, bestP, optR, j);
  }; 
  
  for(int i = 2; i <= k; i++) solve(solve, 0, n - 1, 0, n - 1, i);
  cout << dp[n - 1][k] << '\n';
  
  return 0;
}
