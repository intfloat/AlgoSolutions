#include <stdio.h>
#include <vector>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
inline void solve() {
    int n, p, q;
    scanf("%d %d %d", &n, &p, &q);
    double p1 = 1.0 * q / p;
    double p0 = 1.0 - p1;
    vector<vector<double> > dp(n + 1, vector<double>(n + 1, 0));
    vector<double> pw(n + 1), zero(n + 1);
    pw[0] = 1.0; zero[0] = 1.0;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * p1;
        zero[i] = zero[i - 1] * p0;
    }
    FOR(i, n + 1) dp[0][i] = 1.0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = zero[i]; dp[i][i] = 1.0;
        for (int j = 1; j < i; ++j) {
            if (j + 1 == i) {
                dp[i][j] = 1.0 - pw[i];
                continue;
            }
            dp[i][j] = p0 * dp[i - 1][j] + p1 * (dp[i - 1][j] - pw[j] * p0 * dp[i - 2 - j][j]);
        }
        for (int j = i + 1; j <= n; ++j) dp[i][j] = 1.0;
    }
    double res = 0;
    for (int i = 1; i <= n; ++i) {
        res += (dp[n][i] - dp[n][i - 1]) * i;
    }
    printf("%.3lf\n", res + 1.0);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
