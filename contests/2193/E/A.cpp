/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;

    vector<int> a(n); for(int & x : a) cin >> x;

    sort(begin(a), end(a));
    a.resize(unique(begin(a), end(a)) - begin(a));

    vector<int> dp(n + 1); dp[0] = dp[1] = (a[0] == 1 ? 1 : -1);
    for(int i = 0; i < size(a); i++) dp[a[i]] = 1;
    for(int i = 2; i <= n; i++){
      if(dp[i]) continue;

      dp[i] = 1e9;
      
      for(int j = 0; j < size(a) && a[j] * a[j] <= i; j++){
        if(i % a[j]) continue;
        if(dp[i / a[j]] != -1) dp[i] = min(dp[i], 1 + dp[i / a[j]]);
      }

      if(dp[i] == 1e9) dp[i] = -1;
    }

    for(int i = 1; i <= n; i++){
      cout << dp[i] << ' ';
    }

    cout << '\n';
  }

  return 0;
}