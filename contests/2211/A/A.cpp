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
    int n; cin >> n;
    vector<int> a(n); for(int & x : a) cin >> x;
    for(int i = 0; i < n; i++) cout << min(2, n) << ' ';
    cout << '\n';
  }

  return 0;
}