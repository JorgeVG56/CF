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

struct SegmentTree {
  struct Item {
    ll l, r;
    ll p[4];

    Item(ll x = -1) {
      if(x == -1) {
        l = r = p[0] = p[1] = p[2] = p[3] = -1;
      } else {
        l = r = x;
        p[0] = p[1] = p[2] = p[3] = 0;
        p[r * 2 + l] = 1;
      }
    }

    Item operator+(Item item) {
      Item res;
      if(l == -1) res = item;
      else if(item.l == -1) res = *this;
      else {
        res.l = l, res.r = item.r;  
        res.p[0] = p[0] + item.p[0];
        res.p[1] = p[1] + item.p[1];
        res.p[2] = p[2] + item.p[2];
        res.p[3] = p[3] + item.p[3];
        res.p[r * 2 + l]--;
        res.p[item.r * 2 + item.l]--;
        res.p[r * 2 + item.l]++;
        res.p[res.r * 2 + res.l]++;
      } 
      return res;
    }
  };

  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n;
  vector<Item> st;

  SegmentTree(int n) : n(n), st(n << 2) { }

  void build(int u, int tl, int tr, vector<int> & a) {
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

    int tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }

  void build(vector<int> & a) {
    build(0, 0, n - 1, a);
  }

  Item query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> a(n);
  for(int i = 0; i < n; i++) a[i] = s[i] - '0';
  SegmentTree st(n); st.build(a);

  for(int i = 0; i < q; i++) {
    int l, r; cin >> l >> r; --l, --r;
    auto res = st.query(l, r);
    // cout << res.p[0] << ' ' << res.p[1] << ' ' << res.p[2] << ' ' << res.p[3] << '\n';
    if(res.p[0] < res.p[3]) swap(res.p[0], res.p[3]);

    ll needs = max({0ll, (res.p[0] - res.p[1] + 1) / 2, (res.p[0] + res.p[3] - 2 * res.p[1] + 2) / 3});
    ll ans = 2 * res.p[1] - res.p[0] - res.p[3] + 4 * needs;
    cout << ans << '\n';
  }
  
  return 0;
} 