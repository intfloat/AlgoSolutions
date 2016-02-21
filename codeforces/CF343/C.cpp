#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
const int MAX_N = 2005;
ll dp[MAX_N][MAX_N];
void preprocess() {
    dp[0][0] = 1;
    for (int i = 1; i <= 2000; ++i) {
        dp[i][i] = 1;
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j < i; ++j) {
            dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % MOD;
        }
    }
}
int main() {
    preprocess();
    int n, m;
    char s[100005];
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    int lcnt = 0, rcnt = 0, mx = 0;
    FOR(i, m) {
        if (s[i] == '(') {
            ++lcnt;
        }
        else {
            ++rcnt;
            mx = max(mx, rcnt - lcnt);
        }
    }
    ll res = 0;
    FOR(i, n - m + 1) {
        FOR(j, i + 1) {
            if (j < mx) continue;
            int diff = j + lcnt - rcnt;
            if (diff < 0 || diff > n - m - i) continue;
            res = (res + (dp[i][j] * dp[n - m - i][diff]) % MOD) % MOD;
        }
    }
    cout << res << endl;
    return 0;
}
