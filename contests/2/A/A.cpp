/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<pair<string, int>> a(n); for(auto & [s, x] : a) cin >> s >> x;

  map<string, int> mp;
  for(auto & [s, x] : a){
    mp[s] += x;
  }

  int maxScore = -1e9;
  for(auto & [s, x] : mp){
    maxScore = max(maxScore, x);
  }

  map<string, int> mpSecond;
  for(auto & [s, x] : a){
    mpSecond[s] += x;
    if(mpSecond[s] >= maxScore && mp[s] >= maxScore){
      cout << s << '\n';
      break;
    }
  }

  return 0;
}