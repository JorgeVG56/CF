/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int tc; cin >> tc;

  for(int c = 0; c < tc; c++){
    int n; cin >> n;
    string s; cin >> s;

    bool canLookLeft = true;
    bool lookedLeft = false;
    bool canLookRightLast = false;
    bool lookedRight = false;
    bool inDanger = false;
    bool lastOne = false;
    bool fl = true;

    for(int i = 0; i < n; i++){
      if(s[i] == '0'){
        lastOne = false;
        if(inDanger && !canLookLeft){
          fl = false;
          break;
        } else if(!canLookLeft){
          lookedRight = true;
          canLookRightLast = true;
          inDanger = false;
          canLookLeft = true;
          lookedLeft = false;
        } else if(inDanger){
          canLookRightLast = false;
          lookedRight = false;
          inDanger = false;
          lookedLeft = true;
          canLookLeft = true;
        } else{
          canLookRightLast = true;
          lookedRight = false;
          inDanger = false;
          lookedLeft = false;
          canLookLeft = true;
        }
      } else if(s[i] == '1'){
        if(inDanger){
          fl = false;
          break;
        } else if(lookedRight){
          inDanger = true;
        } else if(!canLookRightLast || lastOne){
          canLookLeft = false;
        }
        lastOne = true;
      }
    }

    cout << (fl && !inDanger ? "YES" : "NO") << '\n';
  }
  
  return 0;
}