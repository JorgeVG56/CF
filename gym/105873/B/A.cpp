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

  vvll a(n, vll(n)); FOR(i, 0, n) FOR(j, 0, n) cin >> a[i][j];

  int xS[] = {0, 0, n - 1, n - 1, n - 1, n - 1, 0, 0};
  int yS[] = {0, 0, 0, 0, n - 1, n - 1, n - 1, n - 1};
  int dS[] = {2, 1, 1, 0, 0, 3, 3, 2};
  int rS[] = {-1, 1, -1, 1, -1, 1, -1, 1};

  ll ans = 0;
  FOR(s, 0, 8){
    int x = xS[s], y = yS[s], d = dS[s], r = rS[s];

    ll mx = 0, cur = 0;
    vvi vis(n, vi(n, 0));
    FOR(i, 0, n * n){
      cur = max(0ll, cur + a[x][y]);
      mx = max(mx, cur);
      vis[x][y] = 1;

      x += dx[d], y += dy[d];
      if(x < 0 || x >= n || y < 0 || y >= n || vis[x][y]){
        x -= dx[d], y -= dy[d];
        d = (d + r + 4) % 4;
        x += dx[d], y += dy[d];
      }
    }

    ans = max(ans, mx);
  }

  cout << ans;

  return 0;
}
