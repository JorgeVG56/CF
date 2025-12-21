/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    ll n; cin >> n;

    vector<ll> a(n); for(ll & x : a) cin >> x;
    int mxElement = (int)(max_element(begin(a), end(a)) - begin(a));
    
    vector<ll> b(n); for(int i = 0; i < n; i++) b[i] = a[(i + mxElement) % n];
    
    stack<ll> st; st.push((ll)1e18);
    ll ans = 0 ;

    for(ll & x : b){
      while(x >= st.top()){
        st.pop(); ans += min(st.top(), x);
      }
      st.push(x);
    }

    while((ll)st.size() > 2){
      st.pop(); ans += st.top();
    }

    cout << ans << '\n';
  }

  return 0;
}