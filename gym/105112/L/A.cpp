/*
Pura gente del Coach Moy


*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string query(int x, int y){
  cout << x + 1 << ' ' << y + 1 << '\n'; cout.flush();
  string result;
  if(!(cin >> result)) exit(0);
  return result;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, ships; cin >> n >> ships;
  
  bool shot[n][n];
  memset(shot, false, sizeof(shot));
  
  for(int i = 0; i < n; i++){
    for(int j = i % 5; j < n; j += 5){
      string result = query(i, j);
      if(result == "hit") shot[i][j] = 1;
    }
  }
  
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  for(int i = 0; i < n; i++){
    for(int j = i % 5; j < n; j += 5){    
      if(!shot[i][j]) continue;
      
      for(int k = 0; k < 4; k++){
        for(int l = 1; l < 5; l++){
          if(i + dx[k] * l >= 0 && i + dx[k] * l < n &&  j + dy[k] * l >= 0 && j + dy[k] * l < n){
            string result = query(i + dx[k] * l, j + dy[k] * l);
            if(result == "sunk") ships--;
            if(!ships) return 0;
          }
        }
      }

    }
  }
  
  return 0;
}