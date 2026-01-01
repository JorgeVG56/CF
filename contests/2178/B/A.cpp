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
    string s; cin >> s;

    int ans = 0;
    if(s[0] == 'u') ans++, s[0] = 's';
    if(s.back() == 'u') ans++, s.back() = 's';

    for(int i = 1; i < (int)size(s) - 1; i++) if(s[i] == 'u') ans += s[i + 1] == 'u', s[i + 1] = 's';

    cout << ans << '\n';
  }

  return 0;
}