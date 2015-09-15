#include <stdio.h>
#include <string.h>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int MAX_N = 100005;
char a[MAX_N], b[MAX_N];
int dp[MAX_N][16];
inline void preprocess() {
    memset(dp, 0, sizeof dp);
    FOR(i, 10) dp[0][i] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        FOR(j, 16) FOR(k, 10) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j ^ k]) % MOD;
        }
    }
}
inline ll get(char* s) {
    int sz = strlen(s);
    ll ret = 0;
    int pv = 0;
    for (int i = 0; i < sz; ++i) {
        int idx = sz - 1 - i;
        if (idx == 0) {
            FOR(k, s[i] - '0' + 1) {
                ret = (ret + (pv ^ k)) % MOD;
            }
            continue;
        }
        FOR(k, s[i] - '0') FOR(j, 16) {
            ret = (ret + (ll)dp[idx - 1][j] * (ll)(k ^ j ^ pv)) % MOD;
        }
        pv ^= (s[i] - '0');
    }
    return ret;
}
inline ll solve() {
    scanf("%s %s", a, b);
    ll res = (get(b) - get(a)) % MOD;
    res = (res + MOD) % MOD;
    int extra = 0;
    for (int i = 0; a[i]; ++i) {
        extra = extra ^ (a[i] - '0');
    }
    res = (res + extra) % MOD;
    return res;
}
int main() {
    int T;
    scanf("%d", &T);
    preprocess();
    FOR(i, T) {
        printf("Case #%d: %lld\n", i + 1, solve());
    }
    return 0;
}
