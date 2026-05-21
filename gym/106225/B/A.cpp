#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    ll n, l, r; cin >> n >> l >> r;

    vector<ll> a(n); for(ll & x : a) cin >> x;
    sort(begin(a), end(a));

    vector<ll> preffix(n + 1); for(int i = 1; i <= n; i++) preffix[i] = preffix[i - 1] + a[i - 1];
    vector<ll> suffix(n + 1); for(int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + a[i];

    ll maxProffit = 0;
    for(int i = 0; i < n; i++){
      ll proffitL = (l * i - preffix[i]) + (suffix[i + 1] - l * (n - i - 1));
      ll proffitR = (r * i - preffix[i]) + (suffix[i + 1] - r * (n - i - 1));
      
      ll proffit = min(proffitL, proffitR);
      maxProffit = max(maxProffit, proffit);
    }

    for(int i = 0; i <= n; i++){
      ll proffitL = (l * i - preffix[i]) + (suffix[i] - l * (n - i));
      ll proffitR = (r * i - preffix[i]) + (suffix[i] - r * (n - i));
      
      ll proffit = min(proffitL, proffitR);
      maxProffit = max(maxProffit, proffit);
    }

    cout << maxProffit << '\n';
  }

  return 0;
}