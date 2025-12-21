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
    int n, b; cin >> n >> b;

    vector<ll> x(n); for(auto & d : x) cin >> d;

    ll sum = accumulate(begin(x), end(x), 0ll) % (b - 1);
    if(sum){ cout << "NO" << '\n'; continue; }

    vector<ll> y;
    ll cur = 0; for(auto & d : x) { cur = cur * b + d; y.push_back(cur / (b - 1)); cur -= (b - 1) * y.back(); }

    cout << "YES" << '\n';
    cout << (n + 2) << '\n';
    cout << 1 << ' ' << 0 << ' '; for(auto & d : y) cout << d << ' '; cout << '\n';
    cout << 1 << ' '; for(auto & d : y) cout << d << ' '; cout << 0 << '\n';
  }

  return 0;
}