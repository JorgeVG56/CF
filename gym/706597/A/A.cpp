#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;

    vector<int> a(n); for(int & x : a) cin >> x;

    int ans = 0, mx = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
      if(a[i] <= mx) continue;
      ans++;
      mx = a[i];
    }

    cout << ans << '\n';
  }

  return 0;
}