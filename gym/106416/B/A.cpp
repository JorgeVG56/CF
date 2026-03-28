#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;

  set<pair<int, int>> st; for(int i = 0; i < n; i++) st.insert({a[i], i});

  int i = 0;
  vector<pair<int, int>> movements;
  while(i < n){
    auto it = begin(st);
    auto [value, pos] = *it;

    st.erase(it);
    if(pos == i) { i++; continue; }
    st.erase({a[i], i});

    movements.push_back({i + 1, pos + 1});

    a[pos] = (a[i] + value + 1) / 2;
    a[i] = (a[i] + value) / 2;
    
    st.insert({a[pos], pos});
    st.insert({a[i], i});
  }

  cout << size(movements) << '\n';
  for(auto & [i, j] : movements) cout << i << ' ' << j << '\n';

  return 0;
}