/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--)
  {
  
  int n; cin >> n;
  int auxN=n;
  vector<vector<int>>mat(200,vector<int>(200));
  
  for(int i=0;i<n-1 && i<200;i++)
  {
    for(int j=0;j<2 && i+j<200;j++)
    {
      mat[i][i+j]=1;
    }
  }
  for(int i=0;i<min(n,200);i++)
  {
    mat[min(n,200)-1][i]=1;
  }

  if (n > 200)
  {
    auxN -= 200;
    int number = 0;
    int subs = 198;
    int cantidad = 1;

    while (auxN > 0 && number < 200)
    {
      int auxnumber = 0;
      int puestos = 0;

      while (puestos < cantidad && auxnumber < 200 && auxN > 0)
      {
        mat[number][auxnumber] = 1;
        auxnumber++;
        puestos++;
        auxN--;
      }

      subs--;
      cantidad++;
      number++;
    }
  }

  cout<<min(200,n)<<"\n";
  for(int i=0;i<min(n,200);i++)
  {
    for(int j=0;j<min(n,200);j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
  }
  return 0;
}
