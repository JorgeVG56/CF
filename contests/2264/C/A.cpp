#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 998244353;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;

    vector<ll> a(n); for(ll & x : a) cin >> x;

    sort(rbegin(a), rend(a));
    vector<ll> preffix(n + 1); for(int i = 0; i < n; i++) preffix[i + 1] = (preffix[i] + a[i]) % MOD;

    ll ans = 0, fact = 1;

    for(ll i = 1; i < n; i++) {
      ans = ans * i % MOD;
      ll add = fact * (preffix[i] - i * a[i] % MOD + MOD) % MOD;
      ans = (ans + add) % MOD;
      fact = fact * i % MOD;
    }

    cout << ans << '\n';
  }

  return 0;
}
