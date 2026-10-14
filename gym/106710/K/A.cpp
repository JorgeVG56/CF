#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

struct Point {
  ll x, y;

  friend istream & operator>>(istream & in, Point & p) {
    in >> p.x >> p.y;
    return in;
  }
};

struct Rectangle {
  Point p1, p2;

  friend istream & operator>>(istream & in, Rectangle & r) {
    in >> r.p1 >> r.p2;
    return in;
  }
};

struct Event {
  ll y1, y2, delta;
};

struct LazySegmentTree {
  struct Item {
    int mn, mx, sum;
    bool leftOn, rightOn;
    ll area;

    Item() : mn(0), mx(0), sum(0), leftOn(0), rightOn(0), area(0) { }
    
    Item operator+(const Item & item) const {
      Item ret;
      ret.mn = min(mn, item.mn); ret.mx = max(mx, item.mx);
      ret.sum = sum + item.sum; if(rightOn && item.leftOn) ret.sum -= 2;
      ret.leftOn = leftOn; ret.rightOn = item.rightOn;
      return ret;
    }

    void operator+=(int x) {
      mn += x, mx += x;
      if(mn > 0) sum = 2, leftOn = true, rightOn = true;
      else if(mx == 0) sum = 0, leftOn = false, rightOn = false;
    }
  };

  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n;
  vector<Item> st;
  vector<int> lazy;
  vector<ll> val;

  LazySegmentTree(int n, vector<ll> & val) : n(n), st(n << 2), lazy(n << 2), val(val) { }

  void apply(int u, int x) { 
    st[u] += x; lazy[u] += x; 
  }

  void push(int u) { 
    apply(lp, lazy[u]); apply(rp, lazy[u]); 
    lazy[u] = 0; 
  }

  void update(int u, int tl, int tr, int l, int r, int x) {
    if(r < l) return;
    if(l == tl && r == tr) {
      int newmn = st[u].mn + x, newmx = st[u].mx + x;
      if(tl == tr || newmn > 0 || newmx == 0) { 
        apply(u, x); 
        return; 
      }
    }
    push(u);
    int tm = (tl + tr) >> 1;
    update(lp, tl, tm, l, min(tm, r), x); update(rp, tm + 1, tr, max(l, tm + 1), r, x);
    st[u] = st[lp] + st[rp];
  }

  ll queryArea(int u, int tl, int tr) {
    if(st[u].mn > 1 || st[u].mx < 1) return 0ll;
    if(st[u].mn == 1 && st[u].mx == 1) return val[tr + 1] - val[tl];
    push(u);
    int tm = (tl + tr) >> 1;
    return queryArea(lp, tl, tm) + queryArea(rp, tm + 1, tr);
  }

  void update(int l, int r, ll x) { 
    update(0, 0, n - 1, l, r, x); 
  }

  ll queryArea() { 
    return queryArea(0, 0, n - 1); 
  }
};

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;

  set<ll> stX, stY;
  vector<Rectangle> rectangles(n);
  for(auto & r : rectangles) {
    cin >> r;
    stX.insert(r.p1.x); stX.insert(r.p2.x);
    stY.insert(r.p1.y); stY.insert(r.p2.y);
  }

  map<ll, int> mpX, mpY;
  vector<ll> revValueX, revValueY;
  for(auto & x : stX) mpX[x] = mpX.size(), revValueX.push_back(x);
  for(auto & y : stY) mpY[y] = mpY.size(), revValueY.push_back(y);

  for(auto & r : rectangles) r.p1.x = mpX[r.p1.x], r.p2.x = mpX[r.p2.x], r.p1.y = mpY[r.p1.y], r.p2.y = mpY[r.p2.y];

  vector<vector<Event>> evX(stX.size());
  for(auto & r : rectangles) {
    evX[r.p1.x].push_back({r.p1.y, r.p2.y, +1});
    evX[r.p2.x].push_back({r.p1.y, r.p2.y, -1});
  }

  ll area = 0, perimeter = 0;
  LazySegmentTree stTreeY(stY.size(), revValueY);
  for(int i = 0; i + 1 < (int)evX.size(); i++) {
    for(auto & e : evX[i]) stTreeY.update(e.y1, e.y2 - 1, e.delta);
    ll width = revValueX[i + 1] - revValueX[i];
    perimeter += width * stTreeY.st[0].sum;
    area += width * stTreeY.queryArea();
  }
  for(auto & e : evX.back()) stTreeY.update(e.y1, e.y2 - 1, e.delta);

  vector<vector<Event>> evY(stY.size());
  for(auto & r : rectangles) {
    evY[r.p1.y].push_back({r.p1.x, r.p2.x, +1});
    evY[r.p2.y].push_back({r.p1.x, r.p2.x, -1});
  }

  LazySegmentTree stTreeX(stX.size(), revValueX);
  for(int i = 0; i + 1 < (int)evY.size(); i++) {
    for(auto & e : evY[i]) stTreeX.update(e.y1, e.y2 - 1, e.delta);
    ll width = revValueY[i + 1] - revValueY[i];
    perimeter += width * stTreeX.st[0].sum;
  }

  cout << area << ' ' << perimeter << '\n';
  return 0;
}