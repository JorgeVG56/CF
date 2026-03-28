/*
  Pura gente del Coach Moy  

  1->2->4
      ->5
  1->3->5
      ->4
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> query(int k){
  cout << '?' << ' ' << k << '\n'; cout.flush();
  int n; cin >> n;
  vector<int> path(n); for(int & x : path){ cin >> x; --x; }
  return path;
}

void answer(int m, vector<vector<int>> & adj){
  cout << '!' << ' ' << m << '\n';
  for(int i = 0; i < adj.size(); i++){
    for(auto & x : adj[i]) cout << i + 1 << ' ' << x + 1 << '\n';
  }
  cout.flush();
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;

    int m = 0;
    vector<vector<int>> adj(n);
    vector<int> szPath(n, -1);
    
    function<void(int)> calc = [&](int u) -> void {
      if(szPath[u] != -1) return;

      szPath[u] = 1;
      for(int v : adj[u]){
        calc(v);
        szPath[u] += szPath[v];
      }
    };

    vector<int> lastPath = {0};
    int k = 2;
    while(true){
      vector<int> path = query(k);
      if(path.empty()) break;

      int commonPreffix = 0;
      for(int i = 0; i < min(size(lastPath), size(path)); i++) 
        if(path[i] != lastPath[i]) break; 
        else commonPreffix++;

      if(lastPath.size() > commonPreffix)
        calc(lastPath[commonPreffix]);

      if(commonPreffix > 0)
        adj[path[commonPreffix - 1]].push_back(path[commonPreffix]), m++;

      if(szPath[path[commonPreffix]] == -1) k++;
      else k += szPath[path[commonPreffix]];

      lastPath = path;
    }

    answer(m, adj);
  }

  return 0;
}