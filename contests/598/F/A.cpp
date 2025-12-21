/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point{
  double x, y;

  Point operator+(Point p){ return {x + p.x, y + p.y}; }
  Point operator-(Point p){ return {x - p.x, y - p.y}; }

  Point operator*(double a){ return {x * a, y * a}; }
  Point operator/(double a){ return {x / a, y / a}; }

  bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }
  
  double dot(Point p) { return x * p.x + y * p.y; }
  double cross(Point p) { return x * p.y - y * p.x; }
  double cross(Point a, Point b) { return (a - *this).cross(b - *this); }
};

struct Segment{
  Point l, r;
};

double dist(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }
double orient(Point a, Point b, Point c){ return a.cross(b, c); }

bool properInter(Point a, Point b, Point c, Point d, Point & p){
  double  oa = orient(c, d, a),
          ob = orient(c, d, b),
          oc = orient(a, b, c),
          od = orient(a, b, d);
  if(oa * ob < 0 && oc * od < 0){
    p = (a * ob - b * oa) / (ob - oa);
    return true;
  }
  return false;
}

bool inDisk(Point a, Point b, Point p) { return (a - p).dot(b - p) <= 0; }

bool onSegment(Point a, Point b, Point p) {
  return a.cross(b, p) == 0 && inDisk(a, b, p);
}

vector<Point> segInter(Point a, Point b, Point c, Point d){
  Point p;
  if(properInter(a, b, c, d, p)) return {p};
  set<Point> s;
  if (onSegment(c, d, a)) s.insert(a);
  if (onSegment(c, d, b)) s.insert(b);
  if (onSegment(a, b, c)) s.insert(c);
  if (onSegment(a, b, d)) s.insert(d);
  return {begin(s), end(s)};
}

int inPolygon(vector<Point> poly, Point p) {
  int n = (int) size(poly), ans = 0;
  for(int i = 0; i < n; i++) {
    Point p1 = poly[i], p2 = poly[(i + 1) % n];
    if (p1.y > p2.y) swap(p1, p2);
    if (onSegment(p1, p2, p)) return 0;
    ans ^= (p1.y <= p.y && p.y < p2.y && p.cross(p1, p2) > 0);
  }
  return ans ? -1 : 1;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<Point> a(n); for(auto & p : a) cin >> p.x >> p.y;
  vector<Segment> b(m); for(auto & s : b) cin >> s.l.x >> s.l.y >> s.r.x >> s.r.y;
  vector<Segment> c(n); for(int i = 0; i < n; i++) c[i].l = a[i], c[i].r = a[(i + 1) % n];

  for(auto & i : b){
    set<Point> st;
    for(auto & j : c){
      vector<Point> inter = segInter(i.l, i.r, j.l, j.r);
      st.insert(begin(inter), end(inter));
    }

    vector<Point> points(begin(st), end(st));
    double ans = 0;
    for(int k = 1; k < (int) size(points); k++){
      double d = dist(points[k - 1], points[k]);
      Point midPoint = (points[k - 1] + points[k]) / 2;
      if(inPolygon(a, midPoint) != 1) ans += d; 
    }

    cout << fixed << setprecision(8) << ans << '\n';
  }

  return 0;
}