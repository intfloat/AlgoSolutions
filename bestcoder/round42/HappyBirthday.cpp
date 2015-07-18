#include <stdio.h>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
bool dp[101][101][101];
int g[101][101];
int row, col, K;
void solve() {
    FOR(r, row) FOR(c, col) scanf("%d", &g[r][c]);
    FOR(r, row) FOR(c, col) FOR(k, K + 1) dp[r][c][k] = false;
    dp[0][0][0] = true;
    if (g[0][0] <= K) dp[0][0][g[0][0]] = true;
    FOR(r, row) FOR(c, col) FOR(k, K + 1) {
        if (r == 0 && c == 0) break;
        if (r == 0) {
            dp[r][c][k] = dp[r][c - 1][k];
            if (k >= g[r][c]) dp[r][c][k] |= dp[r][c - 1][k - g[r][c]];
        }
        else if (c == 0) {
            dp[r][c][k] = dp[r - 1][c][k];
            if (k >= g[r][c]) dp[r][c][k] |= dp[r - 1][c][k - g[r][c]];
        }
        else {
            dp[r][c][k] = dp[r - 1][c][k] || dp[r][c - 1][k];
            if (k >= g[r][c]) dp[r][c][k] |= dp[r - 1][c][k - g[r][c]] || dp[r][c - 1][k - g[r][c]];
        }
    }
    for (int k = K; k >= 0; --k) {
        if (dp[row - 1][col - 1][k]) {
            printf("%d\n", k);
            return;
        }
    }
    return;
}
int main() {
    while (scanf("%d %d %d", &row, &col, &K) != EOF) solve();
    return 0;
}
