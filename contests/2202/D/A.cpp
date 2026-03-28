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
    int n, k; cin >> n >> k;

    if(k < n || k > 2 * n - 1){
      cout << "No" << '\n';
      continue;
    }

    cout << "Yes" << '\n';
    while(k != 2 * n - 1){
      cout << n << ' ' << n << ' ';
      k--, n--;
    }

    cout << 1 << ' ';
    for(int i = 2; i <= n; i++) cout << i << ' ' << i - 1 << ' ';
    cout << n << '\n';
  }

  return 0;
}