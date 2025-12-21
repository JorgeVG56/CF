/*
  Pura gente del Coach Moy

  
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define INF 1e18
#define ENDL '\n'

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const ll MOD = 1000000007;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}
inline int sub(int x, int y) {
  return x >= y ? x - y : x - y + MOD;
}
inline int mul(int x, int y) {
  return int((ll)x * y % MOD);
}

int calc(int l, int r, int k, string & s, vector<vvi> & dp){
  if(k == 0) return (l - 1 <= r ? 0 : 999);
  if(k == 1) return (l <= r ? 0 : 999);
  if(l > r) return 999;

  if(dp[l][r][k] != -1) return dp[l][r][k];

  if(s[l] == s[r]) return dp[l][r][k] = calc(l + 1, r - 1, k - 2, s, dp);

  return dp[l][r][k] = min({1 + calc(l + 1, r - 1, k - 2, s, dp), calc(l + 1, r, k, s, dp), calc(l, r - 1, k, s, dp)});
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  vector<vvi> dp(n, vvi(n, vi(n + 1, -1)));

  string s; cin >> s;

  cout << calc(0, n - 1, k, s, dp);

  return 0;
}