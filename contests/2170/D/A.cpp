/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    int n, q; cin >> n >> q;

    string s; cin >> s;


    int ans = 0;
    int minus = 0, posMinus = 0, one = 0, two = 0, cnt = 0;
    for(int i = n - 1; i >= 0; i++){
      if(s[i] == '?'){
        if(i != n - 1 && (s[i + 1] == 'X' || s[i + 1] == 'V')){
          minus++;
        } else{
          if(cnt){
            two++;
            cnt = 0;
          } else{
            cnt++;
          }
        }
      } else{
        if(cnt){
          if(s[i] == 'I') one++;
          else posMinus++;
        }
        cnt = 0;
        if(s[i] == 'X') ans += 10;
        else if(s[i] == 'V') ans += 5;
        else if(i != n - 1 && (s[i + 1] == 'X' || s[i + 1] == 'V')) ans--;
        else ans++;
      }
    }

    for(int j = 0; j < q; j++){
      int x, v, i; cin >> x >> v >> i;

      if(i >= minus + one + two + posMinus){
        cout << ans - minus + one + two + posMinus << '\n';
        continue;
      }

      int curAns = ans;
      int curMinus = minus;
      int curPosMinus = posMinus;
      int k = min(minus, i);
      curAns -= k;
      i -= k;

      k = min(two, v);


    }
  }

  return 0;
}