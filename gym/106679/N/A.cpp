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

  int n; cin >> n;

  vector<vector<int>> adj(n);
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> current; current.push_back(0);
  vector<vector<int>> keys(n);
  int color = 0;
  auto dfs = [&](auto & self, int u, int p = -1) -> void {
    for(int v : adj[u]) {
      if(v == p) continue;
      keys[v] = keys[u];
      for(int w : current) 
        if(color) keys[w].push_back(color);
      keys[u].push_back(++color); keys[v].push_back(color++);
      current.push_back(v);
      self(self, v, u);
    }
  }; dfs(dfs, 0);

  cout << color - 1 << '\n';
  for(auto & arr : keys) {
    cout << arr.size();
    for(auto & x : arr) cout << ' ' << x;
    cout << '\n';
  }
  
  return 0;
} 