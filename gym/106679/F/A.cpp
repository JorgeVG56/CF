#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define int ll
const ll INF = 4e18;
const ll MOD = 1e9;
const int MAXN = 1e7 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  vector<ll> nxt(MAXN), prev(MAXN, -1);
  nxt[1] = 2, prev[2] = 1;
  for(ll i = 2; i < MAXN; i++) {
    if(prev[i] != -1) nxt[i] = prev[i] * 3ll;
    else nxt[i] = nxt[i - 1] + 1;
    if(nxt[i] < MAXN) prev[nxt[i]] = i;
  }
  
  int n; cin >> n;

  cout << nxt[n] << '\n';
  
  return 0;
} 