/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-18;
const double INF = 1e18;

struct Point {
  double x, y;

  // Operaciones Punto - Punto
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }

  // Operaciones Punto - Numero
  Point operator*(double d) const { return {x * d, y * d}; }

  bool operator<(Point p) const { return x < p.x - EPS || (abs(x - p.x) <= EPS && y < p.y - EPS); }
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }

  double dot(Point p) { return x * p.x + y * p.y; }
  double cross(Point p) const { return x * p.y - y * p.x; }
  double cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
};

double orient(Point a, Point b, Point c) { return a.cross(b, c); }

struct HalfPlane {
  Point p, pq;

  double angle;

  HalfPlane() {}
  HalfPlane(Point _p, Point _q) : p(_p), pq(_q - _p), angle(atan2(pq.y, pq.x)) {}

  bool operator<(HalfPlane b) const { return angle < b.angle; }

  bool out(Point q) { return pq.cross(q - p) < EPS; }

  Point intersect(HalfPlane l) {
    return l.p + l.pq * ((p - l.p).cross(pq) / l.pq.cross(pq));
  }
};

vector<Point> intersect(vector<HalfPlane> b) {
  vector<Point> bx = {Point{INF, INF}, Point{-INF, INF}, Point{-INF, -INF}, Point{INF, -INF}};

  for (int i = 0; i < 4; ++i) b.emplace_back(bx[i], bx[(i + 1) % 4]);

  sort(b.begin(), b.end());

  int n = (int)b.size(), q = 1, h = 0;

  vector<HalfPlane> c(b.size() + 10);

  for (int i = 0; i < n; ++i) {
    while (q < h && b[i].out(c[h].intersect(c[h - 1]))) h--;
    while (q < h && b[i].out(c[q].intersect(c[q + 1]))) q++;
    
    c[++h] = b[i];
    
    if (q < h && abs(c[h].pq.cross(c[h - 1].pq)) < EPS) {
      if (c[h].pq.dot(c[h - 1].pq) <= 0) return {};
      h--;
      if (b[i].out(c[h].p)) c[h] = b[i];
    }

  }
  
  while (q < h - 1 && c[q].out(c[h].intersect(c[h - 1]))) h--;
  while (q < h - 1 && c[h].out(c[q].intersect(c[q + 1]))) q++;
  
  if (h - q <= 1) return {};
  
  c[h + 1] = c[q];

  vector<Point> s;
  for (int i = q; i < h + 1; ++i) 
    s.push_back(c[i].intersect(c[i + 1]));
  
  return s;
}

double areaPolygon(vector<Point> p) {
  double area = 0.0;
  int n = (int)p.size();

  for(int i = 0; i < n; i++) {
    area += p[i].cross(p[(i + 1) % n]);
  }

  return abs(area) / 2.0;
}

void reorder(vector<Point>& p) {
  if (orient(p[0], p[1], p[2]) < -EPS) reverse(begin(p), end(p));

  int pos = 0;

  for(int i = 1; i < (int)p.size(); i++)
    if (Point{p[i].y, p[i].x} < Point{p[pos].y, p[pos].x}) pos = i;
      rotate(p.begin(), p.begin() + pos, p.end());
}

vector<Point> convexHull(vector<Point> pts) {
  if ((int)pts.size() <= 1) return pts;
  sort(begin(pts), end(pts));

  vector<Point> h((int)(pts.size()) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(begin(pts), end(pts)))
    for (Point p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;  // quitar = si se incluye colineares
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

vector<Point> minkowski_sum(vector<Point> p, vector<Point> q) {
  if (min((int)p.size(), (int)q.size()) < 3) {
    vector<Point> v;
    for (Point pp : p)
      for (Point qq : q) v.push_back(pp + qq);
    return convexHull(v);
  }
  reorder(p);
  reorder(q);
  for(int i = 0; i < 2; i++) p.push_back(p[i]), q.push_back(q[i]);
  vector<Point> r;
  int i = 0, j = 0;
  while (i + 2 < (int)(p.size()) || j + 2 < (int)(q.size())) {
    r.push_back(p[i] + q[j]);
    auto cross = (p[i + 1] - p[i]).cross(q[j + 1] - q[j]);
    i += cross >= -EPS;
    j += cross <= EPS;
  }
  return r;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<Point> a(n); for(auto & p : a) cin >> p.x >> p.y;

  vector<HalfPlane> b; for(int i = 0; i < (n >> 1); i++) b.push_back(HalfPlane(a[(i + 1) % n], a[i]));
  vector<HalfPlane> c; for(int i = (n >> 1); i < n; i++) c.push_back(HalfPlane(a[(i + 1) % n], a[i]));

  double ans = areaPolygon(minkowski_sum(intersect(b), intersect(c)));

  cout << fixed << setprecision(6) << ans;

  return 0;
}