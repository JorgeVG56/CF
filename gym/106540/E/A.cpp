#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  string _s;
  for(int i = 0; i < size(s); i++){
    if(s[i] != 'm') _s += s[i];
    else{
      if(i + 5 < size(s) && s[i + 1] == 'e' && s[i + 2] == 's' && s[i + 3] == 'e' && s[i + 4] == 'r' && s[i + 5] == 'o'){
        _s += "taquero";
        i += 5;
      } else{
        _s += s[i];
      }
    }
  }

  cout << _s << '\n';

  return 0;
}