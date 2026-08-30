#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

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
  return vector<int>(begin(p), end(p));
}

vector<int> manacher(string s) {
  string t;
  for(auto c: s) t += string("#") + c;
  auto res = manacher_odd(t + "#");
  return vector<int>(begin(res) + 1, end(res) - 1);
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n; cin >> n;
  string s; cin >> s;

  string t;
  for(auto c: s) t += string("#") + c;
  auto res = manacher_odd(t + "#");

  vector<int> preffix(res.size());
  for(int i = 1; i < res.size(); i++) {
    if(t[i] == '#') preffix[i] = preffix[i - 1];
    else preffix[i] = preffix[i - 1] + t[i] - 'a' + 1;
  }

  int ans = 0; 
  for(int i = 1; i < n; i += 2) {
    while(res[i] >= 0) {
      ans += preffix[i + res[i] - 1] - (i >= res[i] ?preffix[i - res[i]];
      res[i] -= 2;
    }
  }

  return 0;
}