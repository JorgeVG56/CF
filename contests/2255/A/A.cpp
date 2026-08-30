#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int A = 0, B = 0;
    for(int i = 0; i < (n << 1); i++){
      if(s[i] == '0') continue;
      
      if(s[(i + 1) % (n << 1)] == '0') A += (~i & 1), B += (i & 1);
      else B += (~i & 1), A += (i & 1);
    }

    cout << A << ' ' << B << '\n';
  }

  return 0;
}