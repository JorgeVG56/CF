/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll squaresInCircle(double r){
  ll squares = 0;

  for(double i = 1; i < r; i++){
    ll square = (ll)sqrt(r * r - i * i);
    squares += square;
  }

  return 4 * squares;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  double l = 0, r = 1e6;

  while(r - l >= 1e-6){
    double m = (r + l) / 2;

    ll squares = squaresInCircle(m);
    if(squares > n){
      r = m;
    } else{
      l = m;
    }
  }

  cout << fixed << setprecision(8) << l << '\n';

  return 0;
}