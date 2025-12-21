/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;
  int remainingTime = 240 - k;

  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(remainingTime < 5 * i) break;
    ans++;
    remainingTime -= 5 * i;
  }

  cout << ans << '\n'; 

  return 0;
}