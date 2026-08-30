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
    string a, b; cin >> a >> b;

    vector<int> A[2], B[2];
    for(int i = 0; i < n; i++) {
      if(a[i] == '1') A[i & 1].push_back(i);
      if(b[i] == '1') B[i & 1].push_back(i);
    }

    if(A[0].size() != B[0].size() || A[1].size() != B[1].size()) cout << -1 << '\n';
    else {
      ll cnt = 0;
      for(int i = 0; i < 2; i++){
        for(int j = 0; j < A[i].size(); j++){
          cnt += abs(A[i][j] - B[i][j]) / 2;
        }
      }

      cout << cnt << '\n';
    }
  }

  return 0;
}