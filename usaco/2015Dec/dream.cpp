#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = INT_MAX / 2;
const int RED = 0, PINK = 1, ORANGE = 2, BLUE = 3, PURPLE = 4;
int dp[1005][1005][2][4], row, col, g[1005][1005];
const int dir_x[] = {0, 1, 0, -1};
const int dir_y[] = {1, 0, -1, 0};
int solve(int r, int c, bool smell, int d) {
    if (dp[r][c][smell][d] >= 0) return dp[r][c][smell][d];
    int& ret = dp[r][c][smell][d];
    ret = INF;
    if (g[r][c] == RED) return ret;
    if (g[r][c] == BLUE && !smell) return ret;
    if (r == row - 1 && c == col - 1) {
        ret = 0; return ret;
    }
    if (g[r][c] == PURPLE) {
        int nr = r + dir_x[d], nc = c + dir_y[d];
        if (nr >= 0 && nr < row && nc >= 0 && nc < col && g[nr][nc] != RED && g[nr][nc] != BLUE) {
            ret = min(INF, solve(nr, nc, false, d) + 1);
            return ret;
        }
    }
    FOR(i, 4) {
        int nr = r + dir_x[i], nc = c + dir_y[i];
        if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
        if (g[r][c] == PINK) {
            ret = min(ret, solve(nr, nc, smell, i) + 1);
        }
        else if (g[r][c] == ORANGE) {
            ret = min(ret, solve(nr, nc, true, i) + 1);
        }
        else if (g[r][c] == BLUE) {
            ret = min(ret, solve(nr, nc, smell, i) + 1);
        }
        else if (g[r][c] == PURPLE) {
            if (d != i) ret = min(ret, solve(nr, nc, false, i) + 1);
        }
    }
    return ret;
}
int main() {
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    scanf("%d %d", &row, &col);
    memset(dp, -1, sizeof dp);
    FOR(i, row) FOR(j, col) {
        scanf("%d", &g[i][j]);
    }
    int res = solve(0, 0, false, 0);
    if (res >= INF) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}
