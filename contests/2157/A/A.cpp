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

    map<int, int> cnt;
    for(int & x : a) cnt[x]++;

    int ans = 0;
    for(auto & [key, value] : cnt){
      if(value >= key) ans += value - key;
      else ans += value;
    }

    cout << ans << '\n';
  }

  return 0;
}