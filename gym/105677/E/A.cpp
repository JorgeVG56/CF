#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n; cin >> n;

  map<ll, vector<ll>> mp;
  ll minX = INF, maxX = 0;
  for(int i = 0; i < n; i++) {
    ll x, y; cin >> x >> y;
    mp[x].push_back(y);
    minX = min(minX, x);
    maxX = max(maxX, x);
  }

  if(minX == maxX) {
    auto & v = mp[minX];
    cout << v.size() + 1 << '\n';
    sort(begin(v), end(v));
    for(auto & y : v) cout << minX << ' ' << y << '\n';
    cout << minX + (minX == 1 ? 1 : -1) << ' ' << 1 << '\n';
    return 0;
  }

  vector<pair<ll, ll>> finalPoints;
  for(auto & [x, v] : mp) {
    sort(begin(v), end(v));

    if(x != maxX) {
      if(finalPoints.empty() || finalPoints.back().first != x) 
        finalPoints.push_back({x, 2});
    } else {
      reverse(begin(v), end(v));
      if(finalPoints.empty() || finalPoints.back().first != x - 1)
        finalPoints.push_back({x - 1, 2});
    }
    
    for(auto y : v) {
      if(y < 3) continue;
      finalPoints.push_back({x, y});
    }

    if(x + 1 < maxX) {
      finalPoints.push_back({x + 1, 2});
    } else if(x == maxX) {
      reverse(begin(v), end(v));
      if(v[0] == 2 || (v.size() >= 2 && v[1] == 2)) 
        finalPoints.push_back({x, 2});
      finalPoints.push_back({x, 1});
    }
  }

  for(auto it = --mp.end(); it != mp.begin(); it--) {
    if(it -> first == maxX || it -> second[0] > 1) continue;
    finalPoints.push_back({it -> first, 1});
  }

  if(mp.begin() -> second[0] == 1) finalPoints.push_back({mp.begin() -> first, 1});

  cout << finalPoints.size() << '\n';
  for(auto & [x, y] : finalPoints) {
    cout << x << ' ' << y << '\n';
  }
  
  return 0;
}
