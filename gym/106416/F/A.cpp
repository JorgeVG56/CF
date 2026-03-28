#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> colores(n); for(int & x : colores) cin >> x;

  int ans = 0;

  for(int mask = 0; mask < (1 << 17); mask++){
    vector<vector<int>> adj(n + 1);

    auto addEdge = [&](int u, int v) -> void {
      adj[u].push_back(v);
      adj[v].push_back(u);
    };

    int left = -1, right = -1;
    int currentBall = 0;
    for(int i = 0; i < 17; i++){
      if(currentBall > n) break;
      int neighbor = -1;
      for(int j = 0; j <= i; j++){
        currentBall++;
        if(currentBall > n) break;
        if(j > 0) addEdge(currentBall, currentBall - 1);
        if(neighbor != -1){
          addEdge(currentBall, neighbor);
          if(size(adj[neighbor]) >= 3){
            neighbor = adj[neighbor][size(adj[neighbor]) - 3];
            addEdge(currentBall, neighbor);
          }
        } else{
          bool isLeft = (mask >> i) & 1;
          neighbor = (isLeft) ? left : right;
          if(isLeft) left = currentBall;
          else right = currentBall;
          if(neighbor != -1) addEdge(currentBall, neighbor);
        }
        if(left == -1) left = 1;
        else if(right == -1) right = 1;
      }
    }

    vector<int> visited(n + 1);

    auto sizeCluster = [&](auto & self, int u) -> int {
      visited[u] = 1;
      int size = 1;
      for(int v : adj[u]) if(!visited[v] && colores[v - 1] == colores[u - 1]) size += self(self, v);
      return size;
    };

    for(int i = 1; i <= n; i++){
      if(visited[i]) continue;

      ans = max(ans, sizeCluster(sizeCluster, i));
    }
  }

  cout << ans << '\n';

  return 0;
}