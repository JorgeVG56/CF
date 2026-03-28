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
    int n, s, x; cin >> n >> s >> x;

    vector<int> a(n); for(auto & x : a) cin >> x;

    int sum = accumulate(begin(a), end(a), 0);

    if(sum > s || (s - sum) % x) cout << "No" << '\n';
    else cout << "Yes" << '\n';
  }

  return 0;
}