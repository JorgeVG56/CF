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

  vector<ll> a(n); for(ll & x : a) cin >> x;
  
  vector<vector<pair<int, char>>> adj(n);
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v; --u, --v;
    char c; cin >> c;
    if(c == '=') {
      adj[u].push_back({v, '='});
      adj[v].push_back({u, '='});
    } else if(c == '>') {
      adj[u].push_back({v, '>'});
    } else {
      adj[v].push_back({u, '>'});
    }
  }
  
  vector<int> comp(n, -1);
  auto dfsC = [&](auto & self, int u, int compId, int p = -1) -> void {
    comp[u] = compId;
    for(auto [v, c] : adj[u]) {
      if(c != '=' || v == p) continue;
      self(self, v, compId, u);
    }
  };
  int compNum = 0;
  for(int u = 0; u < n; u++) {
    if(comp[u] != -1) continue;
    dfsC(dfsC, u, compNum++);
  }

  vector<vector<int>> adjC(compNum);
  vector<int> degree(compNum);
  for(int u = 0; u < n; u++) {
    for(auto [v, c] : adj[u]) {
      if(c == '=') continue;
      adjC[comp[v]].push_back(comp[u]);
      degree[comp[u]]++;
    }
  }

  queue<int> q;
  for(int i = 0; i < compNum; i++) 
    if(degree[i] == 0) q.push(i);

  vector<int> b(compNum, 1);
  while(!q.empty()) {
    auto u = q.front(); q.pop();
    for(int v : adjC[u]) {
      b[v] = max(b[v], b[u] + 1);
      degree[v]--;
      if(degree[v] == 0) q.push(v);
    }
  }

  ll sum = 0;
  for(int i = 0; i < n; i++) sum += a[i] * b[comp[i]];

  cout << sum << '\n';
  for(int i = 0; i < n; i++) cout << b[comp[i]] << ' ';
  cout << '\n';
  
  return 0;
}
