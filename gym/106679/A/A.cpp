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

  int n; cin >> n;
  
  vector<pair<int, int>> level(n + 1);
  for(int i = 0; i < n; i++) {
    int ci, vi; cin >> ci >> vi;
    level[i + 1].first = level[i].first + ci;
    level[i + 1].second = level[i].second + vi;
  }

  int q; cin >> q;

  for(int i = 0; i < q; i++) {
    int l; cin >> l;
    if(level[l].first < level[l].second) cout << "VENDA" << '\n';
    else if(level[l].first > level[l].second) cout << "COMPRA" << '\n';
    else cout << "NEUTRO" << '\n';
  }
  
  return 0;
} 