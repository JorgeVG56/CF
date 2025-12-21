/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  vector<string> a(7); for(string & s : a) cin >> s;

  int d, h; cin >> d >> h;

  double ans = 0;

  for(int mask = (1 << 7) - 1; mask >= 0; mask--){
    int days = __builtin_popcount(mask);
    
    if(days != d) continue;

    vector<double> b(24);
    for(int j = 0; j < 24; j++){
      for(int k = 0; k < 7; k++){
        if((mask >> k) & 1) b[j] += (double)(a[k][j] == '.') / days;
      }
    }

    sort(rbegin(b), rend(b));

    double currentAns = accumulate(begin(b), begin(b) + h, 0.0) / h;
    ans = max(ans, currentAns);
  }

  cout << ans;

  return 0;
}