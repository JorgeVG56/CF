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
    vector<pair<ll,ll>>a(n);
    ll cp=0,bill=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
        cp+=a[i].first;
        bill+=a[i].second;
    }

        ll remainder=bill-cp;
        for(int i=0;i<n;i++)
        {
            if(a[i].first+remainder<=a[i].second)
            {
                cout<<i+1<<"\n";
                return 0;
            }
        }
        cout<<"impossible"<<"\n";
        return 0;
}

