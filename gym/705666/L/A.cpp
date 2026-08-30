#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<ll> a(n); for(auto & x : a) cin >> x;
  vector<ll> b(n); for(auto & x : b) cin >> x;

  map<pair<ll, ll>, ll> mp;
  ll ans = 0, zeroCount = 0;

  for(int i = 0; i < n; i++){
    if(a[i] == 0 && b[i] == 0){
      zeroCount ++;
      continue;
    } else if(a[i] == 0){
      continue;
    } else if(b[i] == 0){
      ans = max(ans, ++mp[{0, 1}]);
    } else{
      ll gcd = __gcd(abs(a[i]), abs(b[i]));
      ll na = abs(a[i]) / gcd, nb = abs(b[i]) / gcd;
      if(a[i] * b[i] > 0) na *= -1;
      ans = max(ans, ++mp[{na, nb}]);
    }
  }

  cout << ans + zeroCount << '\n';

  return 0;
}