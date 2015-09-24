#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> w(K);
    FOR(i, K) scanf("%d", &w[i]);
    vector<bool> ok(N + 1, false);
    ok[0] = true;
    FOR(i, K) {
        for (int j = w[i]; j <= N; ++j) {
            ok[j] = (ok[j] || ok[j - w[i]]);
        }
    }
    ll dp[1005][2];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1; dp[0][1] = 0;
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        for (int j = 1; j <= i; ++j) {
            if (ok[j]) {
                dp[i][1] = (dp[i][1] + dp[i - j][0]) % MOD;
            }
        }
    }
    ll res = (dp[N][0] + dp[N][1]) % MOD;
    cout << res << endl;
    return 0;
}
