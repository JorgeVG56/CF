/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;

  if(n == 1 || n == 3){
    cout << 1;
  } else{
    n--;

    int bitCnt = __builtin_popcountll(n);

    if(bitCnt > 2){
      cout << "impossible" << '\n';
    } else if(bitCnt == 1){
      cout << n / 2 + 1 << '\n';
    } else{
      cout << (n & -n) + 1 << '\n';
    }
  }

  return 0;
}