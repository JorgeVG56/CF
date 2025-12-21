/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, c, q; cin >> n >> c >> q;

  vector<vector<int>> adj(n);

  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int t = 0;
  vector<int> par(n, -1), sz(n, 1), head(n), pos(n), dis(n), depth(n);
  
  auto dfsSZ = [&](auto & self, int u) -> void{
    if(par[u] != -1) adj[u].erase(find(begin(adj[u]), end(adj[u]), par[u]));

    for(auto & v : adj[u]){
      par[v] = u;
      depth[v] = depth[u] + 1;
      self(self, v);
      sz[u] += sz[v];
      if(sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
    }
  };

  auto dfsHLD = [&](auto & self, int u) -> void{
    pos[u] = t++;
    for(auto & v : adj[u]){
      head[v] = (v == adj[u][0] ? head[u] : v);
      dis[v] = (head[v] == v ? 1 : dis[u] + 1);
      self(self, v);
    }
  };

  dfsSZ(dfsSZ, 0);
  dfsHLD(dfsHLD, 0);

  vector<int> ans(n), cnt(c); ans[0] = c;
  vector<stack<pair<int, int>>> changes(n);

  auto updPath = [&](int u, int c) -> void{
    while(u > 0){
      //int d = dis[u];
      int d = dis[u];

      while(d && !changes[head[u]].empty()){
        auto [color, cant] = changes[head[u]].top(); changes[head[u]].pop();

        int removing = min(cant, d);

        d -= removing;
        cant -= removing;
        ans[cnt[color]]--;
        cnt[color] -= removing;
        ans[cnt[color]]++;

        if(cant){
          changes[head[u]].push({color, cant});
        }
      }

      changes[head[u]].push({c, dis[u]});
      ans[cnt[c]]--;
      cnt[c] += dis[u];
      ans[cnt[c]]++;

      u = par[head[u]];
    }
  };

  for(int i = 0; i < q; i++){
    int u, c, m; cin >> u >> c >> m; u--; c--;

    updPath(u, c);

    cout << ans[m] << '\n';
  }

  return 0;
}