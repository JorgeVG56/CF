/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n, k; cin >> n >> k;

  vector<pair<ll, ll>> a(n); for(pair<ll, ll> & p : a) cin >> p.first >> p.second;

  ll minR = a[0].first, maxR = a[0].first;
  ll minC = a[0].second, maxC = a[0].second;

  for(pair<ll, ll> & p : a){
    minR = min(minR, p.first), maxR = max(maxR, p.first);
    minC = min(minC, p.second), maxC = max(maxC, p.second);
  }

  ll area = (maxR - minR + 1) * (maxC - minC + 1);

  ll dx [] = {1, 1, -1, -1};
  ll dy [] = {1, -1, 1, -1};

  for(pair<ll, ll> & p : a){
    for(ll i = 0; i < 4; i++){
      ll auxMinR = min(minR, p.first + k * dx[i]), auxMaxR = max(maxR, p.first + k * dx[i]);
      ll auxMinC = min(minC, p.second + k * dy[i]), auxMaxC = max(maxC, p.second + k * dy[i]);

      area = max(area, (auxMaxR - auxMinR + 1) * (auxMaxC - auxMinC + 1));
    }
  }

  ll r = (maxR - minR + 1);
  ll c = (maxC - minC + 1);
  ll delta = abs(c - r);

  if(r < c) r += min(delta, k);
  else c += min(delta, k);

  k -= delta;

  if(k > 0){
    r += (k + 1) / 2;
    c += k / 2;
  }

  area = max(area, r * c);

  if(n == 1) area = 1;

  cout << area << '\n';

  return 0;
}