/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    int n; cin >> n;

    vector<int> a(n); for(int & x : a) cin >> x;

    int cntZero = 0, sum = 0; for(int & x : a) cntZero += (x == 0), sum += x;

    int ans = min(n - cntZero, sum - n + 1);

    cout << ans << '\n';
  }

  return 0;
}