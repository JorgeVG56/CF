/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n, m; cin >> n >> m;

    vector<pair<int, int>> a(m); for(pair<int, int> & p : a) cin >> p.first >> p.second;

    vector<int> b(n);
    for(auto & p : a){
      auto [l, r] = p;

      b[r - 1] = max(b[r - 1], l);
    }

    vector<ll> dp(n); dp[0] = 1;

    for(int i = 1; i < n; i++){
      ll sub = 0;
      if(b[i]) sub = dp[b[i] - 1];
      dp[i] = (2 * dp[i - 1] % mod - sub + mod) % mod;
    }

    cout << 2 * dp[n - 1] % mod << '\n';
  }

  return 0;
}