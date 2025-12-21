#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node{
  int id, parent, totalSons, alive;
  queue<int> sons;

  Node(int id, int parent){
    totalSons = 0;
    alive = 1;
    this->id = id;
    this->parent = parent;
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int q; cin >> q;
  vector<Node> a; a.push_back({0, -1}); a.push_back({1, 0});

  int currentMonarch = 1;

  for(int i = 0; i < q; i++){
    int t, x; cin >> t >> x;

    if(t == 1){
      a[x].sons.push((int)a.size());
      
      int aux = x;
      while(aux != -1){
        a[aux].totalSons++;
        aux = a[aux].parent;
      }

      a.push_back({(int)a.size(), x});
    } else{
      a[x].alive = 0;
      
      int aux = a[x].parent;
      while(aux != -1){
        a[aux].totalSons--;
        aux = a[aux].parent;
      }

      if(currentMonarch == x){
        while(a[currentMonarch].totalSons == 0){
          currentMonarch = a[currentMonarch].parent;
        }

        while(a[currentMonarch].alive == 0){
          while(a[a[currentMonarch].sons.front()].totalSons == 0 && a[a[currentMonarch].sons.front()].alive == 0){
            a[currentMonarch].sons.pop();
          }

          currentMonarch = a[currentMonarch].sons.front();
        }
      }

      cout << currentMonarch << '\n';
    }
  }

  return 0;
}