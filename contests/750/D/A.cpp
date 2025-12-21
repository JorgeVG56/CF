/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  string s; cin >> s; cin >> s;

  if(s == "week"){
    cout << (52 + (n == 1));
  } else{
    if(n <= 28) cout << 12;
    else if(n < 31) cout << 11;
    else cout << 7;
  }

  return 0;
}