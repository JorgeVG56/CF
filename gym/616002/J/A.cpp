/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Tap{
  ll t, a, b;

  bool operator<(Tap tap){
    return t < tap.t;
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll k; cin >> k;

  vector<Tap> a(k); for(auto & tap : a) cin >> tap.t >> tap.a >> tap.b;

  sort(begin(a), end(a));

  ll minFlow = 0, maxFlow = 0, mllemp = 0;

  for(auto & tap : a){
    // cout << tap.t << ' ' << tap.a << ' ' << tap.b << '\n';
    minFlow += tap.a, maxFlow += tap.b, mllemp += tap.t * tap.a;
  }

  ll r; cin >> r;

  for(ll i = 0; i < r; i++){
    ll t, f; cin >> t >> f;

    if(f < minFlow || f > maxFlow){
      cout << "no\n";
    } else{
      ll lowTemp = mllemp;

      ll curFlow = minFlow;

      for(ll j = 0; j < k; j++){
        if(curFlow >= f) break;

        ll newFlow = min(f - curFlow, a[j].b - a[j].a);
        
        curFlow += newFlow;

        lowTemp += newFlow * a[j].t;
      }

      ll highTemp = mllemp;

      curFlow = minFlow;

      for(ll j = k - 1; j >= 0; j--){
        if(curFlow >= f) break;

        ll newFlow = min(f - curFlow, a[j].b - a[j].a);
        
        curFlow += newFlow;

        highTemp += newFlow * a[j].t;
      }

      // cout << lowTemp << ' ' << highTemp << ' ';

      if(lowTemp <= t * f && t * f <= highTemp){
        cout << "yes\n";
      } else{
        cout << "no\n";
      }
    }

  }

  return 0;
}
