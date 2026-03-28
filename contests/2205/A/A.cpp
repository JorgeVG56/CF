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
    int n, m, d; cin >> n >> m >> d;

    int ans = 0;
    while(n >= 1){
      ans++;
      n -= (d / m) + 1;
    }

    cout << ans << '\n';
  }

  return 0;
}