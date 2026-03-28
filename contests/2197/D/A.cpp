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

    int ans = 0;
    for(int j = 0; j < n; j++){
      for(int x = 1; j - x * a[j] >= 0 && x <= a[j]; x++){
        int i = j - a[j] * x;
        if(a[i] == x) ans ++;
      }

      for(int x = 1; j + x * a[j] < n && x <= a[j]; x++){
        int i = j + a[j] * x;
        if(a[i] == x && x != a[j]) ans ++;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}