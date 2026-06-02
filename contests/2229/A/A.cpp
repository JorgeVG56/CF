#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;
const ll mod = 1e9 + 7;

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;

	for(int _t = 0; _t < t; _t++){
		int n; cin >> n;

		vector<int> a(n); for(int & x : a) cin >> x;

		int mn = *min_element(begin(a), end(a)), mx = *max_element(begin(a), end(a));;

		cout << (mx - mn + 1) / 2 << '\n';
	}
	
	return 0;
}