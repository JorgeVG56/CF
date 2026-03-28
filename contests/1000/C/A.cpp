/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<pair<ll, ll>> a(n); for(auto & [x, y] : a) cin >> x >> y;
  set<ll> b; for(auto & [x, y] : a) b.push_back(x), b.push_back(y + 1);
  sort(begin(b), end(b));
  b.resize(unique(begin(b), end(b)) - begin(b));

  vector<ll> cnt(n << 1);
  for(auto & [x, y] : a){
    int lo = lower_bound(begin(b), end(b), x) - begin(b);
    int hi = lower_bound(begin(b), end(b), y + 1) - begin(b);
    cnt[lo]++, cnt[hi]--;
  }

  for(int i = 1; i < (n << 1); i++) cnt[i] += cnt[i - 1];

  vector<ll> ans(n + 1);
  for(int i = 1; i < (n << 1); i++) ans[cnt[i - 1]] += b[i] - b[i - 1];

  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << '\n';

  return 0;
}