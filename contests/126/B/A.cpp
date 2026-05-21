#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

vector<int> kmp(string s) {
    int n = s.length(); vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;

  vector<int> pi = kmp(s);

  int l = pi[s.size() - 1];
  int maxMiddle = 0; for(int i = 1; i < s.size() - 1; i++) maxMiddle = max(maxMiddle, pi[i]);
  if(l == 0) cout << "Just a legend" << '\n';
  else if(maxMiddle >= l) cout << s.substr(0, l) << '\n';
  else if(pi[l - 1] > 0) cout << s.substr(0, pi[l - 1]) << '\n';
  else cout << "Just a legend" << '\n';

  return 0;
}