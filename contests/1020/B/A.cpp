/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> succ(n); for(int & x : succ) cin >> x;

  vector<int> answer(n, -2);
  bool inCycle = false;

  auto dfs = [&](auto & self, int u) -> void {
    if(answer[u] != -2) {
      if(answer[u] == -1) {
        inCycle = true;
        answer[u] = u;
      }
    } else{
      answer[u] = -1;
      self(self, succ[u] - 1);

      if(answer[u] != -1) inCycle = false;
      else answer[u] = (inCycle ? u : answer[succ[u] - 1]);
    }
  };

  for(int i = 0; i < n; i++) dfs(dfs, i);

  for(int x : answer) cout << x + 1 << ' ';
  cout << '\n';

  return 0;
}