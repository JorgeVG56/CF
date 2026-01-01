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

  vector<vector<int>> b;
  for(int i = 0; i < n; i++){
    int lo = 0, hi = (int)size(b);
    while(lo < hi){
      int mi = (lo + hi) >> 1;
      if(b[mi].back() < a[i]) hi = mi;
      else lo = mi + 1;
    }

    if(lo == (int)size(b)) b.push_back({a[i]});
    else b[lo].push_back(a[i]);
  }

  for(auto & v : b){
    for(auto & x : v) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}