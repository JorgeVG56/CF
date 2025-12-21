/*
  Pura gente del Coach Moy

  
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  vi color(n), order(n), pos(n);

  for(int i = 0; i < n; i++){
    int ni, ci; cin >> ni >> ci;

    pos[ni - 1] = i;
    order[i] = ni - 1;
    color[ni - 1] = ci;
  }

  for(int i = 0; i < n; i++){
    if(order[i] == i) continue;
    else if(color[i] == color[order[i]]){
      pos[order[i]] = pos[i]; 
      swap(order[i], order[pos[i]]);
    } else{
      cout << 'N';
      return 0;
    }
  }

  cout << 'Y';

  return 0;
}
