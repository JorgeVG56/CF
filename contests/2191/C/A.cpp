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
    string s; cin >> s;

    vector<int> z, o; 
    for(int i = 0; i < n; i++){
      if(s[i] == '0') z.push_back(i);
      else o.push_back(i);
    }

    vector<int> b;
    for(auto & x : o) if(x < (int)size(z)) b.push_back(x);
    for(auto & x : z) if(x >= (int)size(z)) b.push_back(x);

    if(z.empty() || o.empty() || b.empty()){
      cout << "Bob" << '\n';
    } else{
      cout << "Alice" << '\n';
      cout << size(b) << '\n';
      for(auto & x : b) cout << x + 1 << ' ';
      cout << '\n';
    }
  }

  return 0;
}