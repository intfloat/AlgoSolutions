#include <algorithm>
#include <iostream>
#include <cstdio>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
using namespace std;
string sa, sb;
const ll MOD = (ll)(1e9 + 7);
const int MAX_N = 1005;
int dp[MAX_N][MAX_N];
ll res[MAX_N][MAX_N];
inline void solve() {
    cin >> sa >> sb;
    int na = sa.size(), nb = sb.size();
    for (int i = 0; i <= nb; ++i) {
        dp[0][i] = 0;
        res[0][i] = 1;
    }
    for (int i = 0; i <= na; ++i) {
        dp[i][0] = 0;
        res[i][0] = 1;
    }
    int pv[26];
    for (int i = 1; i <= na; ++i) {
        FOR(i, 26) pv[i] = -1;
        for (int j = 1; j <= nb; ++j) {
            if (sa[i - 1] == sb[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            res[i][j] = 0;
            if (dp[i - 1][j] == dp[i][j]) {
                res[i][j] = (res[i][j] + res[i - 1][j]) % MOD;
            }
            pv[sb[j - 1] - 'a'] = j - 1;
            int idx = pv[sa[i - 1] - 'a'];
            if (idx >= 0 && dp[i - 1][idx] + 1 == dp[i][j]) {
                res[i][j] = (res[i][j] + res[i - 1][idx]) % MOD;
            }
        }
    }
    cout << res[na][nb] << endl;
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        solve();
    }
    return 0;
}
