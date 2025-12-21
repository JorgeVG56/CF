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
    ll x, y, k; cin >> x >> y >> k;

    auto f = [&](ll m) -> bool{
      for(int i = 0; i < x && m >= k; i++) m -= m / y;
      return m >= k;
    };

    ll lo = 1, hi = (ll)1e12 + 1;
    while(lo < hi){
      ll mi = (lo + hi) >> 1;

      if(f(mi)){
        hi = mi - 1;
      } else{
        lo = mi + 1;
      }
    }

    if(hi == (ll)1e12 + 1) cout << -1 << '\n';
    else cout << hi + !f(hi) << '\n';
  }

  return 0;
}