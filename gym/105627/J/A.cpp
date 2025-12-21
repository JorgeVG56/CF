/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr
  #define NEUT (int) 1e9

  int n;
  vector<int> st, lazy;

  STree (int n): n(n), st(4 * n, 0), lazy (4 * n, 0){}

  void apply (int v, int tl, int tr, int val) {
    st[v] += val;
    lazy[v] += val;
  }
 
  void push (int v, int tl, int tr) {
    if (lazy[v]){
      int tm = (tl + tr) / 2;
      apply(lp,lazy[v]), apply(rp,lazy[v]);
      lazy[v] = 0;
    }
  }

  int query(int v, int tl, int tr, int l, int r){
    if (tr <= l || r <= tl) return NEUT;
    if (l <= tl && tr <= r) return st[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return min(query(lp, l, r), query(rp, l, r));
  }

  void upd(int v, int tl, int tr, int l, int r, int val){
    if(tr <= l || r <= tl) return;
    if(l <= tl && tr <= r){
      apply(v, tl, tr, val);
      return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(lp, l, r, val), upd(rp, l, r, val);
    st[v] = min(st[ls], st[rs]);
  }

  int query(int l, int r) {
    return query(0, 0, n, l, r);
  }

  void upd(int l, int r, int val){
    upd(0, 0, n, l, r, val);
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<pair<int, int>> a(n);
  
  for(int i = 0; i < n; i++){
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(rbegin(a), rend(a));

  int window = n - m + 1;
  vector<int> ans(n, 1);

  STree st (window);

  for(int i = 0; i < n;){
    int j = i;
    int val = a[i].first;

    while(i < n && a[i].first == val) i++;

    for(int k = j; k < i; k++){
      int l = max(0, a[k].second - m + 1);
      int r = min(a[k].second, n - m);

      ans[a[k].second] = st.query(l, r + 1) + 1;
    }

    for(int k = j; k < i; k++){
      int l = max(0, a[k].second - m + 1);
      int r = min(a[k].second, n - m);

      st.upd(l, r + 1, 1);
    }
  }

  for(int i = 0; i < n; i++){
    cout << ans[i] << ' ';
  }

  return 0;
}