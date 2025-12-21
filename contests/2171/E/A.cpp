/*
  Pura gente del Coach Moy

  0                   1             2
  {n = 0, 2, 4 mod 6} {n = 3 mod 6} {n = 1, 5 mod 6}
  n / 2               n / 6         n / 3

  2 0 0 2 0 0 2 0 0 -> Hasta que me quede sin 2 o sin 0, 2 se reduce en n / 4, Queda n / 12
  2 1 1 2 1 1 2 1 1 -> Hasta que me quede sin 2 o sin 1, 2 se reduce en n / 12, Queda 0
  Imprimir lo que quede en 0, 1, 2. Como todo es mod 6 entonces a lo mucho hay 5 errores
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int _t = 0; _t < t; _t++){
    int n; cin >> n;

    queue<int> a[3];

    for(int i = 1; i <= n; i++){
      if(i % 2 == 0) a[0].push(i);
      else if(i % 3 == 0) a[1].push(i);
      else a[2].push(i);
    }

    for(int i = 0; i < 2; i++){
      while((int)size(a[2]) > 1 && (int)size(a[i]) > 2){
        cout << a[2].front() << ' '; a[2].pop();
        cout << a[i].front() << ' '; a[i].pop();
        cout << a[i].front() << ' '; a[i].pop();
      }
    }

    for(int i = 0; i < 3; i++) while(!a[i].empty()){ cout << a[i].front() << ' '; a[i].pop(); }

    cout << '\n';
  }

  return 0;
}