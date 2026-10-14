#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define int ll
const ll INF = 4e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n, m; cin >> n >> m;
  
  vector<ll> a(n); for(int & x : a) cin >> x;

  vector<vector<int>> ranges(n);
  for(int i = 0; i < m; i++) {
    int l, r; cin >> l >> r; --l, --r;
    ranges[l].push_back(r);
  }

  vector<int> finalRange(n + 1, -1);
  for(int i = 0; i < n; i++) {
    if(ranges[i].empty()) continue;
    sort(begin(ranges[i]), end(ranges[i]));
    finalRange[i] = ranges[i][0];
    for(int j = 1; j < ranges[i].size(); j++) {
      if(ranges[i][j - 1] + 1 > ranges[i][j]) continue;
      ranges[ranges[i][j - 1] + 1].push_back(ranges[i][j]);
    }
  }

  vector<int> sub(n); 
  int cur = 0;

  for(int i = 0; i < n; i++) {
    cur -= sub[i];
    if((a[i] + cur) % 2 == 0) continue;
    if(finalRange[i] == -1) {
      cout << "NO" << '\n';
      return 0;
    }
    cur += 1;
    if(finalRange[i] + 1 < n) sub[finalRange[i] + 1] += 1;
  }

  cout << "YES" << '\n';
  
  return 0;
} 