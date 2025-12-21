#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll formula(ll a, ll b, ll c){
  return (a * a + b * b + c * c) - (a * b + a * c + b * c);
}

int main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;

  vector<ll> v(n); for(int i = 0; i < n; i++) cin >> v[i];

  sort(rbegin(v), rend(v));

  cout << formula(v[0], v[0], v[n - 1]);

  return 0;
}