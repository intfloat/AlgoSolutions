#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
double dp[105][101005];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(n + 1);
    FOR(i, n) {
        scanf("%d", &arr[i + 1]);
    }
    if (m == 1) {
        printf("%d\n", 1);
        return 0;
    }
    FOR(i, n + 1) FOR(j, m * n + 1) {
        dp[i][j] = 0;
    }
    const double den = 1.0 / (m - 1);
    for (int j = 1; j <= m; ++j) {
        if (j == arr[1]) dp[1][j] = 0;
        else dp[1][j] = den;
    }
    for (int j = 1; j <= 2 * m; ++j) {
        dp[1][j] += dp[1][j - 1];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= i * m; ++j) {
            int up = min(m, j - 1);
            dp[i][j] = dp[i - 1][j - 1] - dp[i - 1][j - up - 1];
            if (arr[i] <= up) {
                dp[i][j] -= dp[i - 1][j - arr[i]] - dp[i - 1][j - arr[i] - 1];
            }
            dp[i][j] *= den;
        }
        for (int j = i; j <= i * m + m; ++j) {
            dp[i][j] += dp[i][j - 1];
        }
    }
    int score = accumulate(arr.begin() + 1, arr.end(), 0);
    double res = dp[n][score - 1] * (m - 1) + 1.0;
    printf("%.10lf\n", res);
    return 0;
}
