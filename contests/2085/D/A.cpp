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
    int n, k; cin >> n >> k;

    vector<ll> a(n); for(ll & x : a) cin >> x;
    vector<int> idx(n); for(int i = 0; i < n; i++) idx[i] = i;
    sort(begin(idx), end(idx), [&](int i, int j) -> bool {
      return a[i] > a[j];
    });

    set<int> st;
    for(int i = 0; i < n; i++)
      if((n - i) % (k + 1) == 0)
        st.insert(i);

    ll ans = 0;
    for(int i : idx) {
      auto it = st.lower_bound(i);
      if(it == end(st)) continue;
      ans += a[i];
      st.erase(it);
    }

    cout << ans << '\n';
  }

  return 0;
}
