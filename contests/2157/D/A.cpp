/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    int n, l, r; cin >> n >> l >> r;

    vector<ll> a(n); for(ll & x : a) cin >> x;
    sort(begin(a), end(a));
  
    ll ansL = 0, ansR = 0;
    for(ll & x : a) ansL += (x - l), ansR += (x - r);

    ll ans = min(ansL, ansR);
    for(ll & x : a){
      ansL -= (x - l), ansR -= (x - r);
      ans = max(ans, min(ansL, ansR));
      ansL -= (x - l), ansR -= (x - r);
      ans = max(ans, min(ansL, ansR));
    }

    cout << ans << '\n';
  }

  return 0;
}