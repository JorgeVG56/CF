#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

    int p,d;
    cin>>p>>d;
    priority_queue<int> pq;
    stack<int> st;
    for(int i=0;i<p;i++)
    {
        st.push(0);
    }
    for(int i=0;i<d;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<x;j++)
        {
            int aux=st.top();
            pq.push(aux);
            st.pop();
        }
        while(!pq.empty())
        {
           int aux =pq.top()+1;
           st.push(aux);
           pq.pop();
        }  

    }
    int ans=0;
    while(!st.empty())
    {
        int aux=st.top();
        st.pop();
        ans=max(ans,aux);
    }
    cout<<ans<<"\n";
  return 0;
}