#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 998244353;
const int MAXN = 2e5 + 5;

ll binPow(ll a, ll b, ll mod) {
  ll ret = 1;
  while(b) {
    if(b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  vector<ll> fact(MAXN); fact[0] = 1;
  for(ll i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
  vector<ll> invFact(MAXN); invFact[MAXN - 1] = binPow(fact[MAXN - 1], MOD - 2, MOD);
  for(ll i = MAXN - 1; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;
  
  int n, k; cin >> n >> k;

  ll ans = 0;
  ll invK = binPow(k, MOD - 2, MOD), pot2 = 1;

  for(int i = 1; i <= n; i++) {
    invK = invK * invK % MOD, pot2 = pot2 * 2ll % MOD;
    ll ways = 1;
    for(ll j = 1; j < k; j++) ways = ways * ((pot2 + j) % MOD) % MOD;

    ll top = ways * invFact[k - 1] % MOD;
    ll sorted = top * invK % MOD;
    ll notSorted = (1 - sorted + MOD) % MOD;
    ans = (ans + notSorted) % MOD;
  }

  cout << ans << '\n';
  
  return 0;
}
