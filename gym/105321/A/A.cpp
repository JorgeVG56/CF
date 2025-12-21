#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int checkWin(vector<int> & grid){
  for(int i = 0; i < 3; i++)
    if(grid[i] == grid[i + 3] && grid[i + 3] == grid[i + 6] && grid[i])
      return grid[i];

  for(int i = 0; i < 3; i++)
    if(grid[i * 3] == grid[i * 3 + 1] && grid[i * 3 + 1] == grid[i * 3 + 2] && grid[i * 3])
      return grid[i * 3];

  if(grid[0] == grid[4] && grid[4] == grid[8] && grid[0])
    return grid[0];
  
  if(grid[2] == grid[4] && grid[4] == grid[6] && grid[2])
    return grid[2];  

  return 0;
}

int calc(bool p, vector<vector<int>> restrictions, vector<int> & grid){
  int win = checkWin(grid);
  if(win) return win;

  if(p){
    bool hasWin = false, hasTie = false, hasLose = false;
    for(int i = 0; i < 9; i++){
      if(grid[i]) continue;

      bool fl = true;
      for(int j = 0; j < 9; j++){
        if(restrictions[j][i] && !grid[j]){
          fl = false;
        }
      }

      if(fl){
        grid[i] = 1;
        int ans = calc(!p, restrictions, grid);
        if(ans == 0){
          hasTie = true;
        } else if(ans == 1){
          hasWin = true;
        } else{
          hasLose = true;
        }
        grid[i] = 0;
      }
    }  

    if(hasWin) return 1;
    else if(hasTie) return 0;
    else if(hasLose) return 2;
    else return 0;
  } else{
    bool hasWin = false, hasTie = false, hasLose = false;
    for(int i = 0; i < 9; i++){
        if(grid[i]) continue;

      bool fl = true;
      for(int j = 0; j < 9; j++){
        if(restrictions[j][i] && !grid[j]){
          fl = false;
        }
      }

      if(fl){
        grid[i] = 2;
        int ans = calc(!p, restrictions, grid);
        if(ans == 0){
          hasTie = true;
        } else if(ans == 1){
          hasWin = true;
        } else{
          hasLose = true;
        }
        grid[i] = 0;
      }
    }

    if(hasLose) return 2;
    else if(hasTie) return 0;
    else if(hasWin) return 1;
    else return 0;
  }
}

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<vector<int>> restrictions(9, vector<int>(9));
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;

    restrictions[a - 1][b - 1] = 1;
  }

  vector<int> grid(9, 0);

  int ans = calc(1, restrictions, grid);

  if(ans == 1){
    cout << 'X';
  } else if(ans == 2){
    cout << 'O';
  } else{
    cout << 'E';
  }
}