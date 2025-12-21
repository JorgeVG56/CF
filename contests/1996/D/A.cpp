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
    int n, x; cin >> n >> x;

    ll ans = 0;

    for(int a = 1; a <= x; a++){
      for(int b = 1; b <= n / a && a + b <= x; b++){
        int c1 = (n - a * b) / (a + b), c2 = x - a - b;
        ans += min(c1, c2);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}