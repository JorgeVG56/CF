/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;
    string s; cin >> s;

    int min = 0, max = 0;

    int cnt = 0, lastZero = 0;
    for(int i = 1; i < n; i++){
      if(s[i] == '1') cnt += (cnt && lastZero) + 1, lastZero = 0;
      else if(lastZero){
        max += cnt;
        min += cnt - (cnt - 1) / 2;
        cnt = 0;
      } else lastZero = 1;
    }

    max += cnt;
    min += cnt - (cnt - 1) / 2;
    cnt = 0;

    cout << min << ' ' << max << '\n';
  }

  return 0;
}