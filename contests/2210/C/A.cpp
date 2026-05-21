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

    vector<int> a(n); for(int & x : a) cin >> x;
    vector<pair<int, int>> b(n); for(auto & x : b) cin >> x.first;
    for(int i = 0; i < n; i++) b[i].second = i;
    sort(rbegin(b), rend(b));

    int answer = 0;

    for(int j = 0; j < n; j++){
      int i = b[j].second;
      int l = (i == 0 ? 1 : __gcd(a[i], a[i - 1]));
      int r = (i == n - 1 ? 1 : __gcd(a[i], a[i + 1]));

      int k = l * r / __gcd(l, r);

      for(int p = 1000; p > 0; p--){
        if(k * p == a[i] || k * p > b[j].first) continue;
        int nl = (i == 0 ? 1 : __gcd(k * p, a[i - 1]));
        int nr = (i == n - 1 ? 1 : __gcd(k * p, a[i + 1]));
        if(nl == l && nr == r) { answer++, a[i] = k * p; break; }
      }
    }

    cout << answer << '\n';
  }

  return 0;
}