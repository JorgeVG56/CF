/*
  Pura gente del Coach Moy

  
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define INF 1e18
#define ENDL '\n'

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const ll MOD = 1000000007;

vll a;

multiset<ll> ms;

void add(ll idx, ll end){
  ms.insert(a[idx]);
}

void del(ll idx, ll end){
  ms.erase(ms.find(a[idx]));
}

ll calc(ll c, ll l, ll r){
  if(a[l] >= c) return 0;
  return  distance( ms.lower_bound(c),ms.end());
}

vll mosAlgo(vector<pair<ll,ll>> Q, vector<ll> cs){
  ll L  = 0, R = 0, blk = 350;

  vll s(SZ(Q)), res = s;
  #define K(x) pi(x.first/blk,x.second^-(x.first/blk&1))
  iota(ALL(s), 0);
  sort(ALL(s),[&](int s,int t){return K(Q[s])<K(Q[t]);});

  for(ll qi : s){
    pi q = Q[qi];
    while(L > q.first) add(--L, 0);
    while(R < q.second) add(R++, 1);
    while(L < q.first) del(L++, 0);
    while(R > q.second) add(--R, 1);

    res[qi] = calc(cs[qi], L,R);

    // cout << " = " << res[qi] << '\n';
  }

  return res;
}


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll y, n; cin >> y >> n;

  a.resize(y); for(auto & x : a) cin >> x;

  vector<pair<ll, ll>> q(n);
  vll b(n);
  for(ll i = 0; i < n; i++){
    ll l, c, r; cin >> l >> c >> r;

    q[i] = {l-1 , l+ r};
    b[i] = c;
  }

  vll ans = mosAlgo(q, b);

  for(auto & x : ans) cout << x << ENDL;

  return 0;
}
