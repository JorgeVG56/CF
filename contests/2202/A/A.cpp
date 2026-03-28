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
    ll x, y; cin >> x >> y;

    if(y < 0) x -= y * -4;
    else x -= y * 2;

    if(x >= 0 && x % 3 == 0) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }

  return 0;
}