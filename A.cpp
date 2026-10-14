#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e9;
const ll MOD = 998244353;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF)); 
  for(int i = 0; i < n; i++) dp[i][i] = 1, dp[i + 1][i] = 0;

  for(int k = 1; k < n; k++) {
    for(int i = 0; i + k < n; i++) {
      int j = i + k;
      dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);
      for(int l = i + 2; l <= j; l++) if(a[i] == a[l]) dp[i][j] = min(dp[i][j], dp[i + 1][l - 1] + dp[l + 1][j]);
      if(a[i] == a[i + 1]) dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
    }
  }

  cout << dp[0][n - 1] << '\n';

  return 0;
}
