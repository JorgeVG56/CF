/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll t; cin >> t;

  for(ll _t = 0; _t < t; _t++){
    ll n, y; cin >> n >> y;

    vector<ll> a(n); for(ll & x : a) cin >> x;
    vector<ll> cnt((ll)2e5 + 5); for(ll & x : a) cnt[x]++;
    vector<ll> preffixSum((ll)2e5 + 5); for(ll i = 1; i < (ll)2e5 + 5; i++) preffixSum[i] = cnt[i] + preffixSum[i - 1];

    ll mx = *max_element(begin(a), end(a));

    ll ans = mx == 1ll ? n : (ll)-1e18;

    for(ll x = 2; x <= mx; x++){
      ll curAns = 0;
      for(ll p = 1; p <= mx; p++){
        ll l = (p - 1) * x, r = min(mx, p * x);
        if(l > mx) break;
        ll needs = preffixSum[r] - preffixSum[l];
        curAns += p * needs - y * max(0ll, needs - cnt[p]);
      }

      ans = max(curAns, ans);
    }

    cout << ans << '\n';
  }

  return 0;
}