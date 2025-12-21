/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct PersistentSegTree{
  struct Node{
    int mn;
    int l, r;
  };

  int n;
  vector<Node> nodes;
  int timer = 0;

  PersistentSegTree(int n) : n(n), nodes(n * 32) { }

  Node join(int l, int r){ return {min(nodes[l].mn, nodes[r].mn), l, r}; }

  int init(int tl, int tr){
    if(tl == tr){
      nodes[timer] = {(int)1e9, 0, 0};
      return timer++;
    }

    int tm = (tl + tr) >> 1;
    nodes[timer] = join(init(tl, tm), init(tm + 1, tr));
    return timer++;
  }

  int update(int u, int tl, int tr, int idx, int x){
    if(tl == tr){
      nodes[timer] = {x, 0, 0};
      return timer++;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) nodes[timer] = join(update(nodes[u].l, tl, tm, idx, x), nodes[u].r);
    else nodes[timer] = join(nodes[u].l, update(nodes[u].r, tm + 1, tr, idx, x));

    return timer++;
  }

  int query(int u, int tl, int tr, int l, int r){
    if(r < l) return (int)1e9;
    if(tl == l && tr == r) return nodes[u].mn;

    int tm = (tl + tr) >> 1;
    return min(query(nodes[u].l, tl, tm, l, min(tm, r)), query(nodes[u].r, tm + 1, tr, max(l, tm + 1), r));
  }

  int init(){ return init(0, n - 1); }
  int update(int root, int idx, int x){ return update(root, 0, n - 1, idx, x); }
  int query(int root, int l, int r){ return query(root, 0, n - 1, l, r); }
};


signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<int> a(n); for(auto & x : a) cin >> x;

  PersistentSegTree st(n);

  vector<int> roots(n + 1);
  roots[n] = st.init();

  map<int, int> pos;
  for(int i = n - 1; i >= 0; i--){
    if(pos.count(a[i])) roots[i] = st.update(roots[i + 1], pos[a[i]], pos[a[i]] - i);
    else roots[i] = roots[i + 1];
    pos[a[i]] = i;
  }

  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r; --l, --r;
    int mn = st.query(roots[l], l, r);
    cout << (mn == (int)1e9 ? -1 : mn) << '\n';
  }

  return 0;
}