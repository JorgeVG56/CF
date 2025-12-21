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
    ll a, b, n; cin >> a >> b >> n;

    if(b == a) cout << 1 << '\n';
    else if(b * n <= a) cout << 1 << '\n';
    else cout << 2 << '\n';
  }

  return 0;
}