#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const int INF = 1e9;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n, m; cin >> n >> m;
  
  string s; cin >> s;
  string t; cin >> t;
  
  vector<vector<array<int, 2>>> dp(n + 1, vector<array<int, 2>>(m + 1, {INF, INF}));
  dp[0][0][0] = 0;
  int ans = s.length();

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      if(dp[i][j][0] != INF) {
        for(int k = i; k < n; k++) dp[k][j][1] = min(dp[k][j][1], dp[i][j][0] + 1);

        string pattern = s.substr(i);
        string where = t.substr(j);

        if(pattern.empty()) continue; 

        bool fl = true;
        for(int k = 1; k <= min(pattern.size(), where.size()); k++) {
          if(pattern[k - 1] != where[k - 1]) {
            fl = false;
            ans = min(ans, dp[i][j][0] + k + (k != where.size()));
            break;
          } else {
            dp[i + k][j + k][0] = min(dp[i + k][j + k][0], dp[i][j][0] + k);
          }
        }

        if(fl == true && where.size() > pattern.size()) {
          ans = min(ans, dp[i][j][0] + (int)pattern.size());
        }
      }
      
      if(dp[i][j][1] != INF) {
        string pattern = s.substr(i);
        string where = t.substr(j);
        string total = pattern + '#' + where;
        int _total = total.length(); vector<int> pi(_total);
        for (int a = 1; a < _total; a++) {
          int b = pi[a - 1];
          while (b > 0 && total[a] != total[b]) b = pi[b - 1];
          if (total[a] == total[b])
          b++;
          pi[a] = b;
        }
        vector<int> pos(pattern.size() + 1, -1);
        for(int l = pattern.length() + 1; l < _total; l++) {
          if(pi[l] <= 0 || pos[pi[l]] != -1) continue;
          int k = l - pattern.length();
          pos[pi[l]] = k;
          dp[i + pi[l]][j + k][0] = min(dp[i + pi[l]][j + k][0], dp[i][j][1] + pi[l]);
        }
        bool fl = true;
        for(int k = 1; k < pos.size(); k++) {
          if(pos[k] != -1) continue;
          fl = false;
          ans = min(ans, dp[i][j][1] + k + 1);
          break;
        }
        if(fl) {
          ans = min(ans, dp[i][j][1] + (int)pos.size() - 1);
        }
      }
    }
  }

  cout << ans << '\n';
  
  return 0;
}
