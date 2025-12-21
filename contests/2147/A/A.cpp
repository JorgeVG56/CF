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
    int x, y; cin >> x >> y;

    if(x < y){
      cout << 2 << '\n';
    } else if(y > 1 && y < x - 1){
      cout << 3 << '\n';
    } else{
      cout << -1 << '\n';
    }
  }
  
  return 0;
}