/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;

  vector<int> a(n); for(auto & x : a) cin >> x;

  int ans = 0;

  for(auto & x : a) ans += (x + 1) >> 1;

  cout << ans;

  return 0;
}