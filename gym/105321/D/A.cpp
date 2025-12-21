#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int a, b, c; cin >> a >> b >> c;

  if(a + b <= c || a + c <= b || b + c <= a){
    cout << "S";
  } else{
    cout << "N";
  }
}