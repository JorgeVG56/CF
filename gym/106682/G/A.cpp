#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;
const double PI = acos(-1);

struct Point {
  ll x, y;
  
  Point(ll x = 0, ll y = 0) : x(x), y(y) { }
  
  Point minSemejant() const {
    if(x == 0 && y == 0) return Point();
    if(x == 0) return Point(0, 1);
    if(y == 0) return Point(1, 0);
    ll nX = x, nY = y;
    if(nY < 0) {
      nX *= -1;
      nY *= -1;
    }
    
    ll gcd = __gcd(abs(nX), abs(nY));
    
    return {nX / gcd, nY / gcd};
  }
  
  ll distToOrigin() {
    return x * x + y * y;
  }
  
  bool operator<(const Point & p) const { return x < p.x || (x == p.x && y < p.y); }
  bool operator==(const Point & p) const { return x == p.x && y == p.y; }
};

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n; cin >> n;
  
  vector<Point> points(n); 
  for(auto & p : points) cin >> p.x >> p.y;
  for(auto & p : points) p.x *= 2, p.y *= 2;
  
  map<ll, vector<Point>> mpDist;
  for(auto & p : points) mpDist[p.distToOrigin()].push_back(p);
  
  map<Point, vector<Point>> mpAng;
  for(auto & p : points) mpAng[p.minSemejant()].push_back(p);
  
  if(!mpAng[{0, 0}].empty()) {
    for(auto & [p, v] : mpAng) 
      if(p.x != 0 || p.y != 0)
        v.push_back({0, 0});
    mpAng.erase({0, 0});
  }
  
  for(auto & [p, v] : mpAng) sort(begin(v), end(v));

  ll totalPairs = 0;
  for(auto & [d, v] : mpDist) {
    ll sz = v.size();
    totalPairs += (sz * (sz - 1)) / 2;
  }
  
  vector<Point> middleP; middleP.reserve(totalPairs);
  vector<Point> originP; originP.reserve(totalPairs);
  for(auto & [d, v] : mpDist) {
    for(int i = 0; i < v.size(); i++) {
      for(int j = i + 1; j < v.size(); j++) {
        Point A = v[i], B = v[j];
        Point middle = {(A.x + B.x) / 2, (A.y + B.y) / 2};
        if(middle == Point()) originP.push_back(A.minSemejant());
        else middleP.push_back(middle);
      }
    }
  }

  sort(begin(middleP), end(middleP));
  sort(begin(originP), end(originP));
  
  ll ans = 0;
  for(int i = 0; i < middleP.size(); i++) {
    Point p = middleP[i];
    ll cnt = 1;
    while(i < middleP.size() - 1 && middleP[i] == middleP[i + 1]) i++, cnt++;
    auto line = mpAng.find(p.minSemejant());
    if(line == mpAng.end()) continue;
    if(line -> second.size() < 2) continue;
    ll leftCount = distance(line -> second.begin(), lower_bound(line -> second.begin(), line -> second.end(), p));
    ll rightCount = distance(upper_bound(line -> second.begin(), line -> second.end(), p), line -> second.end());
    ans += leftCount * rightCount * cnt;
  }

  map<Point, ll> cntOrig;

  for(int i = 0; i < originP.size(); i++) {
    Point pOriginal = originP[i];
    ll cnt = 1;
    while(i < originP.size() - 1 && originP[i] == originP[i + 1]) i++, cnt++;
    Point pA = {-pOriginal.y, pOriginal.x};
    auto line = mpAng.find(pA.minSemejant());
    if(line == mpAng.end()) continue;
    if(line -> second.size() < 2) continue;
    Point p;
    ll leftCount = distance(line -> second.begin(), lower_bound(line -> second.begin(), line -> second.end(), p));
    ll rightCount = distance(upper_bound(line -> second.begin(), line -> second.end(), p), line -> second.end());
    ans += leftCount * rightCount * cnt;
    cntOrig[pOriginal.minSemejant()] = cnt;
    if(cntOrig.count(pA.minSemejant())) {
      ans -= cnt * cntOrig[pA.minSemejant()];
    }
  }

  cout << ans << '\n';
  
  return 0;
}
