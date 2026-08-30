#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> color(n); for(int & x : color) cin >> x;
  vector<int> cnt(155); for(int & x : color) cnt[x]++;

  cout << *max_element(begin(cnt), end(cnt)) << '\n';

  return 0;
}