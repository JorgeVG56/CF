#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;

    vector<int> a(n); for(int & x : a) cin >> x;

    bool fl = true;
    int r = n;
    for(int i = 0; i < n; i++) {
      if(a[i] == i + 1) continue;
      if(a[i] > r || a[a[i] - 1] != i + 1) fl = false;
      r = a[i];
    }

    if(fl) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }

  return 0;
}
