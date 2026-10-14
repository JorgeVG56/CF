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
    ll x, y; cin >> x >> y;

    ll max = x + y, op = 0;
    for(int bit = 30; bit >= 0; bit--) {
      if((~max >> bit) & 1) continue;
      if((x >> bit) & 1) continue;
      if((y >> bit) & 1) continue;
      ll curY = y & ((1 << bit) - 1);
      ll needs = (1 << bit) - curY;
      x -= needs, y += needs, op += needs;
    }

    cout << max << ' ' << op << '\n';
  }
  
  return 0;
} 