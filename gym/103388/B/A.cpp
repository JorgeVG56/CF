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

void multiply(vvi & a, vvi & b){
  vvi c(20, vi(20));

  FOR(i, 0, 20)
    FOR(j, 0, 20)
      FOR(k, 0, 20)
        c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));

  FOR(i, 0, 20)
    FOR(j, 0, 20)
      a[i][j] = c[i][j];
}

vvi matrixPow(vvi b, int n){
  vvi a(20, vi(20)); FOR(i, 0, 20) a[i][i] = 1;

  while(n){
    if(n & 1)
      multiply(a, b);
    multiply(b, b);

    n >>= 1;
  }

  return a;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vi a(20); a[0] = 1;
  vvi b(20, vi(20));
  b[0] = {0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0};
  FOR(i, 0, 19) b[i + 1][i] = 1;

  FOR(i, 0, n){
    int x; cin >> x;

    vvi c = matrixPow(b, x);

    int ans = 0; FOR(i, 0, 20) ans = add(ans, c[i][0]);

    cout << ans << ENDL;
  }

  return 0;
}
