/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<string> a(n); for(auto & s : a) cin >> s;

  sort(begin(a), end(a), [&](string a, string b) -> bool {
    return a + b < b + a;
  });

  for(auto & s : a) cout << s;

  return 0;
}