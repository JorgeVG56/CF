/*
Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  
  vector<pair<double, double>> a(n); 
  for(auto & [x, v] : a) cin >> x;
  for(auto & [x, v] : a) cin >> v;
  
  auto f = [&](double mi) -> double {
    double l = 0, r = 1e9;
    for(auto & [x, v] : a) l = max(l, x - mi * v), r = min(r, x + mi * v);
    return l <= r;
  };
  
  double lo = 0, hi = 1e9;
  while(hi - lo > 1e-6){
    double mi = (lo + hi) / 2;

    if(f(mi)){
      hi = mi;
    } else{
      lo = mi;
    }
  }
  
  cout << fixed << setprecision(6) << lo << '\n';
  
  return 0;
}