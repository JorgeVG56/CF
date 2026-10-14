#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define int ll
const ll INF = 4e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int n = 100, m = 100;

  vector<vector<char>> maze(n, vector<char>(m, '#'));

  for(int i=0;i<10;i++)
    maze[2*i][2*i+2] = '\\';

  maze[0][1] = '*', maze[0][3] = 'F';

  for(int i = 0; i < 9; i++){
    maze[2*i+1][2*i+2] = '.', maze[2*i+2][2*i+2] = '.';
    maze[2*i+2][2*i+3] = '.', maze[2*i+2][99] = 'X';
    for(int j = 2 * i + 5; j <= 98; j++) 
      maze[2*i+2][j] = '.';
  }

  for(int i = 19; i <= 98; i++)  
    maze[i][20] = '.';

  maze[99][20] = 'X';

  cout << n << ' ' << m << '\n';
  for(auto & line : maze) {
    for(auto & c : line)
      cout << c;
    cout << '\n';
  }
  
  return 0;
} 