#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int t; cin >> t;
  
  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;
    
    vector<int> a(n); for(int & x : a) cin >> x;
    
    int totalActions = 0, target = a[0];
    for(int i = 1; i < n; i++){
      if(a[i] == target) continue;
      while(a[i] != target){
        if(target == 1 && a[i] == 2) totalActions++, a[i] = 1;
        else if(a[i] & 1 && a[i] == target - 1) totalActions++, a[i]++;
        else if(target & 1 && target == a[i] - 1) totalActions += i, target++;
        else if(a[i] > target) a[i] = (a[i] & 1 ? a[i] + 1 : a[i] >> 1), totalActions++;
        else target = (target & 1 ? target + 1 : target >> 1), totalActions += i;
      }
    }
    
    cout << totalActions << '\n';
  }
  
  return 0;
}