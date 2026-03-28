/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> adj[n];
  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  ll parityNodes[2] = {0, 0};
  function<void(int, int, int)> dfs = [&] (int u, int p, int parity) -> void {
    parityNodes[parity]++;
    for(int v : adj[u]) if(p != v) dfs(v, u, parity ^ 1);
  };

  dfs(0, -1, 0);

  cout << (parityNodes[0] * parityNodes[1]) - n + 1;

  return 0;
}