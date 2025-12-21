/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, b; cin >> n >> b;
  
  vector<pair<int, int>> a(n);
  vector<int> adj[n];

  for(int i = 0; i < n; i++){
    int c, d; cin >> c >> d;
    if(i){
      int x; cin >> x; x--;
      adj[x].push_back(i);
    }
  }

  vector<int> sz(n);
  vector<pair<int, int>> dp(n, {-1, -1});

  auto dfs = [&](auto & self, int u = 0) -> int{
    
  };

  return 0;
}