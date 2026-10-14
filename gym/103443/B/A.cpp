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
  int n; cin >> n;
  string a, b; cin >> a >> b;

  vector<vector<int>> dp(n, vector<int>(n));
  for(int i = 0; i < n; i++) {
    dp[i][i] = int(a[i] == b[i]);
    if(i > 0) dp[i - 1][i] = int(a[i] == b[i - 1]) + int(b[i] == a[i - 1]);
  }

  for(int k = 0; k < n; k++) {
    for(int l = 1; l + k < n - 1; l++) {
      int r = l + k;
      dp[l - 1][r + 1] = max(dp[l - 1][r + 1], dp[l][r] + int(a[l - 1] == b[r + 1]) + int(b[l - 1] == a[r + 1]));
    }
  }

  vector<int> preffix(n + 1); 
  for(int i = 0; i < n; i++) preffix[i + 1] = preffix[i] + int(a[i] == b[i]);
  vector<int> suffix(n + 1); 
  for(int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + int(a[i] == b[i]);

  int bestAns = -1, i = -1, j = -1;
  for(int l = 0; l < n; l++) {
    for(int r = l; r < n; r++) {
      int curAns = preffix[l] + dp[l][r] + suffix[r + 1];
      if(curAns < bestAns) continue;
      if(curAns > bestAns) bestAns = curAns, i = l, j = r;
      else {
        if(j - i < r - l) continue;
        else if(j - i > r - l) j = r, i = l;
        else if(i > l) j = r, i = l;
      }
    }
  }

  cout << preffix[n] << ' ' << bestAns << ' ' << i + 1 << ' ' << j + 1 << '\n';
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while(t--) solve();

  return 0;
}
