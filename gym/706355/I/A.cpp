#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n; 
  string s; cin >> s;

  vector<char> a(10); for(int i = 1; i < 10; i++) cin >> a[i];

  int idx = 0;

  while(idx < n && s[idx] >= a[s[idx] - '0']) idx++;

  while(idx < n && s[idx] <= a[s[idx] - '0']) s[idx] = a[s[idx] - '0'], ++idx;

  cout << s << '\n';

  return 0;
}