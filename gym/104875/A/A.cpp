/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n, s; cin >> n >> s;

  vector<ll> a(n); for(auto & x : a) cin >> x;

  if(s <= 2 || n <= 2){
    cout << min(s, n);
    return 0;
  }

  sort(begin(a), end(a));
  a.pop_back(); a.pop_back(); 
  s -= 2, n -= 2;

  auto query = [&](ll k) -> ll{
    vector<ll> b[3];
    for(ll i = 0; i <= k; i++) b[a[i] % 3].push_back(a[i] / 3);
    
    ll totalLength = accumulate(begin(b[0]), end(b[0]), 0ll);

    int w = min(b[1].size(), b[2].size());
    
    for(int i = 0; i < w; i++) totalLength += b[1][i] + b[2][i] + 1;

    int fl = 1;
    for(int i = w; i < b[1].size(); i++){
      totalLength += b[1][i] + fl;
      fl ^= 1;
    }
    
    for(int i = w; i < b[2].size(); i++) totalLength += b[2][i] + 1;
    
    return totalLength;
  };

  ll ans = 0; 

  ll lower = 0, higher = n - 1;
  while(lower <= higher){
    ll mid = (lower + higher) >> 1;

    if(query(mid) <= s){
      ans = max(ans, mid);
      lower = mid + 1;
    } else{
      higher = mid - 1;
    }
  }

  cout << ans + 3 << '\n';

  return 0;
}