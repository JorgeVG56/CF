#include<bits/stdc++.h>

using namespace std;

using ll = long long;


int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n, x; cin >> n >> x;
  
  vector<ll> a(n); for(int i = 0; i < n; i++) cin >> a[i];
  
  sort(begin(a), end(a));
  
  bool fl = true;
  ll cnt = 1, b = -1, c = -1;
  for(int i = 0; i < n -1; i++){
    if(a[i] + a[i + 1] == x){
      fl = false;
      if(a[i] == a[i + 1]){
        cnt++;
        b = a[i];
        c = i;
      } else{
        b = a[i + 1];
      }
    }
  }
  
  if(fl){
    for(ll x : a) cout << x << ' ';

    return 0;
  } 
  
  if(cnt == 1){
    if(a[0] + a[n - 1] == x && a[n - 1] == b){
      cout << '*';

      return 0;
    }
    
    if(a[n - 1] != b){
      for(int i = 0; i < n - 1; i++){
        if(a[i] == b){
          cout << a[n - 1] << ' ';
          b = -1;
        }

        cout << a[i] << ' ';
      }
    } else{
      for(int i = 1; i < n; i++){
        if(a[i] == b){
          cout << a[0] << ' ';
          b = -1;
        }

        cout << a[i] << ' ';
      }
    }
    
    return 0;
  } 
  
  if((cnt << 1) > n + 1){
    cout << '*';
    return 0;
  } 

  ll t = (cnt << 1) - 1;

  c = c - t;

  if(t == n){
    int j = 0;
    for(int i = 0; i < n; i++){
      if(i & 1 || !cnt){
        while(a[j] == b) j++;
        cout << a[j] << ' '; j++;
      } else{
        cout << b << ' ';
        cnt--;
      }
    }
  } else{
    int j = 0;
    for(int i = 0; i < n; i++){
      if(i <= c || (i ^ c) & 1 || !cnt){
        while(a[j] == b) j++;
        cout << a[j] << ' '; j++;
      } else{
        cout << b << ' ';
        cnt--;
      }
    }
  }
  
  return 0;
}

