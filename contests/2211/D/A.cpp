/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int mod = 1e9 + 7;

vector<int> fact(1e6);
vector<int> invFact(1e6);

int modPow(int a, int b){
  int r = 1;
  while(b){
    if(b & 1) r = r * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}

int comb(int n, int k){
  return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  fact[0] = 1;
  for(int i = 1; i < 1e6; i++) fact[i] = fact[i - 1] * i % mod;
  invFact[1e6 - 1] = modPow(fact[1e6 - 1], mod - 2);
  for(int i = 1e6 - 2; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % mod;

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;
    vector<int> b(n); for(int & x : b) cin >> x;

    vector<int> cnt(30, -1);
    for(int i = n - 1; i >= 0; i--) {
      int sub = 0;
      for(int bit = 0; bit < 30; bit++) {
        if(cnt[bit] <= i + 1) continue;
        int add = (1 << bit) % mod * comb(cnt[bit], i + 1) % mod;
        sub = (sub + add) % mod;
      }

      b[i] = (b[i] - sub + mod) % mod;
      for(int bit = 0; bit < 30; bit++){
        if((b[i] >> bit) & 1){
          cnt[bit] = i + 1;
        }
      }
    }

    vector<int> a(n);
    for(int bit = 0; bit < 30; bit++)
      for(int i = 0; i < cnt[bit]; i++) 
        a[i] |= (1 << bit);

    for(int x : a) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}