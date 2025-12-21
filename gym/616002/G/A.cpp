/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(auto & x : a) cin >> x;

  int ans = 0, b = 0, curAns = 0;

  for(int i = 0; i < n; i++){
    if(a[i] == 3) ans += curAns;
    else if(a[i] == 2) curAns += b;
    else if(a[i] == 1) b++;
  }

  cout << ans;

  return 0;
}