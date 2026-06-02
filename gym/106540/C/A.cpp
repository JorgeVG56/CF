#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

ll fact[1000005], invFact[1000005];

ll binPow(ll a, ll b){
  ll ret = 1;
  while(b){
    if(b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  fact[0] = 1; for(ll i = 1; i < 1e6 + 5; i++) fact[i] = fact[i - 1] * i % MOD;
  invFact[1000004] = binPow(fact[1000004], MOD - 2); for(ll i = 1e6 + 4; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;

  ll k; cin >> k;

  ll prob = 1;
  for(int i = 0; i < k; i++){
    ll n; cin >> n;
    ll a = (n - 1) / 2;
    prob = prob * a % MOD * (n - a - 1) % MOD * fact[3] % MOD * fact[n - 3] % MOD * invFact[n] % MOD;
    cout << prob << '\n';
  }

  return 0;
}