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

int kuhn(vector<vector<int>> & adj, int n, int k) {
  vector<int> mt(k, -1), used(n);

  auto tryKuhn = [&](auto & self, int u) -> bool {
    if(used[u]) return false;
    used[u] = true;
    for(int v : adj[u]) {
      if(mt[v] == -1 || self(self, mt[v])) {
        mt[v] = u;
        return true;
      }
    }
    return false;
  };

  int matching = 0;
  for(int u = 0; u < n; u++) {
    fill(begin(used), end(used), 0);
    matching += tryKuhn(tryKuhn, u);
  }
  return matching;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, m1, m2; cin >> n >> m1 >> m2;

  vector<vector<int>> adj1(n, vector<int>(n));
  for(int i = 0; i < m1; i++) {
    int u, v; cin >> u >> v; --u, --v;
    if(u > v) swap(u, v);
    adj1[u][v] = 1;
  }

  vector<vector<int>> adj2(n, vector<int>(n));
  for(int i = 0; i < m2; i++) {
    int u, v; cin >> u >> v; --u, --v;
    if(u > v) swap(u, v);
    adj2[u][v] = 1;
  }

  if(m1 != m2) {
    cout << -1 << '\n';
    return 0;
  }

  vector<pair<int, int>> alive, dead;
  for(int u = 0; u < n; u++) {
    for(int v = u + 1; v < n; v++) {
      if(adj1[u][v] == adj2[u][v]) continue;
      if(adj1[u][v]) alive.push_back({u, v});
      else dead.push_back({u, v});
    }
  }

  int A = alive.size(), D = dead.size();
  vector<vector<int>> adj(A + D);
  for(int i = 0; i < A; i++) {
    for(int j = 0; j < D; j++) {
      if(alive[i].first != dead[j].first && alive[i].first != dead[j].second && 
        alive[i].second != dead[j].first && alive[i].second != dead[j].second) continue;
        adj[i].push_back(j); 
    }
  }

  int ans = 2 * D - kuhn(adj, A, D);
  cout << ans << '\n';

  return 0;
} 