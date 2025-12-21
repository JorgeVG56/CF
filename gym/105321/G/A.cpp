#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;

  int t = 0, a = 0, u = 0, p = 0;

  for(char c : s){
    if(c == 'T') t++;
    if(c == 'A') a++;
    if(c == 'U') u++;
    if(c == 'P') p++;
  }

  cout << min({t, p, a + u});

  return 0;
}