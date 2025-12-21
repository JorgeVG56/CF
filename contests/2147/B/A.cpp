/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int tc; cin >> tc;

  for(int c = 0; c < tc; c++){
    int n; cin >> n;
    for(int i = n; i > 0; i--) cout << i << ' ';
    cout << n;
    for(int i = 1; i < n; i++) cout << ' ' << i;
    cout << '\n';
  }
  
  return 0;
}