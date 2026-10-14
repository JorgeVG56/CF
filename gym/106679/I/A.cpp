#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
#define int ll
const ll INF = 4e18;
const ll MOD = 1e9;
const int MAXN = 1e6 + 5;

struct Event {
  ll order, val;

  bool operator<(Event e) { return order < e.order || (order == e.order && val < e.val); }
};

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int f, n; cin >> f >> n;

  map<int, vector<int>> adj; 
  map<int, int> guests;
  vector<int> id(n);
  for(int i = 0; i < n; i++) {
    int p, k; cin >> p >> k;
    guests[p] = k;
    id[i] = p;
  }

  vector<pair<int, int>> time;
  vector<int> accepted;
  for(int i = 0; i < n; i++) {
    char c; cin >> c;
    if(c == 'A') {
      ll a, t; cin >> a >> t;
      time.push_back({a, a + t});
      accepted.push_back(id[i]);
    } else if(c == 'T') {
      int x; cin >> x;
      adj[x].push_back(id[i]);
      adj[id[i]].push_back(x);
    }
  }

  auto dfs = [&] (auto & self, int u, int p = -1) -> ll {
    ll ans = guests[u];
    for(int v : adj[u]) 
      if(v != p)
        ans += self(self, v, u);
    return ans;
  };

  vector<Event> events;
  for(int i = 0; i < accepted.size(); i++) {
    ll total = dfs(dfs, accepted[i]);
    events.push_back({time[i].first, total});
    events.push_back({time[i].second, -total});
  }

  sort(begin(events), end(events));
  ll cur = 0, ans = 0;
  for(Event & e : events) {
    cur += e.val;
    ans = max(ans, cur);
  }

  cout << ans << '\n';
  
  return 0;
} 