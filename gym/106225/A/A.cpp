#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n, k; cin >> n >> k;

    vector<int> a(n); for(int & x : a) cin >> x;

    sort(begin(a), end(a));

    auto f = [&](int x) -> bool {
      int LIM = 3 * n + 5;
      vector<int> parent(LIM + 1);
      vector<int> freq(LIM + 1, 0);
      iota(parent.begin(), parent.end(), 0);

      function<int(int)> find = [&](int v) {
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
      };
      
      auto erasePos = [&](int v) { parent[v] = find(v + 1); };

      for(int i = n - 1; i >= 0; --i) {
        int nxtAvailable = find(a[i]);
        if(nxtAvailable - a[i] <= x) {
          freq[nxtAvailable]++;
          erasePos(nxtAvailable);
        } else if(++freq[a[i] + x] > k) return false;
      }
      return true;
    };

    int lo = 0, hi = n * 2;
    while(lo < hi){
      int mi = (lo + hi) >> 1;
      if(f(mi)) hi = mi;
      else lo = mi + 1;
    }

    cout << lo << '\n';
  }

  return 0;
}