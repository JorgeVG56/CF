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

  int n, m; cin >> n >> m;

  vi a(n); FOR(i, 0, n) cin >> a[i];
  
  vi inDegree(n), outDegree(n);
  vvi adj(n);
  FOR(i, 0, m){
    int u, v; cin >> u >> v;
    inDegree[u - 1]++;
    outDegree[v - 1]++;
    adj[v - 1].pb(u - 1);
  }

  priority_queue<pair<int, pair<vi, int>>> q; FOR(i, 0, n) if(inDegree[i] == 0) q.push({0, {{i}, a[i]}});

  int ans = 0;
  while(!q.empty()){

    vi needs;
    for(int u : nodes){
      for(int v : adj[u]){
        a[v] += cur;
        inDegree[v]--;
        needs.(v);
      }
    }
  }

  cout << ans;

  return 0;
}
