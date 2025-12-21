#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long ORall = 0;
        for (auto v : a) ORall |= v;
        int base_bits = __builtin_popcountll(ORall);

        // Precompute cost for each bit
        vector<long long> cost(31, LLONG_MAX);
        for (int bit = 0; bit < 31; bit++) {
            if (ORall & (1LL << bit)) {
                cost[bit] = 0; // already set
                continue;
            }
            long long mask = (1LL << (bit+1));
            for (auto v : a) {
                long long rem = v % mask;
                if (rem & (1LL << bit)) { 
                    cost[bit] = 0;
                    break;
                } else {
                    long long need = (1LL << bit) - (rem % (1LL << bit));
                    cost[bit] = min(cost[bit], need);
                }
            }
        }

        // Collect only unset bits with nonzero cost
        vector<long long> buy;
        for (int bit = 0; bit < 31; bit++) {
            if ((ORall & (1LL << bit)) == 0 && cost[bit] < LLONG_MAX) {
                buy.push_back(cost[bit]);
            }
        }
        sort(buy.begin(), buy.end());

        // Prefix sums
        vector<long long> pref(buy.size()+1,0);
        for (int i = 0; i < (int)buy.size(); i++) {
            pref[i+1] = pref[i] + buy[i];
        }

        while (q--) {
            long long b; cin >> b;
            int extra = upper_bound(pref.begin(), pref.end(), b) - pref.begin() - 1;
            cout << base_bits + extra << "\n";
        }
    }
}
