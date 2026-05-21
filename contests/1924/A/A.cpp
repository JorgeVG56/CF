/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  int n, k, m; string s; cin >> n >> k >> m >> s;

  vector<vector<int>> lastOccurrance(k, vector<int>(m + 1, -1));
  
  for(int i = m - 1; i >= 0; i--){
    for(int j = 0; j < k; j++){
      lastOccurrance[j][i] = lastOccurrance[j][i + 1];
    }
    lastOccurrance[s[i] - 'a'][i] = i;
  }

  string _s; int idx = 0;
  for(int i = 0; i < n; i++){
    char c = 'a'; int highestIdx = -1;
    for(int j = 0; j < k; j++){
      if(lastOccurrance[j][idx] == -1){
        cout << "No" << '\n';
        cout << _s << char('a' + j);
        for(int _k = i + 1; _k < n; _k++) cout << 'a';
        cout << '\n';
        return;
      } else if(lastOccurrance[j][idx] > highestIdx){
        highestIdx = lastOccurrance[j][idx];
        c = char('a' + j);
      }
    }
    _s += c; idx = highestIdx + 1;
  }

  cout << "Yes" << '\n';
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int tc; cin >> tc;

  for(int _tc = 0; _tc < tc; _tc++) solve();

  return 0;
}