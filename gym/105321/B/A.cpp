#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> divisors;

  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      divisors.push_back(i);
      if(i != n / i) divisors.push_back(n / i);
    }
  }

  sort(begin(divisors), end(divisors));

  vector<bool> used(size(divisors));

  vector<pair<int, int>> querries;
  for(int i = size(used) - 1; i >= 0; i--){
    // cout << divisors[i] << " -> ";

    if(used[i]){
      // cout << '\n';
      continue;
    }

    querries.emplace_back(1, divisors[i]);

    for(int j = 0; divisors[j] <= (divisors[i] >> 1); j++){
      // cout << divisors[j] << ' ';
      if(divisors[i] % divisors[j] == 0){
        used[j] = 1;
      }
    }

    // cout << '\n';
  }

  if(size(querries) == 0) querries.emplace_back(1, 1);

  cout << size(querries) << '\n';

  for(auto & [a, b] : querries) cout << a << ' ' << b << '\n';

  return 0;
}