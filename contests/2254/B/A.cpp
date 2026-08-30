#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;
    string s; cin >> s;

    int x = 1; for(int i = 1; i < n; i++) x += s[i] != s[i - 1];

    int canReduceOne = 0, canReduceTwo = 0;
    for(int i = 1; i < n - 1; i++){
      canReduceOne |= (s[i] != s[i - 1] && s[i] != s[i + 1]);
      canReduceTwo |= (s[i] != s[i - 1] && s[i] != s[i + 1] && s[i - 1] == s[i + 1]);
    }

    cout << x - canReduceOne - canReduceTwo << '\n';
  }

  return 0;
}