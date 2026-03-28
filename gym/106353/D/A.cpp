/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  if((n % 4) == 0){
    cout << (n / 2) + 1 << '\n';
  } else if(n % 2 == 1){
    cout << n / 2 << '\n';
  } else{
    cout << n / 2 + 2 << '\n';
  }

  return 0;
}