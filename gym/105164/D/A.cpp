/*
  Pura gente del Coach Moy

  p = p;
  a = {(p + 2) / 3, (p - 1) / 2}

  a = p - b - c
  b + c = p - a


  p = 3
  a = {1, 1}
  sp = {2, 2}
  1, 1, 1

  p = 19
  a = {7, 9}
  sp = {12, 10} -> {10, 12}
  9, 9, 1
  9, 8, 2 
  9, 7, 3
  9, 6, 4
  9, 5, 5
  8, 8, 4
  8, 7, 5
  8, 6, 6
  7, 7, 6

  p = 20
  a = {7, 9}
  sp = {13, 11} -> {11, 13}
  9, 9, 2 
  9, 8, 3 
  9, 7, 4
  9, 6, 5
  8, 8, 4
  8, 7, 5
  8, 6, 6
  7, 7, 6

  p = 1000000
  a = {333334, 4999999}
  sp = {666666, 5000001} -> {5000001, 666666}
  
  3, 7, 11, 15, 19, 23,
  1 -> 1
  1 4 -> 5
  1 4 7 -> 12

(3) 3 -> 1  -> 1
(1) 4 ->  -> 0
(2) 5 -> 1  -> 1
(3) 6 -> 1  -> 1
(1) 7 -> 2  -> 2
(2) 8 -> 1  -> 1
(3) 9 -> 1 2  -> 3
(1) 10 -> 2  -> 2
(2) 11 -> 1 3  -> 4
(3) 12 -> 1 2  -> 3
(1) 13 -> 2 3  -> 5
(2) 14 -> 1 3  -> 4
(3) 15 -> 1 2 4  -> 7
(1) 16 -> 2 3  -> 5
(2) 17 -> 1 3 4  -> 8
(3) 18 -> 1 2 4  -> 7
(1) 19 -> 2 3 5  -> 10
(2) 20 -> 1 3 4  -> 8
(3) 21 -> 1 2 4 5  -> 12
(1) 22 -> 2 3 5  -> 10
(2) 23 -> 1 3 4 6  -> 14
24 -> 1 2 4 5  -> 12
25 -> 2 3 5 6  -> 16
26 -> 1 3 4 6  -> 14
27 -> 1 2 4 5 7  -> 19
28 -> 2 3 5 6  -> 16
29 -> 1 3 4 6 7  -> 21
30 -> 1 2 4 5 7  -> 19
31 -> 2 3 5 6 8  -> 24
32 -> 1 3 4 6 7  -> 21
33 -> 1 2 4 5 7 8  -> 27
34 -> 2 3 5 6 8  -> 24
35 -> 1 3 4 6 7 9  -> 30
36 -> 1 2 4 5 7 8  -> 27
37 -> 2 3 5 6 8 9  -> 33
38 -> 1 3 4 6 7 9  -> 30
39 -> 1 2 4 5 7 8 10  -> 37
40 -> 2 3 5 6 8 9  -> 33
41 -> 1 3 4 6 7 9 10  -> 40
42 -> 1 2 4 5 7 8 10  -> 37
43 -> 2 3 5 6 8 9 11  -> 44
44 -> 1 3 4 6 7 9 10  -> 40
45 -> 1 2 4 5 7 8 10 11  -> 48
46 -> 2 3 5 6 8 9 11  -> 44
47 -> 1 3 4 6 7 9 10 12  -> 52
48 -> 1 2 4 5 7 8 10 11  -> 48
49 -> 2 3 5 6 8 9 11 12  -> 56
50 -> 1 3 4 6 7 9 10 12  -> 52
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define INF 1e18
#define ENDL '\n'

const ll dx[] = {-1, 0, 1, 0};
const ll dy[] = {0, 1, 0, -1};
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {
  return x + y < MOD ? x + y : x + y - MOD;
}
inline ll sub(ll x, ll y) {
  return x >= y ? x - y : x - y + MOD;
}
inline ll mul(ll x, ll y) {
  return ll((ll)x * y % MOD);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;

  ll ans = 0;
  FOR(p, 3, n + 1){
    ll r = (p + 1) >> 2;

    ll curAns = (r * (r + 1)) >> 1;

    if(p % 3 == 0){
      ll t = r / 3;
      curAns = curAns - ((3 * t * (t + 1)) >> 1);
    } else if(p % 3 == 1){
      ll t = (r - 1) / 3 + 1;
      curAns = curAns - ((t * (3 * t - 1)) >> 1);
    } else{
      ll t = (r - 2) / 3 + 1;
      curAns = curAns - ((t * (3 * t + 1)) >> 1);
    }

    if(p == 5){
      curAns = 1;
    }

    // cout << p << " -> " << curAns << ENDL;

    ans = add(ans, curAns);
  }

  cout << ans % MOD;

  return 0;
}