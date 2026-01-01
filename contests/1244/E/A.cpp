/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n, k; cin >> n >> k;

  vector<ll> a(n); for(auto & x : a) cin >> x;

  sort(begin(a), end(a));

  vector<ll> preffix(n + 1); for(int i = 0; i < n; i++) preffix[i + 1] = preffix[i] + a[i];
  vector<ll> suffix(n + 1); for(int i = (int)n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + a[i];

  ll ans = (ll)1e18;
  for(int i = 0; i < n; i++){
    ll curK = (i + 1) * a[i] - preffix[i + 1];
    if(curK > k) continue; // All elements >= L | L = a[i]

    auto f = [&](ll mi) -> bool {
      ll pos = upper_bound(begin(a), end(a), mi) - begin(a);
      ll newK = suffix[pos] - (n - pos) * mi;
      return curK + newK <= k;
    };

    ll lo = a[i], hi = a[n - 1];
    while(lo < hi){
      ll mi = (lo + hi) >> 1; // Try this R

      if(f(mi)){
        hi = mi;
      } else{
        lo = mi + 1;
      }
    }

    ans = min(ans, lo - a[i]);
  }

  for(int i = (int)n - 1; i >= 0; i--){
    ll curK = suffix[i] - (n - i) * a[i];
    if(curK > k) continue; // All elements <= R | R = a[i]

    auto f = [&](ll mi) -> bool {
      ll pos = lower_bound(begin(a), end(a), mi) - begin(a);
      ll newK = pos * mi - preffix[pos];
      return curK + newK <= k;
    };

    ll lo = a[0], hi = a[i];
    while(lo < hi){
      ll mi = (lo + hi + 1) >> 1; // Try this L
      
      if(f(mi)){
        lo = mi;
      } else{
        hi = mi - 1;
      }
    }

    ans = min(ans, a[i] - lo);
  }

  cout << ans << '\n';

  return 0;
}