/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;

vector<vector<pair<ll, ll>>> adj;

vector<vector<pair<ll, ll>>> graph;

ll prim(){
  vector<bool> taken(n);

  priority_queue<pair<ll, vector<ll>>> pq;

  auto process = [&](ll u, ll d) -> void {
    taken[u] = 1;

    for (auto & [v, w] : adj[u]) if(!taken[v]) pq.push({-w * d, {v, d, u}});
  };

  process(0, 1);

  ll totalWeight = 0, takenEdges = 0;

  while (!pq.empty() && takenEdges < n - 1) {
    auto [w, node] = pq.top(); pq.pop();

    graph[node[2]].push_back({node[0], w});

    if (taken[node[0]]) continue;

    totalWeight -= w;

    process(node[0], node[1] + 1);

    ++takenEdges;
  }

  return totalWeight;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;

  adj.resize(n);

  for(ll i = 0; i < m; i++){
    ll u, v, c; cin >> u >> v >> c; --u, --v;
    adj[u].push_back({v, c});
    adj[u].push_back({u, c});
  }

  cout << prim();

  return 0;
}