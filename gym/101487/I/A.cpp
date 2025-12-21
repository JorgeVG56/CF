/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isValid(string s){
  stack<char> st;
  for(char c : s){
    if(c == 'e'){
      if(st.empty() || st.top() != 'a') return false;
      st.pop();
    } else if(c == 'o'){
      if(st.empty() || st.top() != 'i') return false;
      st.pop();
    } else{
      st.push(c);
    }
  }

  return st.empty();
}

void find(int n, string s){
  if(n == 0){
    if(isValid(s)) cout << s << '\n'; 
    return;
  }

  find(n - 1, s + 'a');
  find(n - 1, s + 'e');
  find(n - 1, s + 'i');
  find(n - 1, s + 'o');
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  find(n, "");

  return 0;
}