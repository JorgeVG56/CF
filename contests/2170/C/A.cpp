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
    ll n, k; cin >> n >> k;

    vector<ll> a(n); for(ll & x : a) cin >> x;
    vector<ll> b(n); for(ll & x : b) cin >> x;

    sort(begin(a), end(a));
    sort(rbegin(b), rend(b));

    int ans = 0, j = 0;
    for(int i = 0; i < n; i++){
      while(j < n && (a[i] * (b[j] + 1) + b[j] > k || b[j] + 1 > k)) j++;
      if(j >= n) break;
      ans++, j++;
    }


    cout << ans << '\n';
  }

  return 0;
}