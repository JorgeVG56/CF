/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  int curY = 0;

  for(int i = 0; i < n; i++){
    int t; cin >> t;
    string dir; cin >> dir;
    if(curY == 0 && dir != "South"){ cout << "NO\n"; return 0; }
    if(curY == 20000 && dir != "North"){ cout << "NO\n"; return 0; }
    if(dir == "West" || dir == "East") continue;
    if(dir == "South"){ if(curY + t > 20000){ cout << "NO\n"; return 0; } else { curY += t; } }
    if(dir == "North"){ if(curY - t < 0){ cout << "NO\n"; return 0; } else { curY -= t; } }
  }

  if(curY == 0) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}