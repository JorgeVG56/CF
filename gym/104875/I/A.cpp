/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int l, r; cin >> l >> r;

  vector<int> fizz, buzz;

  for(int i = l; i <= r; i++){
    string s; cin >> s;
    if(s == "Fizz"){
      fizz.push_back(i);
    } else if(s == "Buzz"){
      buzz.push_back(i);
    } else if(s == "FizzBuzz"){
      fizz.push_back(i);
      buzz.push_back(i);
    }
  }

  int a = (fizz.empty() ? r + 1 : (fizz.size() == 1 ? fizz[0] : fizz[1] - fizz[0]));
  int b = (buzz.empty() ? r + 1 : (buzz.size() == 1 ? buzz[0] : buzz[1] - buzz[0]));

  cout << a << ' ' << b << '\n';

  return 0;
}