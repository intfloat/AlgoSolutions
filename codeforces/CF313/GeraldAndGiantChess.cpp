#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
const ll MOD = (ll)(1e9 + 7);
const int MAX_N = 200005;
vector<ll> fac(MAX_N), inv(MAX_N);
inline ll pw(ll num, ll p) {
    if (p == 0) return 1ll;
    if (p == 1) return num % MOD;
    ll ret = pw(num, p / 2);
    ret = (ret * ret) % MOD;
    if (p % 2) {
        ret = (ret * num) % MOD;
    }
    return ret;
}
inline void preprocess() {
    fac[0] = 1;
    for (ll i = 1; i < fac.size(); ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    for (ll i = 0; i < inv.size(); ++i) {
        inv[i] = pw(fac[i], MOD - 2ll);
    }
}
inline ll get(int r, int c) {
    return (((fac[r + c] * inv[r]) % MOD) * inv[c]) % MOD;;
}
int main() {
    int row, col, n;
    preprocess();
    scanf("%d %d %d", &row, &col, &n);
    vector<point> black(n);
    FOR(i, n) {
        scanf("%d %d", &black[i].first, &black[i].second);
    }
    black.push_back({row, col});
    sort(black.begin(), black.end());
    vector<ll> dp(n + 1);
    for (int i = 0; i < black.size(); ++i) {
        ll tot = get(black[i].first - 1, black[i].second - 1);
        for (int j = 0; j < i; ++j) {
            if (black[j].second <= black[i].second) {
                ll t = dp[j] * get(black[i].first - black[j].first, black[i].second - black[j].second);
                tot = (tot - t % MOD) % MOD;
                tot = (tot + MOD) % MOD;
            }
        }
        dp[i] = tot;
    }
    cout << dp[n] << endl;
    return 0;
}
