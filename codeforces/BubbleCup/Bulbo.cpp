#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = (ll)1e14;
inline ll get(ll x, ll l, ll r) {
    return (x < l)? (l - x): max(0ll, x - r);
}
int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    vector<pii> arr(n);
    vector<int> pos(1, x);
    FOR(i, n) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
        pos.push_back(arr[i].first);
        pos.push_back(arr[i].second);
    }
    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
    int sz = pos.size();
    vector<vector<ll> > dp(2, vector<ll>(sz, INF));
    int ss = lower_bound(pos.begin(), pos.end(), x) - pos.begin();
    dp[1][ss] = 0;
    ll res = INF;
    for (int i = 0; i < n; ++i) {
        bool ptr = (i % 2);
        // scan from left to right
        ll opt = INF;
        for (int j = 0; j < sz; ++j) {
            dp[ptr][j] = min(opt, dp[!ptr][j]);
            if (j + 1 < sz) {
                opt = dp[ptr][j] + (pos[j + 1] - pos[j]);
            }
        }
        // scan from right to left
        opt = INF;
        for (int j = sz - 1; j >= 0; --j) {
            ll tmp = opt;
            if (j - 1 >= 0) {
                opt = min(opt, dp[!ptr][j]) + (pos[j] - pos[j - 1]);
            }
            dp[ptr][j] = min(dp[ptr][j], min(tmp, dp[!ptr][j]));
        }
        for (int j = 0; j < sz; ++j) {
            dp[ptr][j] += get(pos[j], arr[i].first, arr[i].second);
        }
        if (i + 1 == n) {
            res = *min_element(dp[ptr].begin(), dp[ptr].end());
        }
    }
    cout << res << endl;
    return 0;
}
