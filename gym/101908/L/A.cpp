/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct STree{
  #define ls (v << 1) + 1
  #define rs (v << 1) + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr

  int n;
  vector<int> st, lazy;

  STree(int n){
    this->n = n;
    st.assign(n << 2, 0);
    lazy.assign(n << 2, 0);
  }

  void apply(int v, int tl, int tr, int val){
    st[v] += val * (tr - tl);
    lazy[v] += val;
  }

  void push(int v, int tl, int tr){
    if(lazy[v]){
      int tm = (tl + tr) >> 1;
      apply(lp, lazy[v]), apply(rp, lazy[v]);
      lazy[v] = 0;
    }
  }

  int query(int v, int tl, int tr, int l, int r){
    if(tr <= l || r <= tl) return 0;
    if(l <= tl && tr <= r) return st[v];
    push(v, tl, tr);
    int tm  = (tl + tr) >> 1;
    return query(lp, l, r) + query(rp, l, r);
  }

  void upd(int v, int tl, int tr, int l, int r, int val) {
    if (tr <= l || r <= tl) return;
    if (l <= tl && tr <= r) { apply(v, tl, tr, val); return; }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(lp, l, r, val), upd(rp, l, r, val);
    st[v] = st[ls] + st[rs];
  }

  int query(int l, int r) {
    return query(0, 0, n, l, r);
  }

  void upd(int l, int r, int val) {
    upd(0, 0, n, l, r, val);
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<vector<int>> adj(n);

  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> par(n, -1), sz(n, 1), head(n), pos(n), depth(n);

  auto dfsSZ = [&](auto & self, int u) -> void{
    if(par[u] != -1) adj[u].erase(find(begin(adj[u]), end(adj[u]), par[u]));

    for(auto & v : adj[u]){
      depth[v] = depth[u] + 1;
      par[v] = u;
      self(self, v);
      sz[u] += sz[v];
      if(sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
    }
  };

  int t = 0;
  auto dfs = [&](auto & self, int u) -> void{
    pos[u] = t++;
    for(auto & v : adj[u]){
      head[v] = (v == adj[u][0] ? head[u] : v);
      self(self, v);
    }
  };

  dfsSZ(dfsSZ, 0);
  dfs(dfs, 0);

  STree st(n);

  auto updatePath = [&](int u, int v, int val) -> void{
    while(head[u] != head[v]){
      if(depth[head[u]] > depth[head[v]]){
        st.upd(pos[head[u]], pos[u] + 1, val);
        u = par[head[u]];
      } else{
        st.upd(pos[head[v]], pos[v] + 1, val);
        v = par[head[v]];
      }
    }

    st.upd(min(pos[u], pos[v]), max(pos[u], pos[v]) + 1, val);
  };

  auto queryPath = [&](int u, int v) -> int{
    int ans = 0;

    while(head[u] != head[v]){
      if(depth[head[u]] > depth[head[v]]){
        ans += st.query(pos[head[u]], pos[u] + 1);
        u = par[head[u]];
      } else{
        ans += st.query(pos[head[v]], pos[v] + 1);
        v = par[head[v]];
      }
    }

    ans += st.query(min(pos[u], pos[v]), max(pos[u], pos[v]) + 1);

    return ans;
  };

  for(int i = 0; i < q; i++){
    int a, b, c, d; cin >> a >> b >> c >> d; --a, --b, --c, --d;

    updatePath(a, b, 1);
    cout << queryPath(c, d) << '\n';
    updatePath(a, b, -1);
  }

  return 0;
}