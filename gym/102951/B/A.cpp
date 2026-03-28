/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, x; cin >> n >> x;

  vector<int> a(n); for(int & x : a) cin >> x;

  sort(begin(a), end(a));

  for(int i = 0; i < n; i++){
    if(x < a[i]){
      cout << i << '\n';
      return 0;
    }

    x -= a[i];
  }

  cout << n << '\n';

  return 0;
}