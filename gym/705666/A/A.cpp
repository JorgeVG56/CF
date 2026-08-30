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

    vector<bool> kingdoms(n);
    vector<bool> daugthers(n);
    for(int i = 0; i < n; i++){
      int k; cin >> k;
      for(int j = 0; j < k; j++){
        int g; cin >> g; --g;
        if(daugthers[i]) continue;
        if(kingdoms[g]) continue;
        // cout << "PAIRING D[" << i << "] WITH KINGDOM[" << g << "]'\n";
        daugthers[i] = kingdoms[g] = true;
      }
    }

    int d = -1, k = -1;
    for(int i = 0; i < n; i++){
      if(!daugthers[i]) d = i + 1;
      if(!kingdoms[i]) k = i + 1;
    }

    if(d == -1) cout << "OPTIMAL" << '\n';
    else cout << "IMPROVE" << '\n' << d << ' ' << k << '\n';
  }

  return 0;
}