/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<int> s(n); for(int & _s : s) cin >> _s;

  set<pair<int, int>> st; for(int i = 0; i < n; i++) st.insert({s[i], i});

  for(int i = 0; i < n; i++){
    auto [val, idx] = *st.rbegin(); st.erase({val, idx});
    if(idx > 0 && s[idx - 1] < val){
      int valLeft = s[idx - 1]; st.erase({valLeft, idx - 1});
      s[idx - 1] = max(valLeft, val - m); st.insert({s[idx - 1], idx - 1});
    }
    if(idx < n - 1 && s[idx + 1] < val){
      int valRight = s[idx + 1]; st.erase({valRight, idx + 1});
      s[idx + 1] = max(valRight, val - m); st.insert({s[idx + 1], idx + 1});
    }
  }

  for(int i = 0; i < n; i++) cout << s[i] << ' ';
  cout << '\n';

  return 0;
}