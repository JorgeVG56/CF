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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  string s; cin >> s;

  vi dp(1 << 26);

  int mask = 0;
  FOR(i, 0, n){
    mask ^= (1 << (s[i] - 'a'));
    dp[mask] = i + 1;
  }

  int ans = dp[0], curMask = 0; 
  FOR(i, 0, n){
    ans = max(ans, dp[curMask] - i);
    FOR(j, 0, 26){
      ans = max(ans, dp[curMask ^ (1 << j)] - i);
    }

    curMask ^= (1 << (s[i] - 'a'));
  }

  cout << ans;

  return 0;
}
