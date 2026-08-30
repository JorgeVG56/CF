#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 998244353;

ll fact[1000005], invFact[1000005];

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
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  fact[0] = 1; 
  for(ll i = 1; i < 1000005; i++) fact[i] = fact[i - 1] * i % MOD;
  invFact[1000004] = binPow(fact[1000004], MOD - 2);
  for(ll i = 1000004; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;
  
  auto comb = [&](ll n, ll k) -> ll {
    if(k < 0 || k > n) return 1;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
  };
  
  int t; cin >> t;
  
  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;

    string s; cin >> s;

    ll cA = 0, cB = 0; 
    for(char c : s) cA += c == '0', cB += c != '0';
    ll rA = s[0] == '0', rB = s[0] != '0'; 
    for(int i = 1; i < n; i++) if(s[i] != s[i - 1]) rA += s[i] == '0', rB += s[i] != '0';
    
    cout << comb(cA - 1, rA - 1) * comb(cB - 1, rB - 1) % MOD << '\n';
  }

  return 0;
}