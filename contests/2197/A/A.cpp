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
    int x; cin >> x;

    int ans = 0;
    for(int y = x; y < x + 100; y++){
      int a = y, b = y;
      for(int j = 0; j < 10; j++){ a -= b % 10; b /= 10; }
      if(a == x) ans++;
    }

    cout << ans << '\n';
  }

  return 0;
}