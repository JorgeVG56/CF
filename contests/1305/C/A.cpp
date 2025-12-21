/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<ll> a(n); for(ll & x : a) cin >> x;

  if(n > m){
    cout << 0 << '\n';
    return 0;
  }

  ll ans = 1;

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      ll dif = abs(a[i] - a[j]);
      ans = (1ll * ans * dif) % m;
    }
  }

  cout << ans << '\n'; 

  return 0;
}