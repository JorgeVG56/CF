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

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}
inline int sub(int x, int y) {
  return x >= y ? x - y : x - y + MOD;
}
inline int mul(int x, int y) {
  return int((ll)x * y % MOD);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<ll> fib; fib.pb(2); fib.pb(3);

  ll a = 2, b = 3, c = 0;

  while(c <= 1e18){
    c = a + b;
    a = b;
    b = c;

    fib.pb(c);
  }

  ll n; cin >> n;

  string ans = "";

  ROF(i, SZ(fib), 0){
    cout << n << ' ' << fib[i] << '\n';
    while(n % fib[i] == 0){
      n /= fib[i];
      FOR(j, 0, i + 1){
        ans.pb('A');
      }

      ans.pb('B');
    }
  }

  if(n != 1){
    cout << "IMPOSSIBLE"<<'\n';
  } else{
    cout << ans<< '\n';
  }

  return 0;
}
