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
    ll p, q; cin >> p >> q;

    if(p >= q) cout << "Alice" << '\n';
    else if((q - p) * 2 <= p) cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
  }

  return 0;
}