#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
vector<vector<ll> > dp(18, vector<ll>(1 << 18));
int main() {
    int rule[18][18], x, y, c;
    memset(rule, 0, sizeof rule);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> satis(n);
    FOR(i, n) scanf("%d", &satis[i]);
    FOR(i, k) {
        scanf("%d %d %d", &x, &y, &c);
        --x; --y;
        rule[x][y] = c;
    }
    ll res = 0;
    FOR(status, 1 << n) FOR(i, n) {
        if (!(status & (1 << i))) continue;
        int bits = __builtin_popcount(status);
        if (bits > m) continue;
        int ns = status - (1 << i);
        dp[i][status] = satis[i];
        FOR(j, n) {
            if (!(ns & (1 << j))) continue;
            dp[i][status] = max(dp[i][status], satis[i] + dp[j][ns] + rule[j][i]);
        }
        if (bits == m) {
            res = max(res, dp[i][status]);
        }
    }
    cout << res << endl;
    return 0;
}
