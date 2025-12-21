/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string a, b; cin >> a >> b;

  reverse(begin(a), end(a));
  reverse(begin(b), end(b));

  vector<vector<ll>> dp(1000005, vector<ll>(100));

  auto solve = [&](auto & self, int pos, ll curPow, int x, int y) -> ll{
    if(pos >= (int)a.size() || pos >= (int)b.size()) return 0;

    int c = a[pos] - '0' + x, d = b[pos] - '0' + y;

    if(c + d >= 10) return dp[pos][c * 10 + d] = ((c + d - 9) * curPow) + min(self(self, pos + 1, curPow * 10, 1, 0), self(self, pos + 1, curPow * 10, 0, 1));
    else return dp[pos][c * 10 + d] = self(self, pos + 1, curPow * 10, 0, 0);
  };

  cout << solve(solve, 0, 1, 0, 0);

  return 0;
}