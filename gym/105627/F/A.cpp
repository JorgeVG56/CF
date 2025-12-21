#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<string>g;
  string s; getline(cin,s); g.pb(s);
  string t="";
  int m= 1;
  
  while(t!=s){
    getline(cin,t);
    g.pb(t);
    m++;
  }

  g.pb(t);
  int n = s.size();
  
  vector<vector<string>>curso(50);
  vector<vector<bool>>vis(m,(vector<bool>) n);
  
  int cursos = 0;
  
  for(int i=1;i<m-1;i++){
    for(int j=1;j<n-1;j++){
      
      if (g[i][j] == '+' && !vis[i][j]) {
        
        int right = j + 1;
        while (right < n && g[i][right] != '+') right++;
        if (right >= n || g[i][right] != '+') continue;
        
        int down = i + 1;
        while (down < m && g[down][j] != '+') down++;
        if (down >= m || g[down][j] != '+') continue; 
        
        
        vis[i][j]=true;
        vis[i][right]=true;
        vis[down][j]=true;
        vis[down][right]=true;
        for(int o=i+1;o<down;o++)
        {
          string cs="";
          for(int k=j+1;k<right;k++)
          {
            if(g[o][k]!=' '){
              
              cs+=tolower(g[o][k]);
            }
          }
          if(cs!="")
          {
            curso[cursos].pb(cs);
          }
        }
        cursos++;
      }
    }
  }
  
  // for(auto & s : curso  )
  // {
  //   if(s.empty()) continue;
  //   for(auto & c : s){
  //     cout<<c<<" ";
  //   }
  //   cout<<"\n";
  // }
  
  int ans = 1500;
  
  for(int i = 0; i < 50; i++) {
    for(int j = i + 1 ; j < 50; j++) {
      for(int k = j + 1; k < 50; k++){
        if(curso[i].empty() || curso[j].empty() || curso[k].empty()) continue;
        
        set<string> st;
        
        for(string s : curso[i]) st.insert(s);
        for(string s : curso[j]) st.insert(s);
        for(string s : curso[k]) st.insert(s);
        
        ans = min(ans, (int)st.size());
      }
    }
  }
  
  cout<<ans<<'\n';
}
