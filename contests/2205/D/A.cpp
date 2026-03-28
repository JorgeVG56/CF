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
    int n; cin >> n;

    vector<ll> a(n); for(auto & x : a) cin >> x;

    
    vector<pair<int, int>> b(n);
    for(int i = 0; i < n; i++) b[i] = {a[i], i};
    
    sort(rbegin(b), rend(b));

    int l = 0, r = n - 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
      if(b[i].second < l || b[i].second > r) continue;
      if(b[i].second - l >= r - b[i].second){
        ans += r - b[i].second;
        r = b[i].second - 1;
      } else{
        ans += b[i].second - l;
        l = b[i].second + 1;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}