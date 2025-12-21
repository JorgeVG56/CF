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

int bfs(int s, int t, vi & p, vvi & adj, vvi & cap){
  fill(ALL(p), -1); p[s] = -2;
  queue<pi> q; q.push({0, (int)INF});

  while(!q.empty()){
    auto [u, f] = q.front(); q.pop();

    for(auto v : adj[u]){
      if(p[v] != -1 || !cap[u][v]) continue;

      int newFlow = min(f, cap[u][v]);
      p[v] = u;
      if(v == t) return newFlow;
      q.push({v, newFlow});
    }
  }

  return 0;
}

int maxFlow(int s, int t, int n, vvi & adj, vvi & cap){
  int flow = 0;
  vi p(n);
  int curFlow;

  while((curFlow = bfs(s, t, p, adj, cap))){
    flow += curFlow;

    int cur = t;
    while(cur != s){
      int prev = p[cur];
      cap[prev][cur] -= curFlow;
      cap[cur][prev] += curFlow;
      cur = prev;
    }
  }

  return flow;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, s, e; cin >> n >> s >> e;

  int totalNodes = (n + 1) << 1;

  vvi adj(totalNodes), cap(totalNodes, vi(totalNodes));
  FOR(i, 0, s){
    int u; cin >> u;

    adj[0].pb((u << 1) - 1);
    adj[(u << 1) - 1].pb(0);
    cap[0][(u << 1) - 1] = 1;
  }
  
  FOR(i, 0, e){
    int u; cin >> u;
    adj[u << 1].pb(totalNodes - 1);
    adj[totalNodes - 1].pb(u << 1);
    cap[u << 1][totalNodes - 1] = 1;
  }

  FOR(i, 1, n + 1){
    adj[(i << 1) - 1].pb(i << 1);
    adj[i << 1].pb((i << 1) - 1);
    cap[(i << 1) - 1][i << 1] = 1;
  }

  int m; cin >> m;

  FOR(i, 0, m){
    int u, v; cin >> u >> v;

    adj[u << 1].pb((v << 1) - 1);
    adj[(v << 1) - 1].pb(u << 1);
    cap[u << 1][(v << 1) - 1] = 1;
  }

  cout << maxFlow(0, totalNodes - 1, totalNodes, adj, cap);

  return 0;
}
