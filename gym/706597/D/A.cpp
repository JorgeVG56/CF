#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main() {
  cin.tie(0) -> sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++) {
    int n; cin >> n;

    vector<int> a(n << 1); for(int & x : a) cin >> x;

    stack<int> strawLeft, blueLeft;
    queue<int> strawRight, blueRight;

    for(int i = 0; i < n; i++) {
      if(a[i] == 1) strawLeft.push(i);
      else blueLeft.push(i);
    }

    for(int i = n; i < (n << 1); i++) {
      if(a[i] == 1) strawRight.push(i);
      else blueRight.push(i);
    }

    int strawCnt = strawLeft.size() + strawRight.size();
    int blueCnt = blueLeft.size() + blueRight.size();
    int moves = 0;
    while(strawCnt != blueCnt){
      if(strawCnt > blueCnt) {
        int closestStrawLeft = n - strawLeft.top();
        int closestStrawRight = strawRight.front() - n + 1;
        if(if(close))
      } else {

      }
    }
  }

  return 0;
}