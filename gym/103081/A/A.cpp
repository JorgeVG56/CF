/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  map<string, pair<int, int>> mp;

  string trash; getline(cin, trash);

  for(int i = 0; i < n * 3; i++){
    string s;
    getline(cin, s);

    if(mp.count(s) == 0){
      mp[s] = {1, i};
    } else{
      mp[s].first++;
      mp[s].second = i;
    }
  }

  vector<pair<pair<int, int>, string>> v;  
  for(auto & [key, value] : mp){
    v.push_back({value, key});
  }

  sort(rbegin(v), rend(v));

  for(int i = 0; i < min((int)v.size(), k); i++){
    cout << v[i].second << '\n';
  }
  
  return 0;
}