/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m, q; cin >> n >> m >> q;
  
  vector<int> positions(m); for(int & position : positions) cin >> position;
  vector<int> values(m); for(int & value : values) cin >> value;

  map<int, int> mp; for(int i = 0; i < m; i++) mp.insert(positions[i], values[i]);

  for(int _q = 0; _q < q; _q++){
    int type; cin >> type;
    if(type == 1){
      int x, v; cin >> x >> v;
    } else{

    }
  }

  return 0;
}