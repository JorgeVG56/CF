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
  
  int t; cin >> t;
  
  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;
    
    if(n == 1) cout << "1" << '\n';
    else if(n == 2) cout << "10" << '\n';
    else if(n == 3) cout << "101" << '\n';
    else if(n == 4) cout << "1010" << '\n';
    else if(n == 5) cout << "10101" << '\n';
    else if(n % 6 == 0) {  
      cout << 1;
      for(int j = 1; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 1; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 1; j < n / 3; j++)
        cout << 0;
      cout << '\n';
    } else if(n % 6 == 1) {
      cout << 1;
      for(int j = 0; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 1; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 1; j < n / 3; j++)
        cout << 0;
      cout << '\n';
    } else if(n % 6 == 2) {
      cout << 1;
      for(int j = 0; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 1; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 0; j < n / 3; j++)
        cout << 0;
      cout << '\n';
    } else if(n % 6 == 3) {
      cout << 1;
      for(int j = 1; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 2; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 0; j < n / 3; j++)
        cout << 0;
      cout << '\n';
    } else if(n % 6 == 4) {
      cout << 1;
      for(int j = 0; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 0; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 2; j < n / 3; j++)
        cout << 0;
      cout << '\n';
    } else if(n % 6 == 5) {
      cout << 1;
      for(int j = 0; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 0; j < n / 3; j++)
        cout << 0;
      cout << 1;
      for(int j = 1; j < n / 3; j++)
        cout << 0;
      cout << '\n';
    }
  }
  
  return 0;
}
