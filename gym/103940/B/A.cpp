/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  vector<ll> palindromeNumbers; palindromeNumbers.push_back(1);

  for(ll i = 1; i < 33; i++){
    ll x = 1 | (1ll << i);

    ll range = i >> 1;

    for(ll mask = 0; mask < (1 << range); mask++){
      ll y = x;

      for(ll j = 0; j <= range; j++){
        if((mask >> j) & 1){
          y |= (1ll << (j + 1));
          y |= (1ll << (i - j - 1));
        }
      }

      palindromeNumbers.push_back(y);
    }
  }

  sort(begin(palindromeNumbers), end(palindromeNumbers));

  auto query = [&](int x) -> int{
    return upper_bound(begin(palindromeNumbers), end(palindromeNumbers), x) - begin(palindromeNumbers) - 1;
  };

  ll q; cin >> q;

  for(ll i = 0; i < q; i++){
    ll a, b; cin >> a >> b;

    cout << query(b) - query(a-1) << '\n';

  }

  
  return 0;
}