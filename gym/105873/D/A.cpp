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

  int k; cin >> k;
  vll a(k); FOR(i, 0, k) cin >> a[i];

  int n; cin >> n;
  vvll b(n, vll(k)); FOR(i, 0, n) FOR(j, 0, k) cin >> b[i][j];

  vll t(k, 0); FOR(i, 0, n) FOR(j, 0, k) t[j] += b[i][j];

  ll day = 1e18;
  FOR(i, 0, k) day = min(day, a[i] / (t[i] ? t[i] : 1));

  FOR(i, 0, k) a[i] -= t[i] * day;

  ll order = -1;
  FOR(i, 0, n){
    FOR(j, 0, k){
      if(b[i][j] > a[j]){
        if(order == -1) order = i;
      }

      a[j] -= b[i][j];
    }
  }

  cout << day + 1 << ' ' << order + 1;

  return 0;
}
