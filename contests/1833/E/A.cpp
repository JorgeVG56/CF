/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct TarjanSolver{
  vector<vector<int>> & adj;
  vector<vector<int>> revAdj;
  vector<int> post, comp;
  vector<bool> visited;
  int timer = 0;
  int id = 0;

  TarjanSolver(vector<vector<int>> & adj) : adj(adj), revAdj(adj.size()), post(adj.size()), comp(adj.size()), visited(adj.size()){
    vector<int> nodes(adj.size());
    for(int u = 0; u < (int)adj.size(); u++){
      nodes[u] = u;
      for(int v : adj[u]) revAdj[v].push_back(u);
    }

    for(int u = 0; u < (int)adj.size(); u++) if(!visited[u]) fillPost(u);

    sort(begin(nodes), end(nodes), [&](int u, int v) -> bool { return post[u] > post[v]; });

    visited.assign(adj.size(), false);
    for(auto u : nodes) if(!visited[u]){ findComp(u); id++; }
  }

  void fillPost(int u){
    visited[u] = true;
    for(auto v : revAdj[u]) if(!visited[v]) fillPost(v);
    post[u] = timer++;
  }

  void findComp(int u){
    visited[u] = true;
    comp[u] = id;
    for(auto v : adj[u]) if(!visited[v]) findComp(v);
  }

  int compNum(){ return id; }
  int getComp(int u){ return comp[u]; }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;

    vector<vector<int>> adj(n);
    vector<pair<int, int>> neighbors(n, {-1, -1});
    for(int u = 0; u < n; u++){
      int v; cin >> v; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
      if(neighbors[u].first == -1) neighbors[u].first = v;
      else if(neighbors[u].first != v) neighbors[u].second = v;
      if(neighbors[v].first == -1) neighbors[v].first = u;
      else if(neighbors[v].first != u) neighbors[v].second = u;
    }

    TarjanSolver tarjan(adj);
    int totalComponents = tarjan.compNum();

    vector<int> sizeComponents(totalComponents);
    vector<int> openDancers(totalComponents);
    for(int u = 0; u < n; u++){
      sizeComponents[tarjan.getComp(u)]++;
      if(neighbors[u].second == -1) openDancers[tarjan.getComp(u)]++;
    }

    int closedComponents = 0, openComponents = 0;
    for(int u = 0; u < totalComponents; u++){
      if(sizeComponents[u] > 2 && !openDancers[u]) closedComponents++;
      else openComponents = 1;
    }

    cout << closedComponents + openComponents << ' ' << totalComponents << '\n';
  }

  return 0;
}