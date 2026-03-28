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

    vector<int> p(n); for(int & x : p) cin >> x;
    vector<int> a(n); for(int & x : a) cin >> x;

    vector<int> pos(n + 1); for(int i = 0; i < n; i++) pos[p[i]] = i;

    bool fl = true;
    int lst = -1;
    for(int i = 0; i < n; i++){
      if(lst > pos[a[i]]) fl = 0;
      lst = pos[a[i]];
    }

    cout << (fl ? "Yes" : "No") << '\n';
  }

  return 0;
}