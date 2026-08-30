#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 4e18;
const ll MOD = (1ll << 32);
const int MAXN = 1e6 + 5;

void getCentroidTree(vector<vector<int>> & adj, vector<int> & parent, vector<vector<pair<int, int>>> & par) {
  int n = size(adj);

  vector<int> size(n), taken(n);
  auto dfsZ = [&](auto & self, int u, int p = -1) -> int {
    size[u] = 1;
    for(int v : adj[u]) {
      if(v == p || taken[v]) continue;
      size[u] += self(self, v, u);
    }
    return size[u];
  };

  auto dfsC = [&](auto & self, int u, int sz, int p = -1) -> int {
    for(int v : adj[u]) {
      if(v == p || taken[v] || size[v] * 2 <= sz) continue;
      return self(self, v, sz, u);
    }
    return u;
  };

  auto dfsA = [&](auto & self, int u, int fl, int par, int p = -1) -> void {
    par[u].push_back({par, fl});
    for(int v : adj[u]) {
      if(v == p || taken[v]) continue;
      self(self, v, fl, par, u);
    }
  };

  auto buildCentroidTree = [&](auto & self, int u = 0) -> int {
    int centroid = dfsC(dfsC, u, dfsZ(dfsZ, u));
    taken[centroid] = true;

    for(int v : adj[centroid]) {
      if(taken[v]) continue;
      dfsA(dfsA, v, v == parent[centroid], centroid);
    }

    for(int v : adj[centroid]) {
      if(taken[v]) continue;
      self(self, v);
    }
  }; buildCentroidTree(buildCentroidTree);
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  

  return 0;
} 