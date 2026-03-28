/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> nxt(n + 1, n + 1); for(int i = n - 1; i >= 0; i--) nxt[i] = (s[i] == '(' ? i : nxt[i + 1]);
    vector<int> suffix(n + 1); for(int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + (s[i] == '(');
    
    int ans = -1;
    for(int i = 0; i < n; i++){
      if(s[i] != ')' || nxt[i] > n) continue;
      int aux = nxt[i] - i;
      if(suffix[nxt[i] + 1] >= aux) ans = max(ans, n - 2 * aux);
    }

    cout << ans << '\n';
  }

  return 0;
}