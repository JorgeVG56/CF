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

  

  return 0;
}