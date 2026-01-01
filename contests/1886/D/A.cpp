/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

struct Item{
  ll x;

  Item() : x(1) { }
  Item (ll n) : x(n) { }

  Item operator+(Item item){
    return Item(x * item.x % mod);
  }
};

struct SegmentTree{
  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n;
  vector<Item> st;

  SegmentTree(int n) : n(n), st(n << 2) { }

  void build(int u, int tl, int tr, vector<ll> & a){
    if(tl == tr){
      st[u] = a[tl];
      return ;
    }

    int tm = (tl + tr) >> 1;
    build(lp, tl, tm, a); build(rp, tm + 1, tr, a);
    st[u] = st[lp] + st[rp];
  }

  void update(int u, int tl, int tr, int idx, int x){
    if(tl == tr){
      st[u] = x;
      return;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) update(lp, tl, tm, idx, x);
    else update(rp, tm + 1, tr, idx, x);
    st[u] = st[lp] + st[rp];
  }

  Item query(int u, int tl, int tr, int l, int r){
    if(r < l) return Item();
    if(tl == l && tr == r) return st[u];

    int tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }

  void build(vector<ll> & a){
    build(0, 0, n - 1, a);
  }

  void update(int idx, int x){
    update(0, 0, n - 1, idx, x);
  }

  Item query(int l, int r){
    return query(0, 0, n - 1, l, r);
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  string s; cin >> s;

  vector<ll> a(n - 1); for(int i = 0; i < n - 1; i++) a[i] = (s[i] == '?' ? i : 1);
  SegmentTree st(n - 1); st.build(a);

  cout << st.query(0, n - 2).x << '\n';

  for(int i = 0; i < m; i++){
    int idx; cin >> idx; --idx;
    char c; cin >> c;

    st.update(idx, (c == '?' ? idx : 1));
    cout << st.query(0, n - 2).x << '\n';
  }

  return 0;
}