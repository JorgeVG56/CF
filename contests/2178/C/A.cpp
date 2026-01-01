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

    vector<ll> a(n); for(ll & x : a) cin >> x;

    int i = 0, j = 1;
    ll ans = 0;
    while(j < n){
      if(a[i] >= 0 && a[j] >= 0) ans += a[i], i = j, j = j + 1;
      else if(a[j] <= 0) ans -= a[j], j = j + 1;
      else if(a[i] + a[j] <)
    }
    cout << ans << '\n';
  }

  return 0;
}