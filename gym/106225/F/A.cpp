#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;

    vector<int> a(n); for(int & x : a) cin >> x;

    vector<int> row(n), column(n);
    for(int i = 0; i < n - 1; i++)
      if(a[i] < a[i + 1]) row[i] = row[i + 1] = a[i + 1] - a[i];
      else row[i] = a[i + 1] - 1, row[i + 1] = a[i + 1]; 
    
    for(int i = 0; i < n; i++)
      column[i] = a[i] / row[i];

    cout << max(*max_element(begin(row), end(row)), *max_element(begin(column), end(column))) << '\n';
  }

  return 0;
}