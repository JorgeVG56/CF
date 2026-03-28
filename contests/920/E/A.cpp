/*
Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m; cin >> n >> m;
  
  vector<set<int>> adj(n);
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v; --u, --v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  
  set<int> unvisited; for(int i = 0; i < n; i++) unvisited.insert(i);
  
  vector<int> componentSizes(n);
  
  auto dfs = [&](auto & self, int u, int component) -> void {
    componentSizes[component]++;
    auto it = unvisited.begin();
    while(it != unvisited.end()){
      if(adj[u].count(*it)){ it++; continue; }
      int last = *it;
      unvisited.erase(it);
      self(self, last, component);
      it = unvisited.upper_bound(last);
    } 
  };
  
  int totalComp = 0;
  for(int i = 0; i < n; i++){
    auto it = unvisited.find(i);
    if(it != unvisited.end()){
      unvisited.erase(it);
      dfs(dfs, i, totalComp++);
    }
  }
  
  cout << totalComp << '\n';
  
  sort(begin(componentSizes), begin(componentSizes) + totalComp);
  for(int i = 0; i < totalComp; i++) cout << componentSizes[i] << ' ';
  cout << '\n';
  
  return 0;
}