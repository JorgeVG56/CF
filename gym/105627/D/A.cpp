/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> dijkstra(vector<vector<pair<int, int>>> & adj, vector<int> & st, int k, int node){
  int n = (int) adj.size(); 
  vector<int> d(n);
  for(int i = 0; i < n; i++) d[i] = (int)1e9;
  d[node] = 0;

  priority_queue<pair<pair<int, int>, int>> pq; pq.push({{0, node}, k});

  while(!pq.empty()){
    auto [p, curK] = pq.top(); pq.pop();
    auto [du, u] = p;
    du *= -1;
    if(st[u]) curK = k;
    if(du > d[u]) continue;

    for(auto & [v, w] : adj[u]){
      if(du + w < d[v] && curK - w >= 0){
        d[v] = du + w;
        pq.push({{-d[v], v}, curK - w});
      }
    }
  }

  return d;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, k; cin >> n >> k;

  vector<vector<pair<int, int>>> adj(n);

  for(int i = 1; i < n; i++){
    int u, v, c; cin >> u >> v >> c; --u, --v;

    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  vector<int> st(n); for(auto & x : st) cin >> x;

  vector<int> dj = dijkstra(adj, st, k, 0);

  for(int i = 1; i < n; i++){
    cout << (dj[i] == (int)1e9 ? -1 : dj[i]) << ' ';
  }

  return 0;
}