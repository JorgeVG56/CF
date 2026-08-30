#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;

    vector<ll> b(n); for(ll & x : b) cin >> x;
    vector<ll> _b(begin(b), end(b));
    sort(begin(_b), end(_b));

    bool fl = _b[0] != 0;
    map<ll, ll> mp; 
    ll cnt = 1, mx = 0;
    for(int i = 1; i < n; i++) {
      if(_b[i] == _b[i - 1]) { cnt++; continue; }
      ll sum = _b[i] - _b[i - 1];
      if(sum % cnt || sum / cnt <= mx) { fl = true; break; }
      mp[_b[i - 1]] = sum / cnt;
      mx = sum / cnt;
      cnt = 1;
    }

    if(fl) {
      cout << -1 << '\n';
      continue;
    }

    for(int i = 0; i < n; i++){
      if(mp.count(b[i])) cout << mp[b[i]] << ' ';
      else cout << mx + 1 << ' ';
    }
    cout << '\n';
  }

  return 0;
}