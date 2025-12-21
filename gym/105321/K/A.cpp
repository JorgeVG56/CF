#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);  

  int n, m; cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> grid[i][j];
    }
  }

  int t = 0, a = 0, p = 0;
  for(int i = n - 1; i >= 0; i--){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == '.') continue;

      if(grid[i - 2][j + 1] == '.'){ 
        t++;
        grid[i][j] = '.';
        grid[i - 1][j] = '.';
        grid[i - 2][j] = '.';
        grid[i - 3][j] = '.';
        grid[i - 4][j] = '.';
        grid[i - 4][j - 1] = '.';
        grid[i - 4][j + 1] = '.';
      } else if(grid[i][j + 2] == '.'){
        p++;
        grid[i][j] = '.';
        grid[i - 1][j] = '.';
        grid[i - 2][j] = '.';
        grid[i - 2][j + 1] = '.';
        grid[i - 2][j + 2] = '.';
        grid[i - 3][j] = '.';
        grid[i - 3][j + 2] = '.';
        grid[i - 4][j] = '.';
        grid[i - 4][j + 1] = '.';
        grid[i - 4][j + 2] = '.';
      } else{
        a++;
        grid[i][j] = '.';
        grid[i][j + 2] = '.';
        grid[i - 1][j] = '.';
        grid[i - 1][j + 2] = '.';
        grid[i - 2][j] = '.';
        grid[i - 2][j + 1] = '.';
        grid[i - 2][j + 2] = '.';
        grid[i - 3][j] = '.';
        grid[i - 3][j + 2] = '.';
        grid[i - 4][j] = '.';
        grid[i - 4][j + 1] = '.';
        grid[i - 4][j + 2] = '.';
      }
    }
  }

  cout << t << ' ' << a << ' ' << p;
  
  return 0;
}


