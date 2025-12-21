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
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;

    for(int i = n - 2; i >= 0; i--) if(s[i] != s[n - 1]) ans++;

    cout << ans << '\n';
  }

  return 0;
}