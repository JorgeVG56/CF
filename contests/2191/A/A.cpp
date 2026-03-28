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

    vector<int> a(n); for(auto & x : a) cin >> x;
    vector<pair<int, int>> b(n); for(int i = 0; i < n; i++) b[i] = {a[i], i};
    sort(begin(b), end(b));

    bool fl = 1;
    for(int i = 1; i < n; i++){
      fl &= (b[i].second ^ b[i - 1].second) & 1;
    }

    cout << (fl ? "Yes" : "No") << '\n';
  }

  return 0;
}