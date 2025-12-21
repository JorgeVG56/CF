/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    int n, k, q; cin >> n >> k >> q;

    vector<pair<int, int>> c1;
    vector<pair<int, int>> c2; 
    
    for(int i = 0; i < q; i++){
      int c, l, r; cin >> c >> l >> r; --l;

      if(c == 1) c1.push_back({l, r});
      else c2.push_back({l, r});
    }

    vector<int> a(n, 0), b(n, 0);

    for(int i = 0; i < (int)size(c2); i++){
      for(int j = c2[i].first; j < c2[i].second; j++){
        b[j] |= 1;
      }
    }

    for(int i = 0; i < (int)size(c1); i++){
      for(int j = c1[i].first; j < c1[i].second; j++){
        b[j] |= 2;
      }
    }

    for(int i = 0; i < n; i++){
      if(b[i] == 3) a[i] = k + 1;
      else if(b[i] == 2) a[i] = k;
      else if(b[i] == 1) a[i] = i % k;
      else a[i] = 1;
    }

    for(int & x : a) cout << x << ' ';

    cout << '\n';
  }

  return 0;
}