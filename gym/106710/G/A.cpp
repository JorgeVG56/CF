#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 4e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

struct DSU {
  int n;
  vector<int> parent, rank;

  DSU(int n) : n(n), parent(n, -1), rank(n, 1) { }

  int head(int u) {
    if(parent[u] == -1) return u;
    return parent[u] = head(parent[u]);
  }

  void join(int u, int v) {
    u = head(u), v = head(v);
    if(u == v) return;
    if(rank[u] < rank[v]) swap(u, v);
    parent[v] = u;
    rank[u] += rank[v];
  }
};

struct Edge {
  int u, v, c;
};

struct GraphicMatroid {
  int n;
  vector<Edge> & edges;
  DSU dsu;

  GraphicMatroid(int n, vector<Edge> & edges) : n(n), edges(edges), dsu(n) { }
  
  void clear() { dsu = DSU(n); }
  bool check(int idx) { return dsu.head(edges[idx].u) != dsu.head(edges[idx].v); }
  void add(int idx) { dsu.join(edges[idx].u, edges[idx].v); }
};

struct ColorMatroid {
  int n;
  vector<Edge> & edges;
  vector<bool> colors;

  ColorMatroid(int n, vector<Edge> & edges) : n(n), edges(edges), colors(n) { }
  
  void clear() { fill(begin(colors), end(colors), false); }
  bool check(int idx) { return !colors[edges[idx].c]; }
  void add(int idx) { colors[edges[idx].c] = true; }
};

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n, m; cin >> n >> m;

  vector<Edge> edges(m);
  for(auto & e : edges) {
    cin >> e.u >> e.v >> e.c;
    e.u--, e.v--, e.c--;
  }

  GraphicMatroid m1(n, edges);
  ColorMatroid m2(n - 1, edges);

  vector<bool> included(m, false);
  auto augment = [&]() -> bool {
    vector<int> s, es;
    for(int i = 0; i < m; i++) {
      if(included[i]) s.push_back(i);
      else es.push_back(i);
    }

    vector<vector<int>> adj(m);
    for(int y : s) {
      m1.clear(), m2.clear();
      for(int i : s) {
        if(i == y) continue;
        m1.add(i), m2.add(i);
      }
      for(int x : es) {
        if(m1.check(x)) adj[y].push_back(x);
        if(m2.check(x)) adj[x].push_back(y);
      }
    }

    vector<bool> isSink(m), vis(m);
    queue<int> q;

    m1.clear(), m2.clear();
    for(int y : s) m1.add(y), m2.add(y);
    for(int x : es) {
      if(m1.check(x)) q.push(x), vis[x] = true;
      if(m2.check(x)) isSink[x] = true;
    }

    vector<int> prev(m, -1);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      
      if(isSink[u]) {
        for(int v = u; v != -1; v = prev[v]) included[v] = !included[v];
        return true;
      }

      for(int v : adj[u]) {
        if(vis[v]) continue;
        vis[v] = true;
        prev[v] = u;
        q.push(v);
      }
    }

    return false;
  };

  int calls = 0;
  while(augment()) calls++;

  if(calls != n - 1){
    cout << "-1" << '\n';
    return 0;
  }

  for(int i = 0; i < m; i++) 
    if(included[i]) 
      cout << i + 1 << ' ';
  cout << '\n';
  
  return 0;
}
