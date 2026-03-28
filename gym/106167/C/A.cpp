/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;

  vector<pair<ll, pair<ll, ll>>> prices(n);

  for(int i = 0; i < n; i++){
    double p; ll b, s; cin >> p >> b >> s;
    prices.push_back({p * 100, {b, s}});
  }

  sort(prices.begin(), prices.end());

  for(ll i = 1; i < prices.size(); i++)
    prices[i].second.second += prices[i - 1].second.second;

  for(ll i = n - 2; i >= 0; i--)
    prices[i].second.first += prices[i + 1].second.first;

  ll price = -1, maxProfit = 0;

  for(ll i = 0; i < n; i++){
    ll currentProfit = prices[i].first * min(prices[i].second.first, prices[i].second.second);

    if(currentProfit > maxProfit){
      maxProfit = currentProfit;
      price = prices[i].first;
    }
  }

  if(maxProfit == 0){
    cout << "impossible" << '\n'; 
  } else{
    cout << price / 100 << '.';
    if(price % 100 < 10) cout << '0';
    cout << price % 100 << ' ';
    
    cout << maxProfit / 100 << '.';
    if(maxProfit % 100 < 10) cout << '0';
    cout << maxProfit % 100 << '\n';
  }

  return 0;
}