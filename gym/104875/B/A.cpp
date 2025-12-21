/*
  Pura gente del Coach Moy

  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double f(double ha, double hw, double a, double w){
  // cout << ha << " " << hw << " " << a << " " << w << '\n';
  return (a * ha * ha + w * hw * hw) / (a * ha + w * hw);
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  double h, rad, a, w; cin >> h >> rad >> a >> w;

  double l = 0, r = h;

  while(r - l >= 1e-7){
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;

    double f1 = f(h - m1, m1, a, w);
    double f2 = f(h - m2, m2, a, w);
    
    if(f1 < f2){
      r = m2;
    } else if(f1 > f2){
      l = m1;
    } else{
      l = m1, r = m2;
    }
  }

  cout << fixed << setprecision(8) << l << '\n';

  return 0;
}