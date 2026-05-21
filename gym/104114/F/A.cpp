/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s, t; cin >> s >> t;

  vector<vector<int>> pos(26);
  for(int i = 0; i < s.size(); i++){
    pos[s[i] - 'a'].push_back(i);
  }

  int idx = 0, loops = 1;
  for(int i = 0; i < t.size(); i++){
    auto idxSearch = lower_bound(begin(pos[t[i] - 'a']), end(pos[t[i] - 'a']), idx);
    if(idxSearch == end(pos[t[i] - 'a'])) loops++, idxSearch = *begin(pos[t[i] - 'a']);
    else idxSearch = *idxSearch;
  }

  cout << loops << '\n';

  return 0;
}