#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;
const ll MOD = 998244353;

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

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> pi = kmp(s);
    vector<int> a; 
    for(int i = 0; i < n; i++) 
      if(pi[i] == 0) 
        a.push_back(i + 1);

    vector<ll> dp(k + 1); dp[0] = 1;
    for(int i = 1; i <= k; i++)
      for(int d : a) 
        if(i - d >= 0) 
          dp[i] = (dp[i] + dp[i - d]) % MOD;

    cout << dp[k] << '\n';
  }

  return 0;
}