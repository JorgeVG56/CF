#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    ll x1, y1, r1; cin >> x1 >> y1 >> r1;
    ll x2, y2, r2; cin >> x2 >> y2 >> r2;
    ll k; cin >> k;

    ll dx = x1 - x2, dy = y1 - y2, sr = r1 + r2, dr = r1 - r2;

    if(k <= 2 * r1 || k <= 2 * r2){
      cout << "YES" << '\n';
    } else if(dx * dx + dy * dy > sr * sr){
      cout << "NO" << '\n';
    } else if(dx * dx + dy * dy <= dr * dr){
      if(k <= 2 * max(r1, r2)) cout << "YES" << '\n';
      else cout << "NO" << '\n';
    } else{
      if((k - sr) * (k - sr) <= dx * dx + dy * dy) cout << "YES" << '\n';
      else cout << "NO" << '\n';
    }
  }

  return 0;
}