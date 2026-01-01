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

    int cnt = 0; for(char c : s) cnt += c == 'Y';

    cout << (cnt < 2 ? "YES" : "NO") << '\n';
  }

  return 0;
}