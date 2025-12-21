#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	vector<string>g(n);
	for(int i=0; i<n; i++) cin >> g[i];
	vector<vector<int>>xd(n,vector<int>(m,0));
	int ans = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(i==0) {
				if(g[i][j] == 'B') xd[i][j] = 1;
				else xd[i][j] = 0;
			} else {
				int left = (j == 0 ? 0 : xd[i - 1][j - 1]);
				int mid = xd[i - 1][j];
				int right = (j == m - 1 ? 0 : xd[i - 1][j + 1]);

				if(g[i][j]=='W') {
					xd[i][j] = max({left, mid, right});
					ans = max(ans,xd[i][j]);
					xd[i][j]=0;
				} else {
					xd[i][j] = max({left, mid, right});
					if(g[i][j]=='B') xd[i][j]++;
				}
			}
		}
	}
	//for(int i=0;i<n;i++){ for(int j=0;j<m;j++){ cout<<xd[i][j]<<" ";} cout<<'\n';}
	cout<<ans<<'\n';
	return 0;
}
