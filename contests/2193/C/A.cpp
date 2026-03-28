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
    int n, q; cin >> n >> q;

    vector<ll> a(n); for(auto & x : a) cin >> x;
    vector<ll> b(n); for(auto & x : b) cin >> x;

    for(int i = n - 1; i >= 0; i--) a[i] = max({a[i], b[i], i == n - 1 ? 0ll : a[i + 1]});
    for(int i = 1; i < n; i++) a[i] += a[i - 1];

    for(int i = 0; i < q; i++){
      int l, r; cin >> l >> r;

      cout << a[r - 1] - (l == 1 ? 0 : a[l - 2]) << ' ';
    }

    cout << '\n';
  }

  return 0;
}