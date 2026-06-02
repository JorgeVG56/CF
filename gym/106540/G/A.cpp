#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<vector<int>> adj(n);
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> group(n, -1); 
  int totalGroups = 0;
  auto dfs = [&](auto & self, int u, int curGroup) -> void {
    group[u] = curGroup;
    for(int v : adj[u]) if(group[v] == -1) self(self, v, curGroup);
  };

  for(int u = 0; u < n; u++) if(group[u] == -1) dfs(dfs, u, totalGroups++);

  vector<vector<int>> groupMembers(totalGroups);
  for(int u = 0; u < n; u++) groupMembers[group[u]].push_back(u);

  auto cmp = [&](int a, int b) -> bool {
    return size(groupMembers[a]) < size(groupMembers[b]);
  };

  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  for(int i = 0; i < totalGroups; i++) pq.push(i);

  vector<pair<int, int>> teams;
  while(size(pq) > 1){
    int gA = pq.top(); pq.pop();
    int gB = pq.top(); pq.pop();

    teams.push_back({groupMembers[gA].back(), groupMembers[gB].back()}); 
    groupMembers[gA].pop_back(); groupMembers[gB].pop_back();
    if(!groupMembers[gA].empty()) pq.push(gA);
    if(!groupMembers[gB].empty()) pq.push(gB);
  }

  cout << size(teams) << '\n';
  for(auto [teamL, teamR] : teams) cout << teamL << ' ' << teamR << '\n';

  return 0;
}