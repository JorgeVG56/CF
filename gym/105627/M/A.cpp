/*
Pura gente del Coach Moy


*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  set<string> colors;
  vector<string>paints(n);
  
  for(int i=0;i<n;i++){
    cin >> paints[i];
    colors.insert(paints[i]);
  }
  
  int totalColors = (int)colors.size();
  map<pair<pair<int, int>, pair<bool, set<string>>>, int> dp;
         //n,   intervals, in,   colors;
  
  for(int i = n - 2; i >= 0; i--){
    dp[{{i, 2}, {1, }}]
  }
  
  
  return 0;
}