#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

struct Edge{
  int u, v, cap, cost; 
};

vector<vector<int>> adj, cost, cap;

void shortestPaths(int n, int u, vector<int> & dp, vector<int> & par){
  dp.assign(n, INF); dp[u] = 0;
  par.assign(n, -1);
  vector<bool> vis(n); vis[u] = true;
  queue<int> q; q.push(u);

  while(!q.empty()){
    int u = q.front(); q.pop();
    vis[u] = false;
    for(int & v : adj[u]){
      if(cap[u][v] <= 0 || dp[v] <= dp[u] + cost[u][v]) continue;
      dp[v] = dp[u] + cost[u][v];
      par[v] = u;
      if(vis[v]) continue;
      vis[v] = true;
      q.push(v);
    }
  }
}

int minCostFlow(int n, vector<Edge> & edges, int k, int s, int t){
  adj.assign(n, vector<int>());
  cost.assign(n, vector<int>(n));
  cap.assign(n, vector<int>(n));
  for(auto & e : edges){
    adj[e.u].push_back(e.v);
    adj[e.v].push_back(e.u);
    cost[e.u][e.v] = e.cost;
    cost[e.v][e.u] = -e.cost;
    cap[e.u][e.v] = e.cap;
  }

  int flow = 0, minCost = 0;
  vector<int> dp, par;
  while(flow < k){
    shortestPaths(n, s, dp, par);
    if(dp[t] == INF) break;

    int f = k - flow, cur = t;
    while(cur != s) f = min(f, cap[par[cur]][cur]), cur = par[cur];

    flow += f, minCost += f * dp[t], cur = t;
    while(cur != s) cap[par[cur]][cur] -= f, cap[cur][par[cur]] += f, cur = par[cur];
  }

  if(flow < k) return -1;
  else return minCost;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string t; cin >> t;
  int n; cin >> n;
  vector<pair<string, int>> a(n); for(auto & [s, x] : a) cin >> s >> x;

  vector<Edge> edges;
  for(int i = 0; i < n; i++){
    edges.push_back({0, i + 1, a[i].second, i + 1});
    vector<int> freq(26);
    for(char c : a[i].first) freq[c - 'a']++;
    for(int j = 0; j < 26; j++)
      if(freq[j] > 0)
        edges.push_back({i + 1, n + j + 1, freq[j], 0});
  }

  vector<int> freq(26);
  for(char c : t) freq[c - 'a']++;
  for(int j = 0; j < 26; j++)
    if(freq[j] > 0)
      edges.push_back({n + j + 1, n + 27, freq[j], 0});

  cout << minCostFlow(n + 28, edges, size(t), 0, n + 27) << '\n';

  return 0;
}