#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1000005;
const ll MOD = 1000000007;
vector<bool> win(MAX_N);
vector<int> cnt(MAX_N, 0);
vector<vector<ll> > dp(2, vector<ll>(MAX_N));
vector<ll> ptwo(MAX_N);
void preprocess() {
    ptwo[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        ptwo[i] = (ptwo[i - 1] * 2ll) % MOD;
    }
    FOR(i, 10) {
        win[i] = false;
    }
    for (int i = 10; i < MAX_N; ++i) {
        win[i] = false;
        int low = 1, up = 10;
        while (i >= up) {
            int x = (i / low) % 10;
            int y = (i / up) % 10;
            int r = (x + y) % 10;
            int num = i % low + r * low + (i / (up * 10)) * up;
            if (!win[num]) {
                win[i] = true;
                break;
            }
            low *= 10;
            up *= 10;
        }
        cnt[i] = win[i] + cnt[i - 1];
        // if (win[i] != win[i - 1]) {
        //     if(win[i]) printf("win: %d\n", i);
        //     else printf("lose: %d\n", i);
        // }
    }
    dp[0][0] = 1, dp[1][0] = 0;
    for (int i = 1; i < MAX_N; ++i) {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
        dp[1][i] = (dp[1][i - 1] + dp[0][i - 1]) % MOD;
    }
}
inline void solve() {
    int n, m, x;
    scanf("%d %d", &n, &m);
    int ones = cnt[n], zeros = n - cnt[n], tot = 0;
    FOR(i, m) {
        scanf("%d", &x);
        if (win[x]) --ones;
        else --zeros;
        tot += win[x];
    }
    ll res = 0;
    if (tot % 2) {
        res = (dp[1][ones] * ptwo[zeros]) % MOD;
    }
    else {
        res = (dp[0][ones] * ptwo[zeros]) % MOD;
        res = (res - 1 + MOD) % MOD;
    }
    printf("%lld\n", res);
}
int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
