/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  int moves[2][2];
  cin >> moves[0][0] >> moves[0][1];
  cin >> moves[1][0] >> moves[1][1];

  bool visited[n][n][2];
  memset(visited, false, sizeof(visited));

  queue<pair<pair<int, int>, int>> q; 
  q.push({{0, 0}, 0}); q.push({{0, 0}, 1});
  visited[0][0][1] = visited[0][0][0] = true;

  int dx[] = {1, -1, 1, -1};
  int dy[] = {1, 1, -1, -1};

  while(!q.empty()){
    auto [pos, mov] = q.front(); q.pop();
    auto [x, y] = pos;

    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 2; j++){
        int newX = x + dx[i] * moves[mov][j];
        int newY = y + dy[i] * moves[mov][1 ^ j];

        if(newX < 0 || newX >= n) continue;
        if(newY < 0 || newY >= n) continue;

        if(visited[newX][newY][1 ^ mov]) continue;
        visited[newX][newY][1 ^ mov] = true;
        q.push({{newX, newY}, 1 ^ mov});
      }
    }
  }

  int cnt = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cnt += visited[i][j][0] || visited[i][j][1];

  cout << cnt << '\n';

  return 0;
}