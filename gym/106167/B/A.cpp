/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;

  for(int i = size(s) - 1; i >= 0; i--){
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
      cout << s.substr(0, i + 1) << "ntry" << '\n';
      return 0;
    }
  }

  return 0;
}