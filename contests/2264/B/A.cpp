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
    ll n, m; cin >> n >> m;
    vector<ll> a(n); for(ll & x : a) cin >> x;

    ll ans = -INF, cur = 0;
    priority_queue<ll> pq;
    for(int i = 0; i < m - 1; i++) 
      cur -= a[i], pq.push(a[i]);

    for(int i = m - 1; i < n; i++) {
      ans = max(ans, cur + m * a[i]);
      if(pq.empty() || a[i] >= pq.top()) continue;
      cur += pq.top(); cur -= a[i];
      pq.pop(); pq.push(a[i]);
    }

    cout << ans << '\n';
  }

  return 0;
}
