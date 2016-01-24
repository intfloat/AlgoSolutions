#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 3005;
long double c[MAX_N][MAX_N];
long double dp[MAX_N];
inline void solve() {
    int N, K;
    double p;
    cin >> N >> K >> p;
    if (K > N) {
        printf("0\n");
        return;
    }
    FOR(j, N + 1) c[0][j] = 0;
    c[0][0] = 1.0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (i < j) c[i][j] = 0;
            else c[i][j] = p * c[i - 1][j - 1] + (1.0 - p) * c[i - 1][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            c[i][j] += c[i][j + 1];
        }
    }
    memset(dp, 0, sizeof dp);
    FOR(i, N + 1) {
        dp[i] = 0;
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], c[j][K] + dp[i - j]);
        }
    }
    printf("%.15lf\n", (double)dp[N]);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
