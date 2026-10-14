#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define int ll
const ll INF = 4e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    ll x, y, k; cin >> x >> y >> k;

    ll ans = 0;
    while(k > 0 && x * 2 <= y) {
      ans += (y % x);
      k--, x++, y++;
    }

    ans += k * (y - x);

    cout << ans << '\n';
  }
  
  return 0;
} 