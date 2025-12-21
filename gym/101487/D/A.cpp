/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    int n; cin >> n;
    vector<int> a(n); for(auto & x : a) cin >> x;

    // Sin derrumbes, maximo subarreglo creci
    vector<int> dp(n + 1, 1);
    for(int i = 1; i < n; i++) if(a[i] > a[i - 1]) dp[i] = dp[i - 1] + 1;

    vector<int> dpLIS(n + 1);
    vector<int> dpAns(n); dpAns[0] = 1;

    int size = 0;
    for(int i = 0; i < n; i++){
      if(i > 0 && a[i] > a[i - 1]) dpAns[i] = dpAns[i - 1] + 1;

      int pos = (int)(lower_bound(begin(dpLIS), begin(dpLIS) + size, a[i]) - begin(dpLIS));

      dpAns[i] = max(dpAns[i], pos);

      if(dpLIS[dp[i]] == 0 || dpLIS[dp[i]] > a[i]){
        size = max(size, dp[i] + 1);
        dpLIS[dp[i]] = a[i];
      }
    }

    // for(int i = 0; i < n; i++){
    //   cout << dpAns[i] << ' ';
    // }

    cout << *max_element(begin(dpAns), end(dpAns)) << '\n';
  }

  return 0;
}