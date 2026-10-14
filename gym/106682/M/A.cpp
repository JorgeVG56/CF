#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

struct LazySegmentTree {
  struct Item {
    ll cap, cur, res;

    Item(ll x = 0) : cap(x), cur(0), res(x) { }

    Item operator+(Item item) {
      Item res;
      res.cap = cap + item.cap;
      res.cur = cur + item.cur;
      return res;
    }
  };

  #define lp (u << 1) + 1
  #define rp (u << 1) + 2
  
  int n;
  vector<Item> st;
  vector<int> lazy;

  LazySegmentTree(int n) : n(n), st(n << 2), lazy(n << 2) { }

  void apply(int u, int x) {
    if(x == 1) {
      st[u].cur = st[u].cap;
      lazy[u] = x;
    } else if(x == -1) {
      st[u].cur = 0;
      lazy[u] = x;
    }
  }

  void push(int u) {
    apply(lp, lazy[u]);
    apply(rp, lazy[u]);
    lazy[u] = 0;
  }

  void build(int u, int tl, int tr, vector<ll> & a) {
    if(tl == tr) {
      st[u] = a[tl];
      return;
    }
    int tm = (tl + tr) >> 1;
    build(lp, tl, tm, a); build(rp, tm + 1, tr, a);
    st[u] = st[lp] + st[rp];
  }

  Item query(int u, int tl, int tr, int l, int r) {
    if(r < l) return Item();
    if(tl == l && tr == r) return st[u];
    push(u);
    int tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }

  void fill(int u, int tl, int tr, int l, int r) {
    if(r < l) return;
    if(tl == l && tr == r) {
      apply(u, 1);
      return;
    }
    push(u);
    int tm = (tl + tr) >> 1;
    fill(lp, tl, tm, l, min(tm, r));
    fill(rp, tm + 1, tr, max(l, tm + 1), r);
    st[u] = st[lp] + st[rp];
  }

  void empty(int u, int tl, int tr, int l, int r) {
    if(r < l) return;
    if(tl == l && tr == r) {
      apply(u, -1);
      return;
    }
    push(u);
    int tm = (tl + tr) >> 1;
    empty(lp, tl, tm, l, min(tm, r));
    empty(rp, tm + 1, tr, max(l, tm + 1), r);
    st[u] = st[lp] + st[rp];
  }

  void update(int u, int tl, int tr, int idx, int x) {
    if(tl == tr) {
      st[u].cur += x;
      return;
    }
    push(u);
    int tm = (tl + tr) >> 1;
    if(idx <= tm) update(lp, tl, tm, idx, x);
    else update(rp, tm + 1, tr, idx, x);
    st[u] = st[lp] + st[rp];
  }

  void build(vector<ll> & a) {
    build(0, 0, n - 1, a);
  }

  Item query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }

  void fill(int l, int r) {
    fill(0, 0, n - 1, l, r);
  }

  void empty(int l, int r) {
    empty(0, 0, n - 1, l, r);
  }

  void update(int idx, int x) {
    update(0, 0, n - 1, idx, x);
  }
};

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n, m; cin >> n >> m;
  vector<ll> a(n); for(ll & x : a) cin >> x;

  LazySegmentTree st(n); st.build(a);

  for(int i = 0; i < m; i++) {
    int type; cin >> type;

    if(type == 1) {
      ll b, v; cin >> b >> v; --b;
      int l = 0, r = b, j = -1;
      while(l <= r) {
        int m = (l + r) >> 1;
        auto res = st.query(m, b);
        if(res.cap - res.cur >= v) {
          j = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      auto res = st.query(j + 1, b);
      v -= (res.cap - res.cur);
      st.fill(j + 1, b);
      if(j >= 0) st.update(j, v);
    } else {
      int l, r; cin >> l >> r; --l, --r;
      auto res = st.query(l, r);
      cout << res.cur << '\n';
      st.empty(l, r);
    }
  }

  return 0;
}
