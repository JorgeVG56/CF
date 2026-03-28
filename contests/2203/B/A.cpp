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
    string s; cin >> s;
    string _s = s; _s[0] = '1';

    sort(begin(s) + 1, end(s));
    sort(begin(_s), end(_s));

    int aux = 0; 
    int answerOne = 0;
    for(int i = 0; i < size(s); i++) 
      if(aux + s[i] - '0' <= 9) aux += s[i] - '0';
      else { answerOne = size(s) - i; break; }

    aux = 0;
    int answerTwo = 1;
    for(int i = 0; i < size(_s); i++) 
      if(aux + _s[i] - '0' <= 9) aux += _s[i] - '0';
      else { answerTwo = size(_s) - i + 1; break; }

    cout << min(answerOne, answerTwo) << '\n';
  }

  return 0;
}