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
  vector<int> a(n); for(int & x : a) cin >> x;
  
  int total = accumulate(begin(a), end(a), 0);
  
  if(total != n * (n - 1) / 2) {
    cout << "NO" << '\n';
    return 0;
  }
  

  vector<pair<int, int>> b(n);
  for(int i = 0; i < n; i++) {
    b[i] = {a[i], i};
  }
  
  vector<vector<int>> ans(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++) {
    sort(begin(b), end(b));
    auto act = b.back(); b.pop_back();
    if(act.first < 0 || act.first > b.size()) {
      cout << "NO" << '\n';
      return 0;
    }

    for(int j = 0; j < act.first; j++) {
      ans[act.second][b[j].second] = 1;
      ans[b[j].second][act.second] = 0;
    }

    for(int j = act.first; j < b.size(); j++) {
      ans[act.second][b[j].second] = 0;
      ans[b[j].second][act.second] = 1;
      b[j].first--;
    }
  }

  cout << "YES" << '\n';
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
  
  return 0;
}
