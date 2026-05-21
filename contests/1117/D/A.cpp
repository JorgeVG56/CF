#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;
const ll mod = 1e9 + 7;

vector<vector<ll>> mul(vector<vector<ll>> & a, vector<vector<ll>> & b){
	vector<vector<ll>> c(size(a), vector<ll>(size(a)));
	for(ll i = 0; i < size(a); i++)
		for(ll j = 0; j < size(a); j++)
			for(ll k = 0; k < size(a); k++)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j] % mod) % mod;
	return c;
}

vector<vector<ll>> binPow(vector<vector<ll>> & a, ll b){
	vector<vector<ll>> res(size(a), vector<ll>(size(a)));
	for(ll i = 0; i < size(a); i++) res[i][i] = 1;
	while(b){
		if(b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	ll n, m; cin >> n >> m;
	
	vector<ll> a(m); a[0] = 1;
	vector<vector<ll>> b(m, vector<ll>(m)); b[0][0] = 1;
	for(ll i = 0; i < m; i++) b[i][(i + m - 1) % m] = 1;
	vector<vector<ll>> res = binPow(b, n);

	cout << res[0][0] << '\n';
	
	return 0;
}