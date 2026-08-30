#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  for(auto & v : a) for(int & x : v) cin >> x;

  auto f = [&](int x) -> pair<int, int> {
    vector<int> maskPos(1 << m, -1);

    for(int i = 0; i < n; i++) {
      int mask = 0;
      for(int j = 0; j < m; j++){
        if(a[i][j] >= x) mask |= (1 << j);
      }
      maskPos[mask] = i;
    }

    for(int i = 0; i < (1 << m); i++){
      if(maskPos[i] == -1) continue;

      for(int j = i; j < (1 << m); j++){
        if(maskPos[j] == -1) continue;
        if((i | j) == (1 << m) - 1) return {maskPos[i], maskPos[j]};
      }
    }

    return {-1, -1};
  };

  int l = 0, r = 1e9;
  while(l < r){
    int m = (l + r + 1) >> 1;

    if(f(m).first != -1) l = m;
    else r = m - 1;
  }

  pair<int, int> answer = f(l);
  cout << answer.first + 1 << ' ' << answer.second + 1 << '\n';

  return 0;
}