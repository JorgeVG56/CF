#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define int ll
const ll INF = 4e18;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<string> a(n); for(string & s : a) cin >> s;
  vector<string> b = a;

  int dI [] = {0, m - 1, n - 1, 0}, dJ [] = {0, 0, m - 1, m - 1};
  int sIL [] = {1, 0, -1, 0}, sJL [] = {0, -1, 0, 1};
  int sIR [] = {0, 1, 0, -1}, sJR [] = {1, 0, -1, 0};
  int ans = 0;
  for(int flipped = 0; flipped < 2; flipped++) {
    for(int dir = 0; dir < 4; dir++) {
      if(dir & 1 && n != m) continue;
      bool fl = true;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          int nI = dI[dir] + i * sIL[dir] + j * sJL[dir];
          int nJ = dJ[dir] + i * sIR[dir] + j * sJR[dir];
          if(!fl || a[i][j] != b[nI][nJ]) {
            fl = false;
            break;
          }
        }
      }
      ans += fl;
    }

    for(int i = 0; i < n; i++) {
      reverse(begin(b[i]), end(b[i]));
    }
  }

  cout << ans << '\n';
  
  return 0;
} 