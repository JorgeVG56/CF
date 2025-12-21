#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct FT{
  vector<ll> s;
 
  FT(int n) : s(n) {};

  void update(int pos, ll dif){
    for(; pos < (int)s.size(); pos |= pos + 1) s[pos] += dif;
  }

  ll querry(int pos){
    ll res = 0;
    for(; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }

  int lower_bound(ll sum){
    if(sum <= 0) return -1;

    int pos = 0;
    for(int pw = 1 << 25; pw; pw >>=1)
      if(pos + pw <= (int)s.size() && s[pos+ pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    
    return pos;
  }
};

void dfs(int u, int p, vector<vector<int>> & adj, vector<int> & in, vector<int> & out, int & t){
  in[u] = ++t;
  for(auto & v : adj[u]) if(v != p) dfs(v, u, adj, in, out, t);
  out[u] = t;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a, b;
  for(int i = 0; i < n; i++){
    int t, x; cin >> t >> x;
    
    if(t == 1){
      a.push_back(x - 1);
    } else{
      b.push_back(x - 1);
    }
  }

  vector<vector<int>> adj(1);
  for(auto & x : a){
    adj[x].push_back((int)adj.size());
    adj.push_back({});
    adj.back().push_back(x);
  }

  vector<int> in(adj.size()), out(adj.size());
  int t = 0;
  dfs(0, -1, adj, in, out, t);

  FT ft((int)adj.size());

  vector<int> c((int) adj.size());

  for(int i = 0; i < (int)adj.size(); i++){ 
    // cout << i << ' ' << in[i] << '\n';
    ft.update(i, 1);
    c[in[i] - 1] = i;
  }

  for(auto & x : b){
    ft.update(in[x] - 1, -1);
    cout << c[ft.lower_bound(1)] + 1 << '\n';
  }

  return 0;
}