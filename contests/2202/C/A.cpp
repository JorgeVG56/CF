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
    vector<ll> a(n); for (ll & x : a) cin >> x;
    
    ll cnt = 1, startGen = 0, maxGen = a[0];
    for (int i = 1; i < n; i++) {
      ll delta = a[i] - a[startGen];
      if (delta > 0 && delta <= (ll)(i - startGen) && a[i] <= a[i - 1] + 1) {
        maxGen = max(maxGen, a[i]);
      } else {
        cnt++;
        startGen = i;
        maxGen = a[i];
      }
    }

    cout << cnt << '\n';
  }
  
  return 0;
}