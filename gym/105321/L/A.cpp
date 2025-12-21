#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int bitsOn(int x){
  int cnt = 0;

  for(int i = 0; i < 32; i++){
    cnt += (x >> i) & 1;
  }

  return cnt;
}

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];

  vector<int> pTwo(n + 1), pOdd(n + 1), pOne(n + 1);

  for(int i = 0; i < n; i++){
    pTwo[i + 1] = pTwo[i];
    pOdd[i + 1] = pOdd[i];
    pOne[i + 1] = pOne[i];
    if(a[i] == 1){
      pOne[i + 1] += 1;
    } else if(a[i] & 1){
      pOdd[i + 1] += a[i];
    } else if(bitsOn(a[i]) == 1){
      pTwo[i + 1] += a[i];
    }
  }

  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;

    int nOne = pOne[r] - pOne[l - 1];
    int agustin = pTwo[r] - pTwo[l - 1] + ((nOne + 1) >> 1);
    int brian = pOdd[r] - pOdd[l - 1] + ((nOne) >> 1);

    if(agustin > brian){
      cout << 'A' << '\n';
    } else if(brian > agustin){
      cout << 'B' << '\n';
    } else{
      cout << 'E' << '\n';
    }
  }

  return 0;
}