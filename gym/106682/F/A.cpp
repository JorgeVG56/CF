#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n, m; cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);
  vector<int> weights(m, 1);

  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  auto calcDist = [&]() -> int {
    vector<int> vis(n, INF); vis[0] = 0;
    deque<int> dq; dq.push_back(0);
    while(!dq.empty()) {
      auto u = dq.front(); dq.pop_front();
      for(auto [v, idx] : adj[u]) {
        int w = weights[idx];
        if(vis[u] + w < vis[v]) {
          vis[v] = vis[u] + w;
          if(w == 0) dq.push_front(v);
          else dq.push_back(v);
        }
      }
    }
    return vis[n - 1];
  };

  vector<double> dist(m);
  for(int k = 0; k < m; k++) {
    dist[k] = calcDist();
    double ans = INF;
    for(int i = 0; i <= k; i++) 
      ans = min(ans, dist[i] / (k - i + 1));
    
    cout << fixed << setprecision(6) << ans << '\n';
    weights[k] = 0;
  }

  return 0;
}
