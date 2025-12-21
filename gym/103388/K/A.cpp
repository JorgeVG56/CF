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

const int dx[] = {-1, 1, 2, 2, -1, 1, -2, -2};
const int dy[] = {2, 2, -1, 1, -2, -2, -1, 1};
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

/**
* Descripcion: algoritmo para calcular el flujo maximo en un grafo
* Tiempo: O(V^2 E)
*/

template<typename T>
struct Dinic {

  #define INF numeric_limits<T>::max()

  struct Edge {
    int to, rev;
    T c, oc;
    T flow(){ 
      return max(oc - c, T(0)); 
    }  
  };

  vi lvl, ptr, q;
  vector<vector<Edge>> adj;

  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}

  void addEdge(int a, int b, T c, T rcap = 0) {
    adj[a].push_back({b, SZ(adj[b]), c, c});
    adj[b].push_back({a, SZ(adj[a]) - 1, rcap, rcap});
  }

  T dfs(int v, int t, T f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < SZ(adj[v]); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1) if (T p = dfs(e.to, t, min(f, e.c))) {
        e.c -= p, adj[e.to][e.rev].c += p;
        return p;
      }
    }
    return 0;
  }
  
  T calc(int s, int t) {
    T flow = 0;
    q[0] = s;
    FOR(L, 0, 31){
      do{
        lvl = ptr = vi(SZ(q));
        int qi = 0, qe = lvl[s] = 1;
        while (qi < qe && !lvl[t]) {
          int v = q[qi++];
          for (Edge e : adj[v]) if (!lvl[e.to] && e.c >> (30 - L)) q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
        }
        
        while (T p = dfs(s, t, INF)) flow += p;
      } while (lvl[t]);
    }
    
    return flow;
  }
  
  bool leftOfMinCut(int a){
    return lvl[a] != 0;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
 int t,d,m;
 cin>>t>>d>>m; 
 int start=0;
 bool ok = false;
 FOR(i,0,m)
 {
    int me;
    cin>>me;
    if(me-start >= t)
    {
      ok=true;
    }
    start= me;
 }
 if(d-start>=t)
 {
  cout<<"Y"<<ENDL;
return 0; 
}
if(ok)
{
  cout<<"Y"<<ENDL;
}
else
{
  cout<<"N"<<ENDL;
}
  return 0;
}
