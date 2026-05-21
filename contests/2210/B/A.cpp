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

    vector<int> marked(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
      if(marked[i]) break;
      if(a[i] - 1 <= i) ans++, marked[a[i] - 1] = 1;
    }

    cout << ans << '\n';
  }

  return 0;
}