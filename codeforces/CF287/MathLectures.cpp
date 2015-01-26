#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int MAX_N = 1005;
ll dp[MAX_N][105];
ll powm[MAX_N], powk[MAX_N];
int n, m, k;

int solve(int pos, int rem, bool nonzero) {
    if (rem == 0 && nonzero) {
        // the number is already fixed, only this one feasible choice
        if (pos == 0) return 1;
        else return (powm[pos - 1] * 9) % m;
    }
    if (pos == 0) return 0;
    if (dp[pos][rem] != -1) return dp[pos][rem];
    ll cur = 0;
    FOR(i, 10) { cur += solve(pos - 1, (rem + i * powk[n - pos]) % k, nonzero | (i > 0)); cur %= m; }
    dp[pos][rem] = cur;
    return dp[pos][rem];
}

int main() {
    scanf("%d %d %d", &n, &k, &m);
    memset(dp, -1, sizeof(dp));
    powm[0] = 1;
    for (int i = 1; i < MAX_N; ++i) powm[i] = (powm[i - 1] * 10) % m;
    powk[0] = 1 % k;
    for (int i = 1; i < MAX_N; ++i) powk[i] = (powk[i - 1] * 10) % k;
    int res = solve(n, 0, false);
    printf("%d\n", res);
    return 0;
}
