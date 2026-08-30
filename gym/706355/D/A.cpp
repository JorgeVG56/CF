#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  vector<vector<int>> adj(n);

  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> color(n + 1, 0); color[0] = 1;

  auto dfs = [&](auto & self, int u = 0, int p = 0) -> void {
    int c = 1;
    for(int v : adj[u]){
      if(v == p) continue;
      while(c == color[u] || c == color[p]) c++;
      color[v] = c++;
      self(self, v, u);
    }
  }; dfs(dfs);

  cout << *max_element(begin(color), end(color)) << '\n';
  for(int i = 0; i < n; i++) cout << color[i] << ' ';

  return 0;
}