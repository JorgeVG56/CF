#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];

  int ans = 0, cnt = 0;
  for(int i = 0; i < n; i++){
    if(a[i]){
      ans++;
      cnt++;
    } else{
      ans--;
      ans += max(0, cnt - 2);
      cnt = 0;
    }
  }
  
  ans += max(0, cnt - 2);

  cout << ans;
}