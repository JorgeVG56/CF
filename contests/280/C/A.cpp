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

  vector<int> depth(n); depth[0] = 1;
  auto dfs = [&](auto & self, int u, int p = -1) -> void {
    for(int v : adj[u]) if(v != p) { depth[v] = depth[u] + 1; self(self, v, u); }
  };

  double ans = 0; dfs(dfs, 0);
  for(int i = 0; i < n; i++){
    ans += 1.0 / depth[i];
  }

  cout << fixed << setprecision(6) << ans << '\n';

  return 0;
}