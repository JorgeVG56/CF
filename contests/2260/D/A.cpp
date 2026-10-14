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
  
  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;
    string s; cin >> s;

    vector<pair<char, int>> runs;
    int curRun = 1;
    for(int i = 1; i <= n; i++) {
      if(i < n && s[i] == s[i - 1]) curRun++;
      else {
        runs.push_back({s[i - 1], curRun});
        curRun = 1;
      }
    }

    bool possible = runs[0].first != '0';
    int ans = 1, cur = 0;
    for(int i = 0; i < runs.size(); i++) {
      if(runs[i].first == '0') {
        possible &= runs[i].second == 1;
        ans = max(ans, abs(cur));
        cur = 0;
      } else if(runs[i].first == '+') {
        if(cur < 0) {
          ans = max(ans, (abs(cur) + 1));
          cur = 1;
        } else if(i < runs.size() - 1 && runs[i].second == 2){
          cur = 1;
          ans = max(ans, 2ll);
          continue;
        }
        cur = 1;
        if(runs[i].second & 1) continue;
        if(i == runs.size() - 1) continue;
        if(runs[i].second == 2) cur++;
        else ans = max(ans, 2ll);
      } else {
        if(cur > 0) {
          ans = max(ans, (abs(cur) + 1));
          cur = -1;
        } else if(i < runs.size() - 1 && runs[i].second == 2){
          cur = -1;
          ans = max(ans, 2ll);
          continue;
        }
        cur = -1;
        if(runs[i].second & 1) continue;
        if(i == runs.size() - 1) continue;
        if(runs[i].second == 2) cur--;
        else ans = max(ans, 2ll);
      }
    }
    
    if(possible) {
      cout << ans << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  
  return 0;
} 