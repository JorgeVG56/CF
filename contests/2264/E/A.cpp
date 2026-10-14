#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 998244353;
const int MAXN = 1e6 + 5;

ll binPow(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;
    vector<ll> cnt(n + 1);
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      cnt[x]++;
    }

    ll ans = 0;
    for(ll i = 0; i <= n; i++) {
      if(cnt[i] == 0) continue;
      ll grabL = (binPow(2, cnt[i]) - 1 + MOD) % MOD;
      ans = (ans + i * grabL) % MOD;
      ll less = 0, more = 0;
      ll x = getUniquePrime(i);
      for(int j = i + 1; j <= n; j++) {
        if(cnt[j] == 0) continue;
        if(x * x > j) less += cnt[j];
        else more += cnt[j];
      }
      ll grabOnlyLess = (binPow(2ll, less) - 1ll + MOD) % MOD;
      ans = (ans + i * grabOnlyLess % MOD * grabL % MOD) % MOD;
      ll grabOnlyMore = (binPow(2ll, more) - 1ll + MOD) % MOD;
      ans = (ans + grabOnlyMore * grabL % MOD) % MOD;
      ans = (ans + grabOnlyLess * grabOnlyMore % MOD * grabL % MOD) % MOD;
    }

    cout << ans << '\n';
  }

  return 0;
}
