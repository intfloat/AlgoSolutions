#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;
int dp[155][12005];
const int INF = INT_MAX / 2;
int main() {
    int n, k, s;
    scanf("%d %d %d", &n, &k, &s);
    vector<int> arr(n);
    s = min(s, 12000);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        for (int j = s; j >= 0; --j) {
            for (int p = min(k, i + 1); p > 0; --p) {
                if (j - (i - p + 1) >= 0) {
                    dp[p][j] = min(dp[p][j], arr[i] + dp[p - 1][j - (i - p + 1)]);
                }
            }
        }
    }
    int res = INF;
    for (int i = 0; i <= s; ++i) {
        res = min(res, dp[k][i]);
    }
    printf("%d\n", res);
    return 0;
}
