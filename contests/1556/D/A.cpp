/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int query(string s, int i, int j){
  cout << s << ' ' << i + 1 << ' ' << j + 1 << endl;
  int answer; cin >> answer;
  return answer;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  vector<int> arr(n);

  int aANDb = query("and", 0, 1), aORb = query("or", 0, 1);
  int aXORb = ~aANDb & aORb;
  int aPLUSb = (aANDb << 1) + aXORb;

  int aANDc = query("and", 0, 2), aORc = query("or", 0, 2);
  int aXORc = ~aANDc & aORc;
  int aPLUSc = (aANDc << 1) + aXORc;

  int bANDc = query("and", 1, 2), bORc = query("or", 1, 2);
  int bXORc = ~bANDc & bORc;
  int bPLUSc = (bANDc << 1) + bXORc;

  arr[0] = (aPLUSb - bPLUSc + aPLUSc) >> 1; arr[1] = aPLUSb - arr[0]; arr[2] = aPLUSc - arr[0];

  for(int i = 3; i < n; i++){
    int aANDi = query("and", 0, i), aORi = query("or", 0, i);
    int aXORi = ~aANDi & aORi;
    int aPLUSi = (aANDi << 1) + aXORi;
    arr[i] = aPLUSi - arr[0];
  }

  sort(begin(arr), end(arr));

  cout << "finish" << ' ' << arr[k - 1] << endl;

  return 0;
}