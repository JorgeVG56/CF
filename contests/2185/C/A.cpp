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
    sort(begin(a), end(a));

    int mxMEX = 1, curMEX = 1, last = a[0];
    for(int i = 1; i < n; i++){
      if(a[i] == last) continue;
      else if(a[i] == last + 1) mxMEX = max(mxMEX, ++curMEX), last = a[i];
      else curMEX = 1, last = a[i];
    }

    cout << mxMEX << '\n';
  }

  return 0;
}