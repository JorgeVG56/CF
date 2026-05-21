#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;

  vector<int> freq(n + 1); for(int & x : a) freq[x]++;

  int ans = 0;
  for(int i = 0; i < n + 1; i++)
    if(freq[i] < i) ans += freq[i];
    else ans += freq[i] - i;

  cout << ans << '\n';

  return 0;
}