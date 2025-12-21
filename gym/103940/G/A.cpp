/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  int distance[n - 1];
  for(int i = 0; i < n - 1; i++) cin >> distance[i];

  int wait[n];
  for(int i = 0; i < n; i++) cin >> wait[i];

  pair<int, int> t1 = {0, wait[0]}, t2 = {n - 1, wait[n - 1]};
    // cout << t1.first << ',' << t1.second << " - ";
    // cout << t2.first << ',' << t2.second << "\n";

  while(abs(t1.first) <= abs(t2.first)){
    if(t1.second < t2.second){
      if(t1.first == t2.first && t1.first >= 0){
        cout << t1.second << '\n';
        return 0;
      } else{
        t2.second -= t1.second;
        t1.second = 0;
      }
    } else{
      if(t1.first == t2.first && t2.first >= 0){
        cout << t2.second << '\n';
        return 0;
      } else{
        t1.second -= t2.second;
        t2.second = 0;
      }
    }

    if(t1.second == 0){
      if(t1.first >= 0){
        t1.second = distance[t1.first];
        t1.first = -(t1.first + 1);
      } else{
        t1.first = -t1.first;
        t1.second = wait[t1.first];
      }
    }

    if(t2.second == 0){
      if(t2.first >= 0){
        t2.second = distance[t2.first - 1];
        t2.first = -(t2.first - 1);
      } else{
        t2.first = -t2.first;
        t2.second = wait[t2.first];
      }
    }
    // cout << t1.first << ',' << t1.second << " - ";
    // cout << t2.first << ',' << t2.second << "\n";
  }

  cout << 0 << '\n';

  return 0;
}