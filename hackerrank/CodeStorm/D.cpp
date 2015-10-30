#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1005;
vector<int> dp(MAX_N);
void preprocess() {
    dp[1] = 0;
    dp[2] = 0;
    for (int i = 3; i < (int)dp.size(); ++i) {
        if (i % 2) {
            dp[i] = (dp[i - 1] + 1) % i;
        }
        else {
            if (dp[i - 1] <= i / 2 - 2) {
                dp[i] = (dp[i - 1] + 1) % i;
            }
            else dp[i] = (dp[i - 1] + 2) % i;
        }
    }
}
inline void solve() {
    ll n;
    scanf("%lld", &n);
    if (n < 10) printf("%d\n", dp[n] + 1);
    else {
        ll low = 5ll, up = 4 * low + 1;
        while (n > up) {
            low = up;
            up = 4ll * low + 1ll;
        }
        if (n == low) printf("%lld\n", n);
        else if (n <= 2ll * low) printf("%lld\n", n - low);
        else {
            ll y = n - 2ll * low;
            printf("%lld\n", low + y / 2 * 3 + (y % 2));
        }
    }
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
