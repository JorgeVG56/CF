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

  int n, m, k; cin >> n >> m >> k;
  
  vector<vector<array<ll, 3>>> adj(n);
  for(int i = 0; i < m; i++) {
    ll u, v, w, f; cin >> u >> v >> w >> f; --u, --v;
    adj[u].push_back({v, w, 0}); adj[v].push_back({u, w, 0});
    if(f == -1) continue;
    adj[u].push_back({v, f, 1}); adj[v].push_back({u, f, 1});
  }

  vector<vector<ll>> dist(n, vector<ll>(k + 1, INF)); dist[0][0] = 0;
  priority_queue<array<ll, 3>> pq; pq.push({0, 0, 0});

  while(!pq.empty()) {
    auto [d, _k, u] = pq.top(); pq.pop(); d *= -1ll;
    if(d > dist[u][_k]) continue;
    for(auto [v, w, __k] : adj[u]) {
      int newD = d + w, newK = _k + __k;
      if(newK > k) continue;
      if(newD >= dist[v][newK]) continue;
      dist[v][newK] = newD;
      pq.push({-newD, newK, v});
    }
  }

  cout << *min_element(begin(dist[n - 1]), end(dist[n - 1])) << '\n';
  
  return 0;
} 