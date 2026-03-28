/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll modPow(ll a, ll b, ll m){
  ll ret = 1;

  while(b > 0){
    if(b & 1) ret = ret * a % m;
    a = a * a % m;
    b >>= 1;
  }

  return ret;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m, p; cin >> n >> m >> p;

  vector<vector<int>> adj(n);
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> color(n, -1);

  auto propagate = [&] (auto & self, int u, int paint) -> bool {
    color[u] = paint;
    for(auto & v : adj[u]){
      if(color[v] == u) return false;
      if(color[v] != -1) continue;
      if(!self(self, v, paint ^ 1)) return false;
    }
    return true;
  };

  int k = 0;

  for(int i = 0; i < n; i++){
    if(color[i] == -1){
      k++;
      if(!propagate(propagate, i, 0)){
        cout << "impossible" << '\n';
        return 0;
      }
    }
  }

  ll ans = (modPow(2, k - 1, p) + 1) % p;

  cout << ans << '\n';

  return 0;
}