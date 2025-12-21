/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    string s; cin >> s;
    int n = (int)s.size();

    bool fl;
    for(int l = n / 4; l >= 1; l--){
      for(int i = 0; i < n - l * 3; i++){
        fl = true;
        for(int j = 0; j < l; j++){
          fl = (fl && s[i + j] == s[i + 2 * l - 1 - j]);
        }
        if(!fl) continue;
        for(int j = 0; j < l; j++){
          fl = (fl && s[2 * l + i + j] == s[2 * l + i + 2 * l - 1 - j]);
        }
        if(fl) break;
      }
      if(fl){
        cout << l * 4 << '\n';
        break;
      }
    }

    if(!fl){
      cout << 0 << '\n';
    }
  }

  return 0;
}