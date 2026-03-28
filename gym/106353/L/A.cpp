/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  map<string, vector<int>> mp;
  for(int i = 0; i < n; i++){
    for(int j = 1; j <= 10; j++){
      string s; cin >> s;
      if(mp.count(s) == 0){
        vector<int> a(11);
        mp[s] = a;
      }
      mp[s][0]++;
      mp[s][j]++;
    }
  }

  for(int i = 0; i <= 10; i++){
    int mx = 0;
    for(auto [s, a] : mp) mx = max(mx, a[i]);
    vector<string> removing;
    for(auto [s, a] : mp) if(a[i] < mx) removing.push_back(s);
    for(auto s : removing) mp.erase(s);
  }

  if(mp.size() > 1){
    cout << "tie" << '\n';
  } else{
    cout << mp.begin() -> first << '\n';
  }

  return 0;
}