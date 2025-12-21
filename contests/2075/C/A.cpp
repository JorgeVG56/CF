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
    int n, m; cin >> n >> m;

    vector<int> a(m); for(int & x : a) cin >> x;

    sort(begin(a), end(a));

    ll ans = 0;

    for(int i = 1; i < n; i++){
      ll left = m - (ll)(lower_bound(begin(a), end(a), i) - begin(a));
      ll right = m - (ll)(lower_bound(begin(a), end(a), n - i) - begin(a));
      ans += left * right - min(left, right);
    }

    cout << ans << '\n';
  }

  return 0;
}