/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Item{
  int _gcd;
  pair<int, int> _min;

  Item () : _gcd(0), _min({0, 0}) { }
  Item (int n) : _gcd(n), _min({n, 1}) { }

  Item operator+(Item item){
    Item result;

    if(item._gcd == 0){
      result._gcd = _gcd;
      result._min = _min;
    } else if(_gcd == 0){
      result._gcd = item._gcd;
      result._min = item._min;
    } else{
      result._gcd = __gcd(_gcd, item._gcd);
      if(item._min.first == _min.first) result._min = {_min.first, _min.second + item._min.second};
      else result._min = min(_min, item._min);
    }

    return result;
  }
};

struct SegmentTree{
  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n;
  vector<Item> st;

  SegmentTree(int n) : n(n), st(n << 2) { }

  void build(int u, int tl, int tr, vector<int> & a){
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
    if(tm <= idx) update(lp, tl, tm, idx, x);
    else update(rp, tm + 1, tr, idx, x);
    st[u] = st[lp] + st[rp];
  }

  Item query(int u, int tl, int tr, int l, int r){
    if(r < l) return 0;
    if(tl == l && tr == r) return st[u];

    int tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }

  void build(vector<int> & a){
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

  int n; cin >> n;

  vector<int> a(n); for(auto & x : a) cin >> x;

  SegmentTree st(n); st.build(a);

  int t; cin >> t;

  for(int i = 0; i < t; i++){
    int l, r; cin >> l >> r; --l, --r;
    Item item = st.query(l, r);

    int total = r - l + 1;

    if(item._gcd != item._min.first) cout << total << '\n';
    else cout << (total - item._min.second) << '\n';
  }

  return 0;
}