/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin>>n;
  vector<int>a(3);
  for(int i=0;i<n;i++){
    char l;
    cin>>l;
    if(l=='r')
    {
        a[0]++;
    }
    else if(l=='b')
    {
        a[1]++;
    }
    else
    {
        a[2]++;
    }
  }
  sort(a.begin(),a.end());
  if(a[2]==n)
  {
    cout<<0.00000<<"\n";
    return 0;
  }
  if(a[0]==0)
  {
    double ans=3.000 *(a[1]);
    cout<<fixed<<setprecision(6)<<ans<<"\n";
    return 0;
  }
  double ans=1e9;
  int fv=(a[0]+1/2);
  int pMult=3* min(a[1],a[2])+fv;
  int pMulS=pMult+fv;
  ans=(pMult+pMulS)/2.00;
  cout<<fixed<<setprecision(6)<<ans<<"\n";
  return 0;
}