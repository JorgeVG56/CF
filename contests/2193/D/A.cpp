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

    vector<ll> a(n); for(auto & x : a) cin >> x;
    vector<ll> b(n); for(auto & x : b) cin >> x;
    
    sort(begin(a), end(a));
    for(int i = 1; i < n; i++) b[i] += b[i - 1];

    ll ans = 0;
    for(auto it = begin(a); it != end(a); it = upper_bound(begin(a), end(a), *it)){
      ll usableSwords = n - (it - begin(a));
      ll finalLevel = upper_bound(begin(b), end(b), usableSwords) - begin(b);
      ans = max(ans, finalLevel * (*it));
    }

    cout << ans << '\n';
  }

  return 0;
}