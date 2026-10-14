#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

vector<int> manacher_odd(string s) {
  int n = s.size();
  s = "$" + s + "^";
  vector<int> p(n + 2);
  int l = 0, r = 1;
  for(int i = 1; i <= n; i++) {
    if(i <= r) p[i] = min(r - i, p[l + (r - i)]);
    while(s[i - p[i]] == s[i + p[i]]) p[i]++;
    if(i + p[i] > r) l = i - p[i], r = i + p[i];
  }
  return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
  string t;
  for(auto c: s) t += string("#") + c;
  auto res = manacher_odd(t + "#");
  return vector<int>(begin(res), end(res));
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    string s; cin >> s;

    auto res = manacher(s);

    int ans = 0;
    for(int i = 0; i < res.size(); i += 2) {
      int l = res[i];
      for(int j = ans + 5; j <= l; j += 4) {
        int d = (j - 1) / 2;
        if(res[i - d] >= j / 2 && res[i + d] >= j / 2) ans = max(ans, j - 1);
      }
    }

    cout << ans << '\n';
  }
  
  return 0;
}
