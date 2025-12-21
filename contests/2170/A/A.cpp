/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    int n; cin >> n;

    vector<vector<int>> a(n + 2, vector<int>(n + 2));

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        a[i][j] = (i - 1) * n + j;
      }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        ans = max(ans, a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1]);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}