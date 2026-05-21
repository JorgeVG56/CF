/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int & x : a) cin >> x;
    vector<int> b(n); for(int & x : b) cin >> x;

    bool fl = 1;
    vector<bool> vis(n);
    vector<int> pos(k);
    map<int, int> cnt;
    for(int i = 0; i < k; i++){
      pos[i] = a[i];
    }
      if(b[i] != -1 && b[i] != a[i]) fl = 0;

    for(int i = n - 1; i >= k; i--)
      if(b[i] != -1 && b[i] != a[i]) fl = 0;

    multiset<int> inA, inB;
    int wild = 0;
    for(int i = n - k; i < k; i++){
      inA.insert(a[i]);
      if(b[i] == -1) wild++;
      else inB.insert(b[i]);
    }

    for(int x : inA){
      if(inB.count(x)) continue;
      wild--;
    }
    
    if(wild < 0) fl = 0;

    cout << (fl ? "Yes" : "No") << '\n';
  } 
  return 0;
}