/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  auto query = [&](int i, int x) -> int{
    cout << '?' << ' ' << i << ' ' << x << endl;
    int res; cin >> res;
    return res;
  };

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;

    set<int> idx, st; for(int i = 1; i < n; i++) idx.insert(i), st.insert(i);
    st.insert(n);
    int ans = 0;

    for(int bit = 0; bit < 16; bit++){
      set<int> idx0, idx1, st0, st1;

      for(int i : idx){
        int res = query(i, (1 << bit));
        if(res) idx1.insert(i);
        else idx0.insert(i);
      }

      int zero = 0, one = 0;
      for(int x : st){
        if((x >> bit) & 1) one += 1, st1.insert(x);
        else zero += 1, st0.insert(x);
      }

      if(zero == (int)size(idx0)) ans += (1 << bit), idx = idx1, st = st1;
      else idx = idx0, st = st0;
    }

    cout << '!' << ' ' << ans << endl;
  }

  return 0;
}