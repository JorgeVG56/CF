#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

double binPow(double a, int b){
  double ret = 1;
  while(b){
    if(b & 1) ret = ret * a;
    a = a * a;
    b >>= 1;
  }
  return ret;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int m, n; cin >> m >> n;
  
  double ans = 0;
  for(double i = 1; i <= m; i++){
    double prob = binPow(i / m, n) - binPow((i - 1) / m, n);
    ans += i * prob;
  }

  cout << fixed << setprecision(6) << ans << '\n';
  
  return 0;
}