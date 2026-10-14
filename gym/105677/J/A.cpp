#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
const int INF = 1e9;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

struct Edge {
  int to, cap, cost, rev;
};

vector<vector<Edge>> adj;
vector<int> disS, disD;;
vector<pair<int, int>> par;

void addEdge(int from, int to, int cap, int cost) {
  adj[from].push_back({to, cap, cost, (int)adj[to].size()});
  adj[to].push_back({from, 0, -cost, (int)adj[from].size() - 1});
}

void initialSPFA(int n, int s) {
  fill(begin(disS), end(disS), INF); disS[s] = 0;
  vector<bool> vis(n); vis[s] = true;
  queue<int> q; q.push(s);
  
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = false;
    
    for(auto& e : adj[u]) {
      if (e.cap <= 0 || disS[e.to] <= disS[u] + e.cost) continue;
      disS[e.to] = disS[u] + e.cost;
      if(vis[e.to]) continue;
      vis[e.to] = true;
      q.push(e.to);
    }
  }
}

bool dijkstra(int n, int s, int t) {
  fill(begin(disD), end(disD), INF); disD[s] = 0;
  fill(begin(par), end(par), make_pair(-1, -1)); 
  
  priority_queue<pair<int, int>> pq; pq.push({0, s});
  
  while(!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    d *= -1;
    
    if(d > disD[u]) continue;
    
    for(int i = 0; i < adj[u].size(); i++) {
      auto & e = adj[u][i];
      if(e.cap <= 0) continue;
      int reduced_cost = e.cost + disS[u] - disS[e.to]; 
      if(disD[e.to] <= disD[u] + reduced_cost) continue;
      disD[e.to] = disD[u] + reduced_cost;
      par[e.to] = {u, i};
      pq.push({-disD[e.to], e.to});
    }
  }
  return disD[t] != INF;
}

int minCostFlow(int n, int k, int s, int t) {
  disS.assign(n, 0);
  disD.assign(n, 0);
  par.assign(n, {-1, -1});

  initialSPFA(n, s);
  
  int flow = 0, totalCost = 0;
  
  while (flow < k) {
    if (!dijkstra(n, s, t)) break;
    
    for (int i = 0; i < n; i++) 
      if (disD[i] != INF) disS[i] += disD[i];
    
    int f = k - flow, cur = t;
    
    while (cur != s) {
      int p = par[cur].first, idx = par[cur].second;
      f = min(f, adj[p][idx].cap), cur = p;
    }
    
    flow += f, totalCost += f * disS[t];
    cur = t;
    
    while (cur != s) {
      int p = par[cur].first, idx = par[cur].second, revIdx = adj[p][idx].rev;
      adj[p][idx].cap -= f, adj[cur][revIdx].cap += f, cur = p;
    }
  }
  
  if (flow < k) return INF;
  return totalCost;
}

struct Restriction {
  int sum;
  vector<pair<int, int>> cells;
};

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  
  int n, m, s; cin >> n >> m >> s;

  vector<vector<int>> grid(n, vector<int>(m));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) { 
      char c; cin >> c;
      grid[i][j] = c - '1';
    }
  }

  vector<Restriction> horizontalRestrictions, verticalRestrictions;

  for(int k = 0; k < s; k++) {
    char c; cin >> c;
    int idx, jdx, sum; cin >> idx >> jdx >> sum; --idx, --jdx;
    vector<pair<int, int>> cells;
    if(c == 'H') {
      for(int j = jdx + 1; j < m && grid[idx][j] >= 0; j++) 
        cells.push_back({idx, j});
      if(sum < cells.size()) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
      }
      horizontalRestrictions.push_back({sum - (int)cells.size(), cells});
    } else {
      for(int i = idx + 1; i < n && grid[i][jdx] >= 0; i++) 
        cells.push_back({i, jdx});
      if(sum < cells.size()) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
      }
      verticalRestrictions.push_back({sum - (int)cells.size(), cells});
    }
  }

  int totalCells = n * m * 2;
  int totalHorizontal = horizontalRestrictions.size();
  int totalVertical = verticalRestrictions.size();
  int source = totalCells + totalHorizontal + totalVertical;
  int sink = totalCells + totalHorizontal + totalVertical + 1;
  adj.assign(sink + 1, vector<Edge>());

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(grid[i][j] < 0) continue;
      int id = i * m + j;
      addEdge(id * 2, id * 2 + 1, grid[i][j], -1);
      addEdge(id * 2, id * 2 + 1, 8 - grid[i][j], 1);
    }
  }

  int sumHorizontal = 0;
  for(int k = 0; k < totalHorizontal; k++) {
    sumHorizontal += horizontalRestrictions[k].sum;
    addEdge(source, totalCells + k, horizontalRestrictions[k].sum, 0);
    for(auto [i, j] : horizontalRestrictions[k].cells) {
      int id = i * m + j;
      addEdge(totalCells + k, id * 2, INF, 0);
    }
  }

  int sumVertical = 0;
  for(int k = 0; k < totalVertical; k++) {
    sumVertical += verticalRestrictions[k].sum;
    addEdge(totalCells + totalHorizontal + k, sink, verticalRestrictions[k].sum, 0);
    for(auto [i, j] : verticalRestrictions[k].cells) {
      int id = i * m + j;
      addEdge(id * 2 + 1, totalCells + totalHorizontal + k, INF, 0);
    }
  }

  if(sumHorizontal != sumVertical) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }

  int cost = minCostFlow(sink + 1, sumHorizontal, source, sink);

  if(cost == INF) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }

  int totalSum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(grid[i][j] <= 0) continue;
      totalSum += grid[i][j];
    }
  }

  cout << totalSum + cost << '\n';
  
  return 0;
}
