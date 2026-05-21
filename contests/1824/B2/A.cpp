#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int INF = 1e9;

ll fact[200005], invFact[200005];

ll binPow(ll a, ll b){
  ll ret = 1;
  while(b){
    if(b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

ll comb(ll n, ll k){
  if(n < k) return 0;
  return fact[n] * invFact[n - k] % mod * invFact[k] % mod;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  fact[0] = 1; for(ll i = 1; i < 200005; i++) fact[i] = fact[i - 1] * i % mod;
  invFact[200004] = binPow(fact[200004], mod - 2); for(ll i = 200004; i > 0; i--) invFact[i - 1] = invFact[i] * i % mod;

  int n, k; cin >> n >> k;

  vector<vector<int>> adj(n); 
  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> size(n);
  auto dfs = [&](auto & self, int u, int p = -1) -> int {
    size[u] = 1;
    for(int v : adj[u]) if(v != p) size[u] += self(self, v, u);
    return size[u];
  }; dfs(dfs, 0);

  if(k & 1){
    cout << 1 << '\n';
    return 0;
  }

  ll ans = 1, total = binPow(comb(n, k), mod - 2);
  for(int i = 0; i < n; i++){
    ll prob = comb(size[i], k / 2) * comb(n - size[i], k / 2) % mod * total % mod;
    ans = (ans + prob) % mod;
  }

  cout << ans << '\n';

  return 0;
}