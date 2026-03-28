/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

    int w, h, k, ia, t; cin >> w >> h >> k >> ia >> t;

    vector<vector<char>> g(w, vector<char>(h, '.'));
    g[0][0]='K';
    g[0][1]='I';
    g[0][2]='T';
    k--; ia--; t--;
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(g[i][j]=='.')
            {
                if(k>0)
                {
                    g[i][j]='K';
                    k--;
                }
                else if(t>0)
                {
                    g[i][j]='T';
                    t--;
                }
                else
                {
                    g[i][j]='I';
                    ia--;
                }
            }
        }
    }
     for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
          cout<<g[i][j];
        }
        cout<<"\n";
    }
  return 0;
}