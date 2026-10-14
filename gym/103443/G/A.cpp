#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 998244353;
const int MAXN = 1e6 + 5;
const int dx [] = {0, 1, 0, -1, 0};
const int dy [] = {1, 0, -1, 0, 0};

void solve() {
  int n, m; cin >> n >> m;

  vector<vector<int>> a(m, vector<int>(n));
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int sI, sJ; cin >> sI >> sJ;

  int lcm = 1;
  vector<vector<vector<pair<int, int>>>> b(m, vector<vector<pair<int, int>>>(n));

  int g; cin >> g;
  for(int i = 0; i < g; i++) {
    int k; cin >> k;
    lcm = lcm * k / __gcd(lcm, k);
    for(int j = 0; j < k; j++) {
      int x, y; cin >> x >> y;
      b[y][x].push_back({j, k});
    }
  }

  // cout << lcm << '\n';

  vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(lcm))); vis[sJ][sI][0] = true;
  queue<array<ll, 3>> q; q.push({sJ, sI, 0});
  while(!q.empty()) {
    auto [x, y, t] = q.front(); q.pop();
    // cout << x << ' ' << y << ' ' << t << '\n';
    if(a[x][y] == 0) {
      cout << t << '\n';
      return;
    }

    for(int i = 0; i < 5; i++) {
      int nX = x + dx[i], nY = y + dy[i];
      if(nX < 0 || nX >= m) continue;
      if(nY < 0 || nY >= n) continue;
      if(a[nX][nY] > a[x][y]) continue;
      bool fl = true;
      for(auto & [gt, gp] : b[nX][nY]) {
        if(t % gp == gt || (t + 1) % gp == gt) fl = false;
      }
      if(!fl) continue;
      if(vis[nX][nY][(t + 1) % lcm]) continue;
      vis[nX][nY][(t + 1) % lcm] = true;
      q.push({nX, nY, t + 1});
    }
  }

  cout << -1 << '\n';
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;
  while(t--) solve();

  return 0;
}
