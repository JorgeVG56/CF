#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define int ll
const ll INF = 4e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

struct Line {
  ll m, b;
  Line(ll m = 0, ll b = INF) : m(m), b(b) {}
  
  ll eval(ll x) {
    if (b == INF) return INF;
    ll res = m * x + b;
    if (res > INF) return INF;
    return res;
  }
};

struct Node {
  int l, r;
  int first_unvisited, last_unvisited;
  Line line;
  ll min_val;
  int min_idx;
};

vector<Node> seg;

void recompute(int node) {
  int fu = seg[node].first_unvisited;
  int lu = seg[node].last_unvisited;
  
  if (fu == -1) { 
    seg[node].min_val = INF;
    seg[node].min_idx = -1;
    return;
  }
  
  seg[node].min_val = INF;
  seg[node].min_idx = -1;
  
  ll v1 = seg[node].line.eval(fu);
  if (v1 < seg[node].min_val) {
    seg[node].min_val = v1;
    seg[node].min_idx = fu;
  }
  
  ll v2 = seg[node].line.eval(lu);
  if (v2 < seg[node].min_val) {
    seg[node].min_val = v2;
    seg[node].min_idx = lu;
  }
  
  if (seg[node].l != seg[node].r) {
    int left = 2 * node, right = 2 * node + 1;
    
    if (seg[left].first_unvisited != -1 && seg[left].min_val < seg[node].min_val) {
      seg[node].min_val = seg[left].min_val;
      seg[node].min_idx = seg[left].min_idx;
    }
    
    if (seg[right].first_unvisited != -1 && seg[right].min_val < seg[node].min_val) {
      seg[node].min_val = seg[right].min_val;
      seg[node].min_idx = seg[right].min_idx;
    }
  }
}

void build(int node, int l, int r) {
  seg[node].l = l;
  seg[node].r = r;
  seg[node].first_unvisited = l;
  seg[node].last_unvisited = r;
  seg[node].line = Line(0, INF);
  
  if (l == r) {
    if (l == 0) seg[node].line = Line(0, 0); 
    recompute(node);
    return;
  }
  
  int mid = l + (r - l) / 2;
  build(2 * node, l, mid);
  build(2 * node + 1, mid + 1, r);
  recompute(node);
}

void add_line_internal(int node, Line new_line) {
  int l = seg[node].l, r = seg[node].r;
  int mid = l + (r - l) / 2;
  
  bool better_left = new_line.eval(l) < seg[node].line.eval(l);
  bool better_mid = new_line.eval(mid) < seg[node].line.eval(mid);
  
  if (better_mid) {
    swap(seg[node].line, new_line);
  }
  
  if (l == r) {
    recompute(node);
    return;
  }
  
  if (better_left != better_mid) {
    add_line_internal(2 * node, new_line);
  } else {
    add_line_internal(2 * node + 1, new_line);
  }
  recompute(node);
}

void add_segment(int node, int ql, int qr, Line new_line) {
  if (ql <= seg[node].l && seg[node].r <= qr) {
    add_line_internal(node, new_line);
    return;
  }
  
  int mid = seg[node].l + (seg[node].r - seg[node].l) / 2;
  if (ql <= mid) add_segment(2 * node, ql, qr, new_line);
  if (qr > mid) add_segment(2 * node + 1, ql, qr, new_line);
  
  recompute(node);
}

void mark_visited(int node, int x) {
  if (seg[node].l == seg[node].r) {
    seg[node].first_unvisited = -1;
    seg[node].last_unvisited = -1;
    recompute(node);
    return;
  }
  
  int mid = seg[node].l + (seg[node].r - seg[node].l) / 2;
  if (x <= mid) mark_visited(2 * node, x);
  else mark_visited(2 * node + 1, x);
  
  int left = 2 * node, right = 2 * node + 1;
  seg[node].first_unvisited = (seg[left].first_unvisited != -1) ? seg[left].first_unvisited : seg[right].first_unvisited;
  seg[node].last_unvisited = (seg[right].last_unvisited != -1) ? seg[right].last_unvisited : seg[left].last_unvisited;
  
  recompute(node);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m, a, b; 
  cin >> n >> m >> a >> b; 
  a--, b--;
  
  vector<vector<array<ll, 4>>> ranges(n);
  for(int i = 0; i < m; i++) {
    ll u, l, r, x, k; 
    cin >> u >> l >> r >> x >> k; 
    u--, l--, r--;
    ranges[u].push_back({l, r, x, k});
  }
  
  seg.assign(4 * n, Node());
  build(1, 0, n - 1);
  
  vector<ll> final_dist(n, INF);
  
  for(int i = 0; i < n; i++) {
    int u = seg[1].min_idx;
    ll d_u = seg[1].min_val;
    
    if(u == -1 || d_u == INF) break;
    
    final_dist[u] = d_u;
    
    mark_visited(1, u);
    
    for(auto &range : ranges[u]) {
      ll l = range[0], r = range[1], x = range[2], k = range[3];
      ll b_val = d_u + x - k * l;
      
      add_segment(1, l, r, Line(k, b_val));
    }
  }
  
  if(final_dist[a] == INF || final_dist[b] == INF) cout << -1 << '\n';
  else cout << final_dist[a] + final_dist[b] << '\n';
  
  return 0;
}