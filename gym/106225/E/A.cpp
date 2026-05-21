#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;
  string s; cin >> s;
  
  vector<int> preffixA(n + 1); 
  for(int i = 1; i <= n; i++) 
    preffixA[i] = preffixA[i - 1] + (s[i - 1] == '4');
  vector<int> preffixB(n + 1); 
  for(int i = 1; i <= n; i++) 
    preffixB[i] = preffixB[i - 1] + (s[i - 1] == '8');
  
  for(int i = 0; i < q; i++) {
    int l, r, x, y; cin >> l >> r >> x >> y;
    x = abs(x); y = abs(y);

    int a = preffixA[r] - preffixA[l - 1];
    int b = preffixB[r] - preffixB[l - 1];

    if(a + b >= max(x, y) && a + 2 * b >= x + y) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }

  return 0;
}