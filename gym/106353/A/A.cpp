/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> plushes; 

  for(int i = 0; i < n; i++) {
    int plush; cin >> plush;
    plushes.push_back(plush);
  }

  vector<pair<int, int>> movements;  
  auto xchg = [&] (int i, int j) -> void {
    movements.push_back({i + 1, j + 1});

    vector<int> moving = {plushes[i], plushes[i + 1], plushes[i + 2]};
    plushes.erase(begin(plushes) + i, begin(plushes) + i + 3);
    plushes.insert(begin(plushes) + j, begin(moving), end(moving));
  };

  for(int i = 0; i < n - 2; i++){
    if(plushes[i] == i + 1) continue;

    int pos = -1; 
    for(int j = i + 1; j < n; j++) if(plushes[j] == i + 1) pos = j;

    int before = pos - i - 1, after = n - pos - 1;

    if(after >= 2) { // DONE
      xchg(pos, i);
    } else if(after == 1){
      if(before >= 2) { // DONE
        xchg(pos - 1, pos - 2);
        xchg(pos - 1, i);
      } else { // DONE
        xchg(i - 2, i - 2);
        xchg(i - 2, i);
        xchg(i - 2, i);

        xchg(i - 2, i - 1);
        xchg(i - 2, i - 1);
        xchg(i, i - 2);
      }
    } else{
      if(before >= 3){ // DONE
        xchg(pos - 2, pos - 3);
        xchg(pos - 2, pos - 3);
        xchg(pos - 2, i);
      } else if(before == 2){ // DONE
        xchg(i - 2, i - 1);
        xchg(i - 2, i - 1);
        xchg(i, i - 2);
      } else {
        xchg(i - 3, i - 2);
        xchg(i - 1, i - 3);
        xchg(i - 1, i - 3);
        xchg(i - 1, i - 3);
      }
    }
  }

  cout << movements.size() << '\n';
  for(auto [i, j] : movements) cout << i << ' ' << j << '\n';

  return 0;
}