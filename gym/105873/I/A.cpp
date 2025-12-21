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

void dfs(int u, vi & a, vector<map<int, int>> & b, vvi & adj){
  b[u][a[u]]++;

  for(int v : adj[u]){
    dfs(v, a, b, adj);

    for(auto & [key, value] : b[v]){
      b[u][key] += value;
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vi a(n); FOR(i, 0, n) cin >> a[i];
  vvi adj(n);
  FOR(i, 0, n - 1){
    int u, v; cin >> u >> v;
    adj[u - 1].pb(v - 1);
  }

  vector<map<int, int>> b(n);
  dfs(0, a, b, adj);

  FOR(i, 0, q){
    int x, k; cin >> x >> k;
    
    cout << b[x - 1][k] << ENDL;
  }

  return 0;
}
