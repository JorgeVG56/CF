#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const ll INF = 1e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n; cin >> n;

  vector<ll> cards(n);
  map<int, int> cardCount;
  for(int i = 0; i < n; i++) {
    int a, c; cin >> a >> c;
    cards[i] = a;
    cardCount[a] = c;
  }

  for(int i = n - 1; i >= 0; i--) {
    ll x = cards[i];
    if(cardCount[x] == 0) continue;

    int highestBit = 0;
    for(int j = 0; j < 32; j++) 
      if((x >> j) & 1) highestBit = j;
    ll y = (1ll << (highestBit + 1)) - x - 1ll;
    if(cardCount[x] > cardCount[y]) {
      cout << "Ana" << '\n';
      return 0;
    } else {
      cardCount[y] -= cardCount[x];
    }
  }

  cout << "Beto" << '\n';

  return 0;
}
