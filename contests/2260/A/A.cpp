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

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;
    vector<int> a(n); for(int & x : a) cin >> x;
    if(n == 1) {
      cout << (a[0] == '0' ? 0 : -1) << '\n';
      continue;
    }

    int total = accumulate(begin(a), end(a), 0);
    if(n - total < 2) {
      cout << -1 << '\n';
      continue;
    }

    cout << a[0] + a[n - 1] << '\n';
  }
  
  return 0;
} 