#include <stdio.h>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 100005;
double dp[MAX_N][10][2], res[MAX_N];
void preprocess() {
    memset(dp, 0, sizeof dp);
    memset(res, 0, sizeof res);
    FOR(i, 10) dp[2][i][0] = dp[2][i][1] = 1;
    dp[2][0][0] = dp[2][9][1] = 0;
    for (int i = 2; i < MAX_N - 1; ++i) FOR(j, 10) {
        for (int k = 0; k < 10; ++k) {
            if (j == k) continue;
            if (k < j) {
                dp[i + 1][k][1] += ((9.0 - j) / 9.0 * dp[i][j][1] + j / 9.0 * (dp[i][j][0] + 1)) / (9 - k);
            }
            else {
                dp[i + 1][k][0] += (j / 9.0 * dp[i][j][0] + (9.0 - j) / 9.0 * (dp[i][j][1] + 1)) / k;
            }
        }
    }
    for (int i = 2; i < MAX_N; ++i) {
        for (int j = 0; j < 10; ++j) {
            res[i] += (1.0 / 10) * (dp[i][j][0] * j / 9.0 + dp[i][j][1] * (9 - j) / 9.0);
        }
    }
    return;
}
int main() {
    int T, N;
    preprocess();
    scanf("%d", &T);
    FOR(tt, T) {
        scanf("%d", &N);
        printf("Case #%d:\n", tt + 1);
        if (N == 1) printf("1 1\n");
        else printf("%.6f %.6f\n", res[N], (N + res[N] - 1) / res[N]);
    }
    return 0;
}
