#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define int ll
const ll INF = 4e18;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;

  vector<pair<ll, ll>> ranges(n);
  vector<ll> points;
  for(int i = 0; i < n; i++) {
    ll l, r; cin >> l >> r;
    ll a = l - i, b = r - i;
    ranges[i] = {a, b};
    points.push_back(a);
    points.push_back(b + 1);
  }

  sort(begin(points), end(points));
  points.erase(unique(begin(points), end(points)), end(points));

  vector<pair<ll, ll>> segments;
  for(int i = 0; i < points.size() - 1; i++) {
    segments.push_back({points[i], points[i + 1] - 1});
  }

  auto binPow = [&] (ll a, ll b) -> ll {
    ll ret = 1;
    while(b) {
      if(b & 1) ret = ret * a % MOD;
      a = a * a % MOD;
      b >>= 1;
    }
    return ret;
  };

  ll fact[305]; fact[0] = 1;
  for(ll i = 1; i < 305; i++) fact[i] = fact[i - 1] * i % MOD;
  ll invFact[305]; invFact[304] = binPow(fact[304], MOD - 2);
  for(ll i = 304; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;

  auto comb = [&] (ll n, ll k) -> ll {
    if(k < 0 || k > n) return 0;
    ll ret = 1;
    for(ll i = n; i > (n - k); i--) ret = ret * i % MOD;
    return ret * invFact[k] % MOD;
  };

  vector<vector<ll>> pref(n);
  for(int i = 0; i < n; i++) 
    pref[i].push_back(i == 0);

  ll ans = 0;
  for(int j = 0; j < segments.size(); j++) {
    ll len = segments[j].second - segments[j].first + 1;
    for(int i = 1; i <= n; i++) {
      ll cur = 0;
      for(int k = 1; k <= i; k++) {
        if(segments[j].second < ranges[i - k].first || segments[j].first > ranges[i - k].second) break;
        cur = (cur + comb(len + k - 1, k) * pref[i - k][j] % MOD) % MOD;
      }
      if(i < n) pref[i].push_back((pref[i].back() + cur) % MOD);
      else ans = (ans + cur) % MOD;
    }
    pref[0].push_back(1);
  }

  cout << ans << '\n';
  
  return 0;
} 