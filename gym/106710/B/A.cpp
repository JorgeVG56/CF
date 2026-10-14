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
  
  vector<vector<ll>> grid(n, vector<ll>(n));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  vector<vector<ll>> sums(n, vector<ll>(n));
  int m; cin >> m;
  for(int _m = 0; _m < m; _m++) {
    int i, j, x, y, k; cin >> i >> j >> x >> y >> k; --i, --j, --x, --y;
    int mnX = min(i, x), mxX = max(i, x);
    int mnY = min(j, y), mxY = max(j, y);
    sums[mnX][mnY] += k;
    if(mxY + 1 < n) sums[mnX][mxY + 1] -= k;
    if(mxX + 1 < n) sums[mxX + 1][mnY] -= k;
    if(mxX + 1 < n && mxY + 1 < n) sums[mxX + 1][mxY + 1] += k;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(grid[i][j] > 0) grid[i][j] += sums[i][j];
      if(j + 1 < n) sums[i][j + 1] += sums[i][j];
      if(i + 1 < n) sums[i + 1][j] += sums[i][j];
      if(i + 1 < n && j + 1 < n) sums[i + 1][j + 1] -= sums[i][j];
    }
  }

  vector<vector<pair<ll, ll>>> adj(n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(grid[i][j] <= 0) continue;
      adj[i].push_back({j, grid[i][j]});
    }
  }

  vector<vector<ll>> ans(n, vector<ll>(n, INF));

  for(int i = 0; i < n; i++) {
    auto & dist = ans[i]; dist[i] = 0;
    priority_queue<pair<ll, ll>> pq; pq.push({0, i});
    while(!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();
      d *= -1;
      if(dist[u] < d) continue;
      for(auto [v, w] : adj[u]) {
        if(dist[v] <= d + w) continue;
        dist[v] = d + w;
        pq.push({-dist[v], v});        
      }
    }
  }

  int q; cin >> q;
  for(int i = 0; i < q; i++) {
    int a, b; cin >> a >> b; --a, --b;
    cout << (ans[a][b] == INF ? -1 : ans[a][b]) << '\n';
  }
  
  return 0;
}
