#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;

  vector<bool> inside(1e6 + 5);
  vector<bool> first(1e6 + 5);

  vector<pair<char, int>> a(n); for(auto & [c, x] : a) cin >> c >> x;

  for(int i = 0; i < n; i++) {
    if(first[a[i].second]) continue;
    first[a[i].second] = true;
    inside[a[i].second] = a[i].first == '-';
  }

  set<int> insideNow; for(int i = 0; i < 1e6 + 1; i++) if(inside[i]) insideNow.insert(i);

  int ans = insideNow.size();
  for(int i = 0; i < n; i++) {
    if(a[i].first == '+') insideNow.insert(a[i].second);
    else insideNow.erase(a[i].second);
    ans = max(ans, (int)insideNow.size());
  }

  cout << ans << '\n';

  return 0;
}