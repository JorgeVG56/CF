#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n, m; cin >> n >> m;

    vector<int> a(n); for(int & x : a) cin >> x;
    int largest = -1; for(int i = 0; i < n; i++) if(a[i] != i + 1) largest = i + 1;
    double ans = largest != -1;
    for(int i = 0; i < m; i++){
      int r; double p; cin >> r >> p;
      if(r >= largest) ans *= (1 - p);
    }

    cout << fixed << setprecision(6) << (1 - ans) << '\n';
  }

  return 0;
}