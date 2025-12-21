/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, w; cin >> n >> w;

  vector<int> a(n + 1), b(n + 1);

  vector<vector<int>> adj(n + 1);

  for(int i = 1; i <= n; i++){
    int d, c, u; cin >> d >> c >> u;

    adj[d].push_back(i);

    a[i] = c;
    b[i] = u;
  }

  vector<int> dp(n + 1); dp[0] = w;

  auto dfs = [&](auto & self, int u, int p) -> void{
    if(p != -1) dp[u] = max(a[u] - b[u], dp[p] - b[u]);

    for(auto & v : adj[u]) self(self, v, u);
  };

  dfs(dfs, 0, -1);

  cout << *min_element(begin(dp), end(dp));

  return 0;
}