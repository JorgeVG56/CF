/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    int n; cin >> n;

    vector<ll> a(n); for(auto & x : a) cin >> x;

    ll maxN = (ll) 1e9 * n;

    vector<ll> b(n); for(int i = 0; i < n; i++) b[(i + a[i] + maxN) % n]++;

    if(*max_element(begin(b), end(b)) != 1) cout << "NO" << '\n';
    else cout << "YES" << '\n';
  }

  return 0;
}