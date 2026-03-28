/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n; 

    vector<int> a(n); for(int & x : a) cin >> x;

    vector<int> b(n);
    bool fl = true;
    if(a[n - 1] == 0) b[n - 1] = 1;
    else if(a[n - 1] <= n - 1) b[n - 1] = 0;
    else fl = false;

    int lo = b[n - 1];
    for(int i = n - 2; i >= 0; i--){
      if(a[i] < a[i + 1]) fl = false;
      else if(a[i] == a[i + 1]) b[i] = ++lo;
      else if(a[i] == a[i + 1] + 1) b[i] = b[i + 1];
      else if(a[i] == a[i + 1] + 2) b[i] = 1e9;
      else fl = false;
    }

    if(fl){
      cout << "YES" << '\n';
      for(int & x : b) cout << x << ' ';
      cout << '\n';
    } else{
      cout << "NO" << '\n';
    }
  }

  return 0;
}