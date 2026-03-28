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

    int mxElement = *max_element(begin(a), end(a));
    cout << mxElement * n << '\n';
  }

  return 0;
}