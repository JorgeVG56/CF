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

    int l = 0;
    for(int i = 0; i < n; i++){
      if(a[i] == n - i) continue;
      l = i;
      break;
    }

    int r = 0;
    for(int i = 0; i < n; i++){
      if(a[i] != n - l) continue;
      r = i;
      break;
    }

    reverse(begin(a) + l, begin(a) + r + 1);

    for(auto & x : a) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}