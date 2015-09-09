#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
char g[2002][2002];
int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    FOR(i, row) scanf("%s", &g[i]);
    vector<vector<int> > dp(row, vector<int>(col, 1));
    int res = 0;
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (g[i][j] == g[i - 1][j - 1] && g[i][j] != g[i][j - 1] && g[i][j] != g[i - 1][j]) {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
            if (dp[i][j] >= 32 && g[i][j] == '_') {
                ++res;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
