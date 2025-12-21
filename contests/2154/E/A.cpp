/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll tc; cin >> tc;

  for(ll c = 0; c < tc; c++){
    ll n, k; cin >> n >> k;

    vector<ll> a(n); for(auto & x : a) cin >> x;

    sort(begin(a), end(a));

    vector<ll> preffix(n); preffix[0] = a[0];
    for(ll i = 1; i < n; i++) preffix[i] = a[i] + preffix[i - 1];

    auto query = [&] (ll l, ll r) -> ll{
      if(l > r) return 0;
      ll res = preffix[r];
      if(l > 0) res -= preffix[l - 1];
      return res;
    };

    ll base = preffix[n - 1];
    ll ans = base;
    
    for(ll i = 0; i < n; i++){
      ll l = 0, r = min(i, n - i - 1);
      if(r < 0) continue;
      
      auto gain = [&](ll y) -> ll{
        ll left = min(i, y * k);
        ll leftSum = (left > 0) ? query(0, left - 1) : 0;
        ll rightSum = query(i + 1, min((ll)n - 1, i + y));
        ll res = (left + y) * a[i] - leftSum - rightSum;
        return res;
      };

      while(r - l > 3){
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll g1 = gain(m1);
        ll g2 = gain(m2);
        if(g1 < g2) l = m1;
        else r = m2;
      }

      ll maxGain = 0;
      for(ll j = l; j <= r; j++){
        maxGain = max(maxGain, gain(j));
      }

      ans = max(ans, base + maxGain);
    }

    cout << ans << '\n';
  }

  return 0;
}