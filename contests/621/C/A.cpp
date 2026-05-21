#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, p; cin >> n >> p;

  vector<pair<int, int>> a(n); for(auto & [l, r] : a) cin >> l >> r;

  vector<double> b(n); 
  for(int i = 0; i < n; i++){
    int l = (a[i].first - 1) / p;
    int r = (a[i].second) / p;
    b[i] = (r - l) / (a[i].second - a[i].first + 1.0);
  }

  double ans = 0;
  for(int i = 0; i < n; i++){
    double prob = (1 - b[i]) * (1 - b[(i + 1) % n]);
    ans += 2000 * (1 - prob);
  }

  cout << fixed << setprecision(6) << ans << '\n';

  return 0;
}