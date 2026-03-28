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

    vector<int> a(n); for(auto & x : a) cin >> x;
    sort(begin(a), end(a));

    if(a[0] > 0){
      cout << "No" << '\n';
    } else if(a[1] > 0){
      cout << "Yes" << '\n';
    } else if(binary_search(begin(a), end(a), 1)){
      cout << "Yes" << '\n';
    } else{
      cout << "No" << '\n';
    }
  }

  return 0;
}