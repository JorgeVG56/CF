/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    ll n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;

    vector<pair<ll, ll>> a(n); 
    for(auto & [x, y] : a) cin >> x;
    for(auto & [x, y] : a) cin >> y;
    sort(begin(a), end(a));

    map<ll, ll> compression; int compressionSize = 0;
    for(int i = 0; i < n; i++) if(compression.count(a[i].first) == 0) compression[a[i].first] = compressionSize++;

    vector<pair<ll, ll>> b(compressionSize, {1e9, 1});
    for(int i = 0; i < n; i++){
      int idx = compression[a[i].first];
      b[idx].first = min(b[idx].first, a[i].second);
      b[idx].second = max(b[idx].second, a[i].second);
    }

    vector<pair<ll, ll>> dp(compressionSize); 
    dp[compressionSize - 1].first = abs(b[compressionSize - 1].first - by);
    dp[compressionSize - 1].second = abs(b[compressionSize - 1].second - by);
    for(int i = compressionSize - 2; i >= 0; i--){
      ll lo = b[i + 1].second - b[i + 1].first + min(abs(b[i].first - b[i + 1].first) + dp[i + 1].second, abs(b[i].first - b[i + 1].second) + dp[i + 1].first);
      ll hi = b[i + 1].second - b[i + 1].first + min(abs(b[i].second - b[i + 1].first) + dp[i + 1].second, abs(b[i].second - b[i + 1].second) + dp[i + 1].first);
      dp[i] = {lo, hi};
    }

    ll ans = bx - ax + (b[0].second - b[0].first) + min(abs(ay - b[0].first) + dp[0].second, abs(ay - b[0].second) + dp[0].first);

    cout << ans << '\n';
  }

  return 0;
}