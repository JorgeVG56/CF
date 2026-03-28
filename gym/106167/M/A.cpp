/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  double d, s, e; cin >> d >> s >> e;
  
  double ans = 0;

  for(double i = 0; i <= min(s, d - s - e); i++){
    ans = max(ans, (s - i) / d + i / (d - s - e) * (d - s) / d);
  }

  cout << setprecision(6) << ans << "\n";
  return 0;
}