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
    ll s, m; cin >> s >> m;

    ll ans = 0;
    for(ll i = 60; i >= 0; i--){
      m &= ~(1ll << i);
      if(!m) break;
      ans += s / m;
      s -= (s / m) * m;
    }

    if(s == 0){
      cout << ans << '\n';
    } else{
      cout << -1 << '\n';
    }
  }

  return 0;
}