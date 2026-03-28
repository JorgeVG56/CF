/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, l, r; cin >> n >> l >> r;

  vector<int> a(n + 1);

  for(int i = 0; i < l; i++)
    cin >> a[i];

  for(int i = 0; i < r; i++)
    cin >> a[n - i];    

  int zeroPosition = min_element(begin(a), end(a)) - begin(a);

  int ans = 0, maxL = 0, maxR = 0;

  for(int i = zeroPosition - 1; i >= 0; i--)
    if(a[i] > maxL) ans++, maxL = a[i];
  
  for(int i = zeroPosition + 1; i <= n; i++)
    if(a[i] > maxR) ans++, maxR = a[ip];

  cout << ans << '\n';

  return 0;
}