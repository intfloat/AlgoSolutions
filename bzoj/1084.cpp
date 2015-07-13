#include <stdio.h>
#include <string.h>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    if (m == 1) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int dp[105][11][2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j][0] = dp[i][j][1] = (int)-1e8;
            }
        }
        dp[0][0][0] = 0;
        dp[0][1][1] = arr[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
                if (j >= 1) {
                    dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j][1]) + arr[i];
                }
            }
        }
        printf("%d\n", max(dp[n - 1][k][0], dp[n - 1][k][1]));
        return 0;
    }
    vector<vector<int> > arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    int dp[105][11][5];
    // 0: empty, 1: only left full
    // 2: only right full, 3: left + right full as one
    // 4: left + right full as two
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int s = 0; s < 5; ++s) {
                dp[i][j][s] = (int)-1e8;
            }
        }
    }
    dp[0][0][0] = 0;
    dp[0][1][1] = arr[0][0];
    dp[0][1][2] = arr[0][1];
    dp[0][1][3] = arr[0][0] + arr[0][1];
    dp[0][2][4] = arr[0][0] + arr[0][1];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j][0] = *max_element(dp[i - 1][j], dp[i - 1][j] + 5);
            if (j >= 1) {
                int val[] = {dp[i - 1][j - 1][0], dp[i - 1][j][1],
                           dp[i - 1][j - 1][2], dp[i - 1][j - 1][3], dp[i - 1][j][4]};
                dp[i][j][1] = *max_element(val, val + 5) + arr[i][0];
            }
            if (j >= 1) {
                int val[] = {dp[i - 1][j - 1][0], dp[i - 1][j - 1][1],
                           dp[i - 1][j][2], dp[i - 1][j - 1][3], dp[i - 1][j][4]};
                dp[i][j][2] = *max_element(val, val + 5) + arr[i][1];
            }
            if (j >= 1) {
                int val[] = {dp[i - 1][j - 1][0], dp[i - 1][j - 1][1],
                             dp[i - 1][j - 1][2], dp[i - 1][j][3], dp[i - 1][j - 1][4]};
                dp[i][j][3] = *max_element(val, val + 5) + arr[i][0] + arr[i][1];
            }
            if (j >= 2) {
                int val[] = {dp[i - 1][j - 2][0], dp[i - 1][j - 1][1],
                             dp[i - 1][j - 1][2], dp[i - 1][j - 2][3], dp[i - 1][j][4]};
                dp[i][j][4] = *max_element(val, val + 5) + arr[i][0] + arr[i][1];
            }
        }
    }
    printf("%d\n", *max_element(dp[n - 1][k], dp[n - 1][k] + 5));
    return 0;
}
