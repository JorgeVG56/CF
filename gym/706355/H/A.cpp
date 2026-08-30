#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> a(n); 
    for(int i = 0; i < n; i++) {
      cin >> a[i].first.first >> a[i].first.second;
      a[i].second = i;
    }
    sort(begin(a), end(a));

    vector<int> color(n, 0);
    int mx = a[0].first.second;
    for(int i = 0; i < n; i++){
      if(a[i].first.first > mx) break;
      color[a[i].second] = 1;
      mx = max(mx, a[i].first.second);
    }

    if(*min_element(begin(color), end(color)) != 0){
      cout << -1 << '\n';
    } else {
      for(int i = 0; i < n; i++) cout << color[i] + 1 << ' ';
      cout << '\n';
    }
  }

  return 0;
}