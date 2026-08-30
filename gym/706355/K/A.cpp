#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n; 
  
  string s; cin >> s;

  int cnt = 0;
  for(int i = 0; i < n - 10; i++) cnt += (s[i] == '8');

  cout << (cnt > (n - 11) / 2 ? "YES" : "NO") << '\n';

  return 0;
}