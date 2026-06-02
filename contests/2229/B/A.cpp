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

		vector<ll> a(n); for(ll & x : a) cin >> x;
		vector<ll> b(n); for(ll & x : b) cin >> x;

		ll ans = 0, aux = -1;
		for(int i = 0; i < n; i++)
			ans += max(a[i], b[i]), aux = max(aux, min(a[i], b[i]));

		cout << ans + aux << '\n';
	}
	
	return 0;
}