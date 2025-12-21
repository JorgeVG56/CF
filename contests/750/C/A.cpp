/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<pair<int, int>> a(n); for(auto & p : a) cin >> p.first >> p.second;

  vector<int> preffix(n + 1); for(int i = 1; i <= n; i++) preffix[i] = preffix[i - 1] + a[i - 1].first;
  // Para el concurso i si de categoria:
  //  1 -> x + preffix[i] >= 1900
  //  2 -> x + preffix[i] < 1900
  // Reorganizando
  // 1900 - preffix[i] <= x <= 1899 - preffix[i]
  // Para todo i
  // Entonces encontrar el maximo 1900 - preffix[i] (Div 1)
  // Entonces encontrar el minimo 1899 - preffix[i] (Div 2)

  // Pendejo yo, x es el valor inicial xd

  int mx = -1e9, mn = 1e9;

  for(int i = 0; i < n; i++){
    if(a[i].second == 1) mx = max(mx, 1900 - preffix[i]);
    else mn = min(mn, 1899 - preffix[i]);
  }

  if(mn < mx){
    cout << "Impossible\n";
  } else if(mn == 1e9){
    cout << "Infinity\n";
  } else{
    cout << mn + preffix[n] << '\n';
  }

  return 0;
}