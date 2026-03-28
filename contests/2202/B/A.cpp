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

    if(!(n & 1)){
      bool ans = true;
      for(int i = 0; i + 1 < n; i += 2){
        ans &= (s[i] == '?' || s[i] != s[i + 1]);
      }  

      cout << (ans ? "Yes" : "No") << '\n';

      continue;
    }

    char a[2] = {'a', 'b'};
    bool fl = false, wild = false, ans = true;
    for(int i = 0; i + 1 < n; i += 2){
      if(wild){
        if(s[i] != '?'){
          wild = false;
          fl = s[i] == 'b';
          i -= 2;
        } else if(s[i + 1] != '?'){
          wild = false;
          fl = s[i + 1] == 'a';
        }
      } else{
        if(s[i] == a[!fl]){
          ans = false;
          break;
        } else if(s[i + 1] == a[fl]){
          fl = !fl;
        } else if(s[i + 1] == '?'){
          wild = true;
        }
      }
    }

    if(!wild && s[n - 1] != '?') ans &= s[n - 1] == a[fl];

    cout << (ans ? "Yes" : "No") << '\n';
  }

  return 0;
}