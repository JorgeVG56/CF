/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
ll memo[105][1 << 10];
int momentos[105];
int capas[10];

ll dp(int idx, int mask){
  if(idx == n) return (mask == 0 ? 0 : (ll)1e18);

  if(memo[idx][mask] != -1) return memo[idx][mask];

  ll cur = (ll)1e18;

  int restantes = __builtin_popcount(mask);

  for(int j = 0; j < k; j++){
    if(!(mask >> j & 1)) continue;

    ll acum = 0;
    for(int i = idx; i <= n - restantes; i++){
      acum += momentos[i];
      ll curAns = (acum - capas[j]) * (acum - capas[j]) + dp(i + 1, mask & ~(1 << j));
      cur = min(cur, curAns);
    }
  }

  return memo[idx][mask] = cur;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  memset(memo, -1, sizeof(memo));

  cin >> n >> k;

  for(int i = 0; i < n; i++) cin >> momentos[i];
  for(int i = 0; i < k; i++) cin >> capas[i];

  cout << dp(0, (1 << k) - 1) << '\n';

  return 0;
}