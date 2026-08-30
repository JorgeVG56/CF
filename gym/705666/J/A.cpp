#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> l(n), r(n);

  for(int i = 0; i < n; i++){
    cin >> l[i] >> r[i];
  }

  for(int i = 0; i < n; i++){
    if(l[i] != 0) continue;
    
    int u = i + 1;
    for(int j = 0; j < n; j++){
      if(r[u - 1] != 0) u = r[u - 1];
      else{
        for(int k = 0; k < n; k++){
          if(l[k] != 0 || k == i) continue;
          r[u - 1] = k + 1;
          l[k] = u;
          break;
        }
        u = r[u - 1];
      }
    }
    break;
  }

  for(int i = 0; i < n; i++) cout << l[i] << ' ' << r[i] << '\n';

  return 0;
}