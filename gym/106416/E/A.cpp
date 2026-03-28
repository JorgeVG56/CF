#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  int lo = 1, hi = 1000;

  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    char c; cin >> c;

    if(c == 'A'){
      int newHi = (a + b + 1) / 2 - 1;
      if(newHi < lo){
        cout << '*' << '\n';
        return 0;
      }
      hi = min(hi, newHi);
    } else if(c == 'B'){
      int newLo = (a + b) / 2 + 1;
      if(newLo > hi){
        cout << '*' << '\n';
        return 0;
      }
      lo = max(lo, newLo);
    } else{
      if((a + b) & 1){
        cout << '*' << '\n';
        return 0;
      }
      int mustBe = (a + b) >> 1;
      if(mustBe < lo || mustBe > hi){
        cout << '*' << '\n';
        return 0;
      }
      lo = hi = mustBe;
    }
  }

  cout  << lo << ' ' << hi << '\n';

  return 0;
}