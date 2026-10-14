#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    vector<string> grid(5);
    for(auto & row : grid) cin >> row;

    bool winA = false, winB = false;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(grid[i][j] == grid[i + 1][j + 1] && grid[i][j] == grid[i + 2][j + 2]) {
          if(grid[i][j] == 'A') winA = true;
          else winB = true;
        }
      }
    }

    for(int i = 0; i < 3; i++) {
      for(int j = 2; j < 5; j++) {
        if(grid[i][j] == grid[i + 1][j - 1] && grid[i][j] == grid[i + 2][j - 2]) {
          if(grid[i][j] == 'A') winA = true;
          else winB = true;
        }
      }
    }

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 5; j++) {
        if(grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j]) {
          if(grid[i][j] == 'A') winA = true;
          else winB = true;
        }
      }
    }

    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 3; j++) {
        if(grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2]) {
          if(grid[i][j] == 'A') winA = true;
          else winB = true;
        }
      }
    }

    if(winA && !winB) cout << "A wins" << '\n';
    else if(!winA && winB) cout << "B wins" << '\n';
    else cout << "draw" << '\n';
  }

  return 0;
}