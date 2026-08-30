#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<vector<pair<int, char>>> adj(n);

  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v; --u, --v;
    char c; cin >> c;

    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  vector<int> dis(n, INF); dis[n - 1] = 0;
  queue<int> q; q.push(n - 1);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    
    for(auto & [v, c] : adj[u]) {
      if(dis[v] <= dis[u] + 1) continue;
      dis[v] = dis[u] + 1;
      q.push(v);
    }
  }
  
  string s = "";
  vector<int> possibles; possibles.push_back(0);
  for(int i = 0; i < dis[0]; i++) {
    char minC = 'z';
    for(int j = 0; j < possibles.size(); j++) {
      int u = possibles[j];
      for(auto [v, c] : adj[u]) if(dis[v] == dis[u] - 1) minC = min(minC, c);
    }

    s += minC;
    set<int> possiblesNext;
    for(int j = 0; j < possibles.size(); j++) {
      int u = possibles[j];
      for(auto [v, c] : adj[u]) if(dis[v] == dis[u] - 1 && c == minC) possiblesNext.insert(v);
    }

    possibles.clear(); for(int u : possiblesNext) possibles.push_back(u);
  }

  vector<int> parent(n);
  q.push(n - 1);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(auto & [v, c] : adj[u]) {
      if(c == s[dis[0] - dis[v]] && dis[v] == dis[u] + 1 && parent[v] == 0) {
        parent[v] = u;
        q.push(v);
      }
    }
  }

  cout << dis[0] << '\n';
  int u = 0;
  while(u != n - 1) {
    cout << u + 1 << ' ';
    u = parent[u];
  }
  cout << u + 1 << '\n';
  cout << s << '\n';

  return 0;
}