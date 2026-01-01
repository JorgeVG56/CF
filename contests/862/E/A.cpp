/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m, q; cin >> n >> m >> q;

  vector<ll> a(n); for(auto & x : a) cin >> x;
  vector<ll> b(m); for(auto & x : b) cin >> x;

  ll sumA = 0; for(int i = 0; i < n; i++) sumA += (i & 1 ? -1ll : 1ll) * a[i];

  vector<ll> c;
  ll l = 0, r = 0, sumB = 0;
  while(r < n - 1) sumB += (r & 1 ? 1ll : -1ll) * b[r++];
  while(r < m){
    sumB += (r & 1 ? 1ll : -1ll) * b[r++];
    c.push_back((l & 1 ? -1ll : 1ll) * sumB), sumB -= (l & 1 ? 1ll : -1ll) * b[l++];
  }

  sort(begin(c), end(c));

  auto answer = [&]() -> ll {
    auto it = lower_bound(begin(c), end(c), -sumA);
    if(it == end(c)) it--;
    ll opA = llabs(sumA + *it);
    if(it != begin(c)) it--;
    return min(opA, llabs(sumA + *it));
  };

  cout << answer() << '\n';

  for(int i = 0; i < q; i++){
    int l, r, x; cin >> l >> r >> x;

    if((l - r + 1) & 1) sumA += (l & 1 ? 1ll : -1ll) * x;

    cout << answer() << '\n';
  }

  return 0;
}