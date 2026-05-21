#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s1, s2; cin >> s1 >> s2;

  int n = s1.size();

  int desired = 0; for(int i = 0; i < n; i++) desired += (s1[i] == '+' ? 1 : -1);

  double good = 0, total = 0;
  for(int mask = 0; mask < (1 << n); mask++){
    int end = 0;
    for(int i = 0; i < n; i++){
      if(s2[i] == '?') end += (((mask >> i) & 1) ? 1 : -1);
      else end += (s2[i] == '+' ? 1 : -1);
    }
    if(end == desired) ++good;
    ++total;
  }

  cout << fixed << setprecision(9) << good / total << '\n';

  return 0;
}