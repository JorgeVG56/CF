/*
Pura gente del Coach Moy


*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point{
  int first, second;
};

struct Edge{
  int u, v;
  ll w;
};

struct DSU {
  vector<int> e;
  
  DSU (int n) : e(n, -1) { }
  
  int size(int x) { return -e[get(x)]; }
  
  int get(int x) { return e[x]<0?x:e[x]=get(e[x]);}
  
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

vector<Edge> sweep(vector<Point> & a){
  vector<int> ids(a.size());
  iota(begin(ids), end(ids), 0);
  vector<Edge> edges;
  
  for(int phase = 0; phase < 4; phase++){
    sort(begin(ids), end(ids), [&] (auto & i, auto & j) -> bool {
      return a[i].first + a[i].second < a[j].first + a[j].second;
    });
    
    map<int, int, greater<int>> active;
    for(int i : ids){
      for(auto it = active.lower_bound(a[i].first); it != active.end(); active.erase(it++)){
        int j = it -> second;
        if (a[i].first - a[i].second > a[j].first - a[j].second) break;
        edges.push_back({i, j, abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second)});
      }
      
      active[a[i].first] = i;
    }
    
    for (auto & p : a) {
      if (phase & 1) p.first *= -1;
      else swap(p.first, p.second);
    }
  }

  return edges;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  
  vector<Point> a(n); 
  for(int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second; 
  }

  vector<Edge> candidates = sweep(a);
  
  sort(begin(candidates), end(candidates), [&] (auto & a, auto & b) -> bool {
    return a.w < b.w;
  });
  
  DSU dsu(n);
  ll mst = 0;
  for(auto & e : candidates){
    if(dsu.join(e.u, e.v)){
      mst += e.w;
    }
  }
  
  cout << mst << '\n';
  
  return 0;
}