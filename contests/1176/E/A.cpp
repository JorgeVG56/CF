/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n, m; cin >> n >> m;

    vector<int> adj[n];
    for(int i = 0; i < m; i++){
      int u, v; cin >> u >> v; --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int k = 0, _k = 0;
    vector<int> color(n, -1);
    for(int u = 0; u < n; u++){
      if(color[u] != -1) continue;
      color[u] = 1; k++;
      for(int v : adj[u]) if(color[v] == -1) color[v] = 0, _k++;
    }

    cout << min(_k, k) << '\n';
    for(int u = 0; u < n; u++) if(color[u] == (k < _k)) cout << u + 1 << ' ';
    cout << '\n';
  }

  return 0;
}