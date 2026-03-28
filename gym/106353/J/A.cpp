/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k, q; cin >> n >> k >> q;

  vector<int> arr;
  vector<vector<int>> queries(q); 
  for(int i = 0; i < q; i++){
    int p, l, r; cin >> p >> l >> r;
    arr.push_back(l); arr.push_back(r);
    queries[i] = {l, r, i};
  }
  
  sort(begin(arr), end(arr));
  for(int i = 0; i < q; i++){
    int l = lower_bound(begin(arr), end(arr), queries[i][0]) - begin(arr);
    int r = lower_bound(begin(arr), end(arr), queries[i][1]) - begin(arr);
    queries[i] = {l, r, queries[i][2]};
  }
 
  sort(begin(queries), end(queries));
  vector<int> inHouse(arr.size());
  for(int i = 0; i < q; i++){
    inHouse[queries[i][0]] = -1;
    inHouse[queries[i][1]] = 1;
  }

  vector<int> preffix(arr.size() + 1); preffix[0] = n;
  for(int i = 0; i < (int) arr.size(); i++) preffix[i + 1] = preffix[i] + inHouse[i];

  vector<char> ans(q, '0');
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < q; i++){
    while(!pq.empty() && pq.top() < queries[i][0]) k++, pq.pop();
    if(preffix[queries[i][1]]) continue;
    if(k == 0){
      cout << "impossible" << '\n';
      return 0;
    }
    ans[queries[i][2]] = '1'; k--; pq.push(queries[i][1]);
  }

  for(char c : ans) cout << c;
  cout << '\n';

  return 0;
}