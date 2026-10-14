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

struct Query {
  int l, r, idx;

  bool operator<(Query q) { return r < q.r; }
};

struct Trie {
  struct Node {
    int nxt[26];
    int suffix, id, depth, dict;

    Node() {
      memset(nxt, -1, sizeof(nxt));
      suffix = id = depth = dict = -1;
    }
  };

  vector<Node> nodes;

  int root = -1;

  Trie() {
    root = size(nodes); 
    nodes.emplace_back();
    nodes.back().depth = 0;
  }

  void insert(string & s, int idx) {
    int node = root;
    for(char c : s) {
      if(nodes[node].nxt[c - 'A'] == -1) {
        nodes[node].nxt[c - 'A'] = size(nodes);
        nodes.emplace_back();
        nodes.back().depth = nodes[node].depth + 1;
      }
      node = nodes[node].nxt[c - 'A'];
    }
    if(nodes[node].id == -1) nodes[node].id = idx;
  }

  void bfs() {
    queue<int> q;
    for(int i = 0; i < 26; i++) {
      if(nodes[root].nxt[i] == -1) {
        nodes[root].nxt[i] = root;
      } else {
        nodes[nodes[root].nxt[i]].suffix = root;
        q.push(nodes[root].nxt[i]);
      }
    }

    while(!q.empty()) {
      int u = q.front(); q.pop();
      for(int i = 0; i < 26; i++) {
        if(nodes[u].nxt[i] == -1) continue;
        int node = nodes[u].suffix;
        while(nodes[node].nxt[i] == -1) node = nodes[node].suffix;
        nodes[nodes[u].nxt[i]].suffix = nodes[node].nxt[i];
        if(nodes[nodes[node].nxt[i]].id != -1) nodes[nodes[u].nxt[i]].dict = nodes[node].nxt[i];
        else nodes[nodes[u].nxt[i]].dict = nodes[nodes[node].nxt[i]].dict;
        q.push(nodes[u].nxt[i]);
      }
    }
  }
};

struct SegmentTree {
  struct Item {
    ll idx;
    Item () : idx(INF) { }
    Item(ll n) : idx(n) { }

    Item operator+(Item item) {
      Item res;
      res.idx = min(idx, item.idx);
      return res;
    }
  };

  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n; 
  vector<Item> st;

  SegmentTree(int n) : n(n), st(n << 2) { }

  void build(int u, int tl, int tr, vector<ll> & a) {
    if(tl == tr) {
      st[u] = a[tl];
      return;
    }

    int tm = (tl + tr) >> 1;
    build(lp, tl, tm, a); build(rp, tm + 1, tr, a);
    st[u] = st[lp] + st[rp];
  }

  void update(int u, int tl, int tr, int idx, int x) {
    if(tl == tr) {
      st[u] = x;
      return;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) update(lp, tl, tm, idx, x);
    else update(rp, tm + 1, tr, idx, x);
    st[u] = st[lp] + st[rp];
  }

  Item query(int u, int tl, int tr, int l, int r) {
    if(r < l) return Item();
    if(tl == l && tr == r) return st[u];

    int tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }

  void build(vector<ll> & a) {
    build(0, 0, n - 1, a);
  }

  void update(int idx, ll x) {
    update(0, 0, n - 1, idx, x);
  }

  Item query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  string t; cin >> t;

  int g; cin >> g;
  Trie trie;
  for(int i = 1; i <= g; i++) {
    string gene; cin >> gene;
    trie.insert(gene, i);
  }
  trie.bfs();
  
  int q; cin >> q;
  vector<Query> queries(q);
  for(int i = 0; i < q; i++) {
    cin >> queries[i].l >> queries[i].r; 
    queries[i].idx = i;
  }
  sort(begin(queries), end(queries));
  
  vector<int> ans(q);
  vector<ll> minIdx(t.size(), INF);
  SegmentTree st(t.size()); st.build(minIdx);
  int r = 0, node = trie.root;
  for(Query & q : queries) {
    while(r < q.r) {
      int c = t[r++] - 'A';
      while(trie.nodes[node].nxt[c] == -1) 
        node = trie.nodes[node].suffix;
      node = trie.nodes[node].nxt[c];

      int curNode = trie.nodes[node].id != -1 ? node : trie.nodes[node].dict;
      while(curNode != -1) {
        int idx = trie.nodes[curNode].id; int length = trie.nodes[curNode].depth;
        curNode = trie.nodes[curNode].dict;
        if(minIdx[r - length] <= idx) continue;
        minIdx[r - length] = idx;
        st.update(r - length, idx);
      }
    }
    ll res = st.query(q.l - 1, q.r - 1).idx;
    ans[q.idx] = res == INF ? -1 : res;
  }

  for(auto & x : ans) cout << x << '\n';
  
  return 0;
} 