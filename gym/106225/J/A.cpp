#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n, m; cin >> n >> m;

    vector<int> a(n); for(int & x : a) cin >> x;
    vector<int> b(m); for(int & x : b) cin >> x;

    vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(2, -1)));

    auto dp = [&] (auto self, int i, int j, int k) -> bool {
      if(i == n) return j == m;
      if(j == m) return k;
      if(memo[i][j][k] != -1) return memo[i][j][k];

      int answer = 0;
      if(a[i] == b[j]) answer |= self(self, i + 1, j + 1, 0);
      if(n - i >= b[j]) answer |= self(self, i + b[j], j + 1, 1);
      if(k) answer |= self(self, i + 1, j, k);

      return memo[i][j][k] = answer;
    };

    cout << (dp(dp, 0, 0, 0) ? "Yes" : "No") << '\n';
  }

  return 0;
}