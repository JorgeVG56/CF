#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const string validChar = "!?.,;$#^{}_=+* ";

bool validateCharacters(string s){
  for(char c : s){
    if(isalnum(c)) continue;
    bool fl = false;
    for(char _c : validChar) fl |= _c == c;
    if(fl) continue;
    return false;
  }
  return true;
}

bool validateSpaces(string s){
  if(s[0] == ' ' || s[size(s) - 1] == ' ') return false;
  for(int i = 1; i < size(s); i++) if(s[i] == ' ' && s[i - 1] == ' ') return false;
  return true;
}

vector<string> getTokens(string s){
  vector<string> tokens;
  string curToken = ""; 
  for(char c : s){
    if(c == ' '){ tokens.push_back(curToken); curToken = ""; }
    else curToken += c;
  }
  tokens.push_back(curToken);
  return tokens;
}

bool validateToken(string token){
  bool isScript = false, hasDouble = false;
  for(char c : token){
    if(c != '_' && c != '^') continue;
    if(isScript) hasDouble = true;
    isScript = true;
  }
  if(hasDouble) return false;
  
  if(isScript){
    int pos = -1; for(int i = 0; i < size(token); i++) if(token[i] == '_' || token[i] == '^') pos = i;
    for(int i = 0; i < pos; i++) if(!isalnum(token[i])) return false;
    for(int i = pos + 2; i < size(token) - 1; i++) if(!isdigit(token[i])) return false;
    return token[pos + 1] == '{' && token[size(token) - 1] == '}';
  } 

  bool hasNumber = false, hasAlpha = false, hasOther = false;
  for(char c : token){
    if(isdigit(c)) hasNumber = true;
    else if(isalpha(c)) hasAlpha = true;
    else if(c == '{' || c == '}') return false;
    else hasOther = true;
  }
  if(hasNumber && !hasAlpha && !hasOther) return size(token) == 1 || token[0] != '0';
  if(hasNumber) return !hasOther;
  return true;
}

bool validate(string s){
  if(!validateCharacters(s)) return false;
  if(!validateSpaces(s)) return false;
  vector<string> tokens = getTokens(s);
  for(string token : tokens) if(!validateToken(token)) return false;
  return true;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t; cin.ignore();

  for(int _t = 0; _t < t; _t++){
    string s; getline(cin, s);

    if(!validate(s)){
      cout << "Validation failed" << '\n';
      return 0;
    }
  }

  cout << "Ok" << '\n';

  return 0;
}