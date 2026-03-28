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
    
    vector<ll> a(n << 1); for(auto & x : a) cin >> x;
    
    bool fl = 1;
    sort(rbegin(a), rend(a));
    for(int i = 0; i < n; i++){
      if(a[i << 1] != a[(i << 1) + 1] || (i > 0 && a[i << 1] == a[(i << 1) - 1])){
        fl = 0;
        break;
      }
    }

    unique(begin(a), end(a)) - begin(a);
    
    ll curSum = 0;
    
    for(int i = 0; i < n; i++){
      ll needsToSum = a[i] - (curSum << 1);
      if(needsToSum <= 0 || needsToSum % ((n - i) << 1)){ fl = 0; break; }
      curSum += needsToSum / ((n - i) << 1);
    }
    
    cout << (fl ? "YES" : "NO") << '\n';
  }
  
  return 0;
}