#include <stdio.h>
#include <utility>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int, int> pii;
char g[105][105];
int dp[105][105];
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    pii start;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < row; ++i) {
        scanf("%s", g[i]);
        for (int j = 0; j < col; ++j) {
            if (g[i][j] == 'H') {
                start = make_pair(i, j);
            }
        }
    }
    queue<pii> q;
    dp[start.first][start.second] = 0;
    q.push(start);
    while (!q.empty()) {
        pii tp = q.front(); q.pop();
        int cur = dp[tp.first][tp.second];
        for (int i = 0; i < 4; ++i) {
            int nr = tp.first + dir_x[i];
            int nc = tp.second + dir_y[i];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == '#' || g[nr][nc] == 'P') continue;
            if (dp[nr][nc] != -1) continue;
            dp[nr][nc] = cur + 1;
            if (g[nr][nc] == '.') {
                q.push(make_pair(nr, nc));
            }
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < row; ++i) for (int j = 0; j < col; ++j) {
        if (g[i][j] != 'S' || dp[i][j] == -1) continue;
        for (int k = 0; k < 4; ++k) {
            int nr = i + dir_x[k], nc = j + dir_y[k];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] != 'S' || dp[nr][nc] == -1) continue;
            res = min(res, dp[i][j] + dp[nr][nc]);
        }
    }
    if (res == INT_MAX) printf("Hi and Ho will not have lunch.\n");
    else printf("%d\n", res);
    return 0;
}
