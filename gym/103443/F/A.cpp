#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 998244353;
const int MAXN = 1e6 + 5;

struct Rectangle {
  ll x1, x2, y1, y2, c, z;
};

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n; cin >> n;

  vector<Rectangle> a(n);
  for(auto & r : a) cin >> r.x1 >> r.y1 >> r.x2 >> r.y2 >> r.c;
  
  int idx = 0;
  for(auto & r : a) r.z = idx++;
  for(auto & r : a) if(r.x1 > r.x2) swap(r.x1, r.x2);
  for(auto & r : a) if(r.y1 > r.y2) swap(r.y1, r.y2);

  set<ll> stX;
  for(auto & r : a) stX.insert(r.x1), stX.insert(r.x2);

  vector<ll> b(begin(stX), end(stX));
  vector<array<ll, 3>> c;
  for(auto & r : a) c.push_back({r.y1, r.c, r.z}), c.push_back({r.y2, -r.c, r.z});
  sort(begin(c), end(c));

  map<int, int> mp;
  vector<int> visibleColors(n);
  for(int i = 0; i < size(b) - 1; i++) {
    ll lastY = -1;
    for(auto & [y, c, z] : c) {
      if(a[z].x2 <= b[i] || a[z].x1 >= b[i + 1]) continue;
      if(lastY != -1 && y != lastY && !mp.empty()) visibleColors[mp.rbegin() -> second - 1] = 1;
      if(c > 0) mp[z] = c;
      else mp.erase(z);
      lastY = y;
    }
  }

  cout << accumulate(begin(visibleColors), end(visibleColors), 0) << '\n';

  return 0;
}
