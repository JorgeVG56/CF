/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  auto query = [&](string s) -> int {
    cout << s << endl;
    int n; cin >> n; for(int i = 0; i < n; i++) cin >> s;
    return n;
  };

  do{
    query("next 0 1");
  } while(query("next 0") != 2);

  while(query("next 0 1 2 3 4 5 6 7 8 9") != 1);

  cout << "done" << '\n';

  return 0;
}