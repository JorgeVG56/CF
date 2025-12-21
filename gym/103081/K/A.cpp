#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void solve(){
    string s; cin >> s;
    int n = (int) s.size();
    int lo = 1, hi = n / 2;
    string ans = "";

    while(lo <= hi){
        int mid = (hi + lo) >> 1;

        set<string> st1, st2;    

        for(int i=0;i+mid<=n;i++){
          auto it = st1.find(s.substr(i, mid));
          auto it2 = st2.find(s.substr(i, mid));
          if(it2 != st2.end()) continue;
          if(it != st1.end()){
            st2.insert(*it);
            st1.erase(it);
          } else{
            st1.insert(s.substr(i, mid));
          }
        }

        string c = "";
        for(int i=0;i+mid<=n;i++){
          auto it = st1.find(s.substr(i, mid));
          if(it != st1.end()){
            c = *it;
            break;
          }
        }
        if(c.size()){
            ans = c;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    if(ans.size()){
      cout<<ans<<'\n';
      return;
    }

    lo = n / 2, hi = n;
    ans = "";

    while(lo <= hi){
        int mid = (hi + lo) >> 1;

        set<string> st1, st2;    

        for(int i=0;i+mid<=n;i++){
          auto it = st1.find(s.substr(i, mid));
          auto it2 = st2.find(s.substr(i, mid));
          if(it2 != st2.end()) continue;
          if(it != st1.end()){
            st2.insert(*it);
            st1.erase(it);
          } else{
            st1.insert(s.substr(i, mid));
          }
        }

        string c = "";
        for(int i=0;i+mid<=n;i++){
          auto it = st1.find(s.substr(i, mid));
          if(it != st1.end()){
            c = *it;
            break;
          }
        }
        if(c.size()){
            ans = c;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //int t; cin >> t; while(t--)
    solve();
}