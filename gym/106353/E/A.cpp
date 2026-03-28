/*
  Pura gente del Coach Moy  
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll ncr(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;
    ll res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    vector<int> colours(3, 0);
    for (int i = 0; i < n; i++) {
        char color; cin >> color;
        if (color == 'r') colours[0]++;
        else if (color == 'g') colours[1]++;
        else if (color == 'b') colours[2]++;
    }

    sort(colours.begin(), colours.end());

    if (colours[0] == 0) {
        double ans = 3.0 * min(colours[1], colours[2]);
        cout << fixed << setprecision(6) << ans << "\n";
        return 0;
    }

    ll acc = 0;
    for (int i = 0; i <= colours[0]; i++) {
        ll hp = ncr(colours[0], i);
        hp *= 3 * min(colours[1], colours[2] + (colours[0] - i));
        acc += hp;
    }

    ll total = power(2, colours[0]);

    double ans = (1.5 * colours[0]) + ((double)acc / total);

    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}