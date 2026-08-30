#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;
  vector<int> b(n);

  stack<pair<int, int>> st; st.push({n - 1, 0});
  for(int i = n - 2; i >= 0; i--){
    int time = 1;
    while(!st.empty() && a[i] > a[st.top().first]){
      b[st.top().first] = time++;
      time = max(time, st.top().second + 1);
      st.pop();
    }
    st.push({i, time});
  }

  cout << *max_element(begin(b), end(b)) << '\n';

  return 0;
}