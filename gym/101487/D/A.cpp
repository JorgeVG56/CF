#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;
    
    vector<int> a(n); for(int & x : a) cin >> x;

    vector<array<int, 2>> dp(n); dp[0][0] = dp[0][1] = 1;
    vector<int> heads = {0, a[0]};
    int ans = 1;
    for(int i = 1; i < n; i++) {
      if(a[i] > a[i - 1]) dp[i][0] = dp[i - 1][0] + 1, dp[i][1] = dp[i - 1][1] + 1;
      else dp[i][0] = 1, dp[i][1] = 1;

      int size = lower_bound(begin(heads), end(heads), a[i]) - begin(heads);
      if(dp[i][0] == heads.size()) heads.push_back(a[i]);
      else if(a[i] < heads[dp[i][0]]) heads[dp[i][0]] = a[i];
      
      dp[i][1] = max(dp[i][1], size);

      ans = max({ans, dp[i][0], dp[i][1]});
    }

    cout << ans << '\n';
  }

  return 0;
}