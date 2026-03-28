/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<pair<pair<int, int>, int>> edges(m); 
  for(auto & [e, u] : edges){
    auto & [w, d] = e;
    cin >> u >> d >> w;
  }

  int q; cin >> q;

  vector<pair<int, int>> queries(q); 
  for(int i = 0; i < q; i++){
    cin >> queries[i].first;
    queries[i].second = i;
  }

  sort(rbegin(edges), rend(edges));
  sort(rbegin(queries), rend(queries));

  //  0-1, 1-2, 2-3, 3-4
  // [1e9, 1e9, 1e9, 1e9]
  ll canReach = n - 1;
  ll minCost = 1e9 * (n - 1);
  vector<int> cost(n - 1, 1e9);

  int currentEdge = 0;
  vector<ll> answers(q);
  for(int i = 0; i < q; i++){
    while(currentEdge < size(edges) && queries[i].first <= edges[currentEdge].first.first){
      auto [e, u] = edges[currentEdge];
      auto [w, d] = e;

      if(d < cost[u - 1]){
        if(cost[u - 1] == 1e9) canReach--;
        minCost -= cost[u - 1] - d;
        cost[u - 1] = d;
      }
      
      currentEdge++;
    }

    if(canReach != 0){
      answers[queries[i].second] = -1;
    } else{
      answers[queries[i].second] = minCost;
    }
  }

  for(auto x : answers){
    if(x == -1){
      cout << "impossible" << '\n';  
    } else{
      cout << x << '\n';
    }
  }

  return 0;
}