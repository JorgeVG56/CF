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
    ll n, x, y; cin >> n >> x >> y;

    string s; cin >> s;

    x = abs(x), y = abs(y);

    if(x > n || y > n){
      cout << "NO" << '\n';
      continue;
    }

    int cnt4 = 0, cnt8 = 0;
    for(char c : s){
      if(c == '4') cnt4++;
      else cnt8++;
    }

    if(x + y <= cnt4 + (2 * cnt8)){
      cout << "YES" << '\n';
    } else{
      cout << "NO" << '\n';
    }
  }

  return 0;
}