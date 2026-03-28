/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;

  vector<pair<ll, ll>> a(n); 
  for(auto & [x, y] : a) cin >> x;
  for(auto & [x, y] : a) cin >> y;

  vector<vector<ll>> b(2e5 + 5);
  vector<ll> c(2e5 + 5);
  for(auto & [x, y] : a){
    if(b[y].empty()) b[y].push_back(0);
    b[y].push_back(x + b[y].back());
  }

  ll m; cin >> m;
  
  ll total = 0;

  auto bs = [&] (ll col, ll x) -> ll {
    ll lo = 0, hi = (ll)size(b[col]);
    while(lo < hi){
      ll mi = (lo + hi) >> 1;
      if(mi * (total - c[col]) + b[col][mi] <= x) lo = mi + 1;
      else hi = mi;
    }
    return lo - 1;
  };

  for(ll i = 0; i < m; i++){
    ll type, col, x; cin >> type >> col >> x;
    
    if(type == 1) c[col] += x, total += x;
    else cout << bs(col, x) << '\n';
  }

  return 0;
}