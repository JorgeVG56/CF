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
    int n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;

    int emptyS = 0; for(int i = 0; i < n - 1; i++) if(s[i] == '(' && s[i + 1] == ')') emptyS++;
    int emptyT = 0; for(int i = 0; i < n - 1; i++) if(t[i] == '(' && t[i + 1] == ')') emptyT++;

    int depthS = 0;
    int depthT = 0;

    vector<int> endS(n); stack<int> stS;
    for(int i = 0; i < n; i++){
      if(s[i] == '(') stS.push(i);
      else { endS[stS.top()] = i; stS.pop(); }
    }

    vector<int> endT(n); stack<int> stT;
    for(int i = 0; i < n; i++){
      if(t[i] == '(') stT.push(i);
      else { endT[stT.top()] = i; stT.pop(); }
    }

    for(int i = 0; i < n; i++){
      if(endS[i] != n - i - 1) break;
      else depthS++;
    }

    for(int i = 0; i < n; i++){
      if(endT[i] != n - i - 1) break;
      else depthT++;
    }

    if(emptyS == emptyT && depthS == depthT) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }

  return 0;
}