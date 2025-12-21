/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isConnected(vector<int> adj[], int n){
  vector<bool> visited(n);

  queue<int> q; q.push(0); visited[0] = 1;

  int cnt = 0;
  while(!q.empty()){
    cnt++;
    int u = q.front(); q.pop();

    for(auto v : adj[u]){
      if(visited[v]) continue;
      visited[v] = 1;
      q.push(v);
    }
  }

  return cnt == n;
}

int farthestNode(vector<int> adj[], int n, int u){
  vector<bool> visited(n);

  queue<int> q; q.push(u); visited[u] = 1;

  int lastVisited = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
    lastVisited = u;

    for(auto v : adj[u]){
      if(visited[v]) continue;
      visited[v] = 1;
      q.push(v);
    }
  }

  return lastVisited;
}

int maxDistance(vector<int> adj[], int n){
  int nodeOne = farthestNode(adj, n, 0);
  int nodeTwo = farthestNode(adj, n, nodeOne);

  vector<bool> visited(n);
  queue<pair<int, int>> q; q.push({nodeOne, 0}); visited[nodeOne] = 1;

  while(!q.empty()){
    auto [u, d] = q.front(); q.pop();

    if(u == nodeTwo) return d;

    for(auto v : adj[u]){
      if(visited[v]) continue;
      visited[v] = 1;
      q.push({v, d + 1});
    }
  }

  return 2;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<int> adj[n];

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if(!isConnected(adj, n)){
    cout << -1 << '\n';
    return 0;
  }

  cout << (int)log2(maxDistance(adj, n)) + 1 << '\n';
  
  return 0;
}