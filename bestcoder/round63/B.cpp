#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 1005;
int g[MAX_N][MAX_N], dp[MAX_N][MAX_N];
int main() {
    int row, col;
    while (scanf("%d %d", &row, &col) != EOF) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                scanf("%d", &g[i][j]);
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i < row; ++i) {
            if (i % 2) dp[i][0] = dp[i - 1][0] + g[i][0] * g[i - 1][0];
            else dp[i][0] = dp[i - 1][0];
        }
        for (int i = 1; i < col; ++i) {
            if (i % 2) dp[0][i] = dp[0][i - 1] + g[0][i] * g[0][i - 1];
            else dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if ((i + j) % 2) {
                    dp[i][j] = min(dp[i - 1][j] + g[i - 1][j] * g[i][j],
                                    dp[i][j - 1] + g[i][j - 1] * g[i][j]);
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%d\n", dp[row - 1][col - 1]);
    }
    return 0;
}
