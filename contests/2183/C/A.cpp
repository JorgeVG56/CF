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
    ll n, m, k; cin >> n >> m >> k;
    
    ll ans = 1, l = (k == 1 ? (int) 1e9 + 5 : 1), r = (k == n ? (int) 1e9 + 5 : 1);
    while(l <= m || r <= m){
      ans ++;
      m -= min(l, r);
      if(l < r) l = (k - l == 1 ? (int)1e9 + 5 : l + 1);
      else r = (k + r == n ? (int)1e9 + 5 : r + 1);
    }

    cout << ans << '\n';
  }

  return 0;
}