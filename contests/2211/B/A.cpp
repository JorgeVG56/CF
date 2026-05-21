/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 676767677;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int x, y; cin >> x >> y;

    if(x == y){
      cout << 1 << '\n';
      for(int i = 0; i < x; i++) cout << 1 << ' ';
      for(int i = 0; i < y; i++) cout << -1 << ' ';
      cout << '\n';
    } else{
      int ans = 0;
      for(int i = 1; i <= abs(x - y); i++)
        if(abs(x - y) % i == 0) ans++;
      cout << ans % mod << '\n';
      for(int i = 0; i < x; i++) cout << 1 << ' ';
      for(int i = 0; i < y; i++) cout << -1 << ' ';
      cout << '\n';
    }
  }

  return 0;
}