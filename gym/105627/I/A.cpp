/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> a;
ll n, m;

ll f(ll n){
  ll ans = 0;

  for(ll i = 0; i < (ll)a.size(); i++){
    ll curH = (a[i] + n) % (2 * m);
    if(curH > m){
      curH = 2 * m - curH;
    }
    ans += curH;
  }

  return ans;
}

ll ternary_search(ll l, ll r){
  while(r - l > 2){
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;

    ll f1 = f(m1);
    ll f2 = f(m2);

    if(f1 < f2){
      l = m1;
    } else{
      r = m2;
    }
  }

  return max({f(l), f(l + 1), f(r)});
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> n >> m;

  a.assign(n, 0);

  for(ll i = 0; i < n; i++){
    ll p; cin >> p;
    char d; cin >> d;

    if(d == 'U') a[i] = p;
    else a[i] = (2 * m - p) % (2 * m);
  }

  cout << ternary_search(0, 2 * m);

  return 0;
}