#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
char g[1005][1005];
int dp[1005][1005][4], dp2[1005][1005][4];
int row, col;
inline bool check(int val) {
    FOR(i, row + 2) FOR(j, col + 2) FOR(k, 4) {
        if (dp[i][j][k] >= val) dp2[i][j][k] = val;
        else dp2[i][j][k] = 0;
    }
    for (int i = row; i >= 1; --i) {
        for (int j = col; j >= 1; --j) {
            if (g[i][j] == '#') {
                dp2[i][j][0] = max(dp2[i][j][0], max(dp2[i + 1][j][0], dp2[i][j + 1][0]) - 1);
            }
        }
    }
    for (int i = row; i >= 1; --i) {
        for (int j = 1; j <= col; ++j) {
            if (g[i][j] == '#') {
                dp2[i][j][1] = max(dp2[i][j][1], max(dp2[i + 1][j][1], dp2[i][j - 1][1]) - 1);
            }
        }
    }
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if (g[i][j] == '#') {
                dp2[i][j][2] = max(dp2[i][j][2], max(dp2[i - 1][j][2], dp2[i][j - 1][2]) - 1);
            }
        }
    }
    for (int i = 1; i <= row; ++i) {
        for (int j = col; j >= 1; --j) {
            if (g[i][j] == '#') {
                dp2[i][j][3] = max(dp2[i][j][3], max(dp2[i - 1][j][3], dp2[i][j + 1][3]) - 1);
            }
        }
    }
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if (g[i][j] == '#') {
                bool ok = false;
                FOR(k, 4) {
                    if (dp2[i][j][k] > 0) { ok = true; break; }
                }
                if (!ok) return false;
            }
        }
    }
    return true;
}
int main() {
    memset(g, '\0', sizeof g);
    scanf("%d %d", &row, &col);
    for (int i = 1; i <= row; ++i) {
        scanf("%s", g[i] + 1);
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if (g[i][j] == '#') {
                dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + 1;
            }
        }
    }
    for (int i = 1; i <= row; ++i) {
        for (int j = col; j >= 1; --j) {
            if (g[i][j] == '#') {
                dp[i][j][1] = min(dp[i - 1][j][1], dp[i][j + 1][1]) + 1;
            }
        }
    }
    for (int i = row; i >= 1; --i) {
        for (int j = col; j >= 1; --j) {
            if (g[i][j] == '#') {
                dp[i][j][2] = min(dp[i + 1][j][2], dp[i][j + 1][2]) + 1;
            }
        }
    }
    for (int i = row; i >= 1; --i) {
        for (int j = 1; j <= col; ++j) {
            if (g[i][j] == '#') {
                dp[i][j][3] = min(dp[i + 1][j][3], dp[i][j - 1][3]) + 1;
            }
        }
    }
    int l = 1, r = min(row, col);
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    if (l + 1 == r && check(r)) printf("%d\n", r);
    else printf("%d\n", l);
    return 0;
}
