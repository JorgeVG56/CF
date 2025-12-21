/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll r, n, m;

ll factorial[5000];
ll invFactorial[5000];

pair<ll, ll> egcd(ll a, ll b){
  if(b == 0) return {1, 0};
  pair<ll, ll> p = egcd(b, a % b);
  return {p.second, p.first - a / b * p.second};
}

ll modInv(ll x){
  return egcd(x, m).first;
}

void calc(){
  factorial[0] = invFactorial[0] = 1;
  for(ll i = 1; i < 5000; i++){
    factorial[i] = (factorial[i - 1] * i) % m;
    invFactorial[i] = modInv(factorial[i]);
  }
}

ll comb(ll a, ll b){
  return (factorial[a]) * (invFactorial[b] * invFactorial[a - b] % m) % m;
}

ll catalan(ll n){
  return (comb(2 * n, n) - comb(2 * n, n - 1)) % m;
}

ll f(ll x){
  if(x == 0) return 1;
  if(x == 1) return n - r;
  return (factorial[x] * comb(n - r, x) % m + f(x - 1)) % m;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> r >> n >> m;

  calc();

  ll cat = catalan(n - r);
  cout << cat << '\n';

  ll answer = catalan(n - r) * f(r - 1) % m;

  cout << answer << '\n';

  return 0;
}