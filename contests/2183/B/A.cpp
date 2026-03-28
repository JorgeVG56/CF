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
    int n, k; cin >> n >> k;
    
    vector<int> a(n); for(int & x : a) cin >> x;

    set<int> st(begin(a), end(a));

    int mex = 0, fl = 0;
    for(auto & x : st) if(!fl && x != mex++) fl = 1;

    cout << min(mex - fl, k - 1) << '\n';
  }

  return 0;
}