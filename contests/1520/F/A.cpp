/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int query(int l, int r){
  cout << '?' << ' ' << l << ' ' << r << endl;
  int x; cin >> x;
  return x;
}

void answer(int x){
  cout << '!' << ' ' << x << '\n';
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, t; cin >> n >> t;

  for(int _t = 0; _t < t; _t++){
    int k; cin >> k;

    int lo = 1, hi = n;

    while(lo < hi){
      int mi = (lo + hi) >> 1;
      
      int zeroes = (mi - lo + 1) - query(lo, mi);

      if(zeroes < k){
        k -= zeroes;
        lo = mi + 1;
      } else{
        hi = mi;
      }
    }

    answer(lo);
  }

  return 0;
}