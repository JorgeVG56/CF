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
  
  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n, m; cin >> n >> m;

    vector<int> a(m); for(int & x : a) cin >> x;

    vector<pair<int, int>> ans;
    vector<int> lastDay(n, 0);
    set<int> freeDays;
    bool fl = true;
    for(int i = 0; i < m; i++) {
      if(a[i] == 0) {
        freeDays.insert(i);
        continue;
      }

      auto it = freeDays.lower_bound(lastDay[a[i] - 1]);
      if(it == freeDays.end()) {
        fl = false;
        break;
      }
      ans.push_back({*it, a[i]});
      freeDays.erase(it);
      lastDay[a[i] - 1] = i;
    }

    if(!fl) {
      cout << "NO" << '\n';
      continue;
    }

    for(auto & x : freeDays) ans.push_back({x, 0});
    sort(begin(ans), end(ans));
    cout << "YES" << '\n';
    for(auto & [d, l] : ans) cout << l << ' ';
    cout << '\n';
  }

  
  return 0;
}
