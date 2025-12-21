/*
  Pura gente del Coach Moy

  
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<string> a(n); for(string & s : a) cin >> s;

  sort(begin(a), end(a), [&](string & a, string & b) -> bool{
    return a.size() < b.size();
  });

  set<string> st;
  int ans = 0;

  for(string & s : a){
    if((int)s.size() == 1 || (st.count(s.substr(0, (int) s.size() - 1)) && st.count(s.substr(1)))){
      st.insert(s);
      ans = (int) size(s);
    }
  }

  cout << ans << '\n';
  
  return 0;
}