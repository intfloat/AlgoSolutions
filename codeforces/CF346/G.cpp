#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 7);
int main() {
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    FOR(i, n) scanf("%d", &h[i]);
    vector<ll> dp(n), dpr(n);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = h[i] - 1;
        if (i - 1 >= 0 && h[i - 1] <= h[i]) {
            ll tmp = (h[i - 1] - 1) * dp[i - 1];
            tmp %= MOD;
            dp[i] = (dp[i] + tmp) % MOD;
        }
        else if (i - 1 >= 0 && h[i - 1] > h[i]) {
            ll tmp = (h[i] - 1) * dpr[i - 1];
            tmp %= MOD;
            dp[i] = (dp[i] + tmp) % MOD;
        }
        if (i + 1 < n && h[i] <= h[i + 1]) {
            dpr[i] = 0;
        }
        else if (i + 1 < n && h[i] > h[i + 1]) {
            dpr[i] = h[i + 1] - 1;
            if (i - 1 >= 0 && h[i - 1] >= h[i + 1] && h[i - 1] <= h[i]) {
                ll tmp = (h[i + 1] - 1) * dp[i - 1];
                tmp %= MOD;
                dpr[i] = (dpr[i] + tmp) % MOD;
            }
            else if (i - 1 >= 0 && h[i - 1] > h[i]) {
                ll tmp = (h[i + 1] - 1) * dpr[i - 1];
                tmp %= MOD;
                dpr[i] = (dpr[i] + tmp) % MOD;
            }
            else if (i - 1 >= 0 && h[i - 1] < h[i + 1]) {
                ll tmp = (h[i - 1] - 1) * dp[i - 1];
                tmp %= MOD;
                dpr[i] = (dpr[i] + tmp) % MOD;
            }
        }
        res = (res + dp[i]) % MOD;
    }
    cout << res << endl;
    return 0;
}
