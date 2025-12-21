#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMax(ll x){
  if(!x) return 9;

  ll res = x, a = 1;

  while(a <= x){
    ll b = 9 - (x % (a * 10)) / a;

    res = max(res, x + b * a);

    a *= 10;
  }

  return res;
}

ll getMin(ll x){
  ll res = x, a = 1;

  while(a * 10 <= x){
    ll b = (x % (a * 10)) / a;

    res = min(res, x - b * a);

    a *= 10;
  }

  ll b = (x % (a * 10)) / a;

  res = min(res, x - (b - 1) * a);

  return res;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<ll> a(n); for(auto & x : a) cin >> x;

  bool fl = false;

  for(int i = 0; i < n; i++){
    ll x1 = getMin(a[i]), x2 = getMax(a[i]);

    if(i > 0 && a[i - 1] > x1){
      fl = true;
      a[i] = x1;
      break;
    }

    if(i < n - 1 && x2 > a[i + 1]){
      fl = true;
      a[i] = x2;
      break;
    }
  }
  
  if(!fl){
    cout << "impossible";
  } else{
    for(auto & x : a) cout << x << ' ';
  }

  return 0;
}
