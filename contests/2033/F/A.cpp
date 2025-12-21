/*
  Pura gente del Coach Moy
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mod = (int)(1e9) + 7;
 
signed main(){
  cin.tie(0)->sync_with_stdio(0);
 
  int t; cin >> t;
 
  for(int _t = 0; _t < t; _t++){
    ll n, k; cin >> n >> k;
 
    if(k == 1){ cout << n << '\n'; continue; }
 
    ll a = 1, b = 1, c = 1, cnt = 2;
    while(c % k != 0 && cnt++){ a = b; b = c; c = (a + b) % k; }
 
    cout << n % mod * cnt % mod << '\n';
  }
 
  return 0;
}