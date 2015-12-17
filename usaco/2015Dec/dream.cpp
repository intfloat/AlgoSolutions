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
struct Node {
    int r, c;
    bool smell;
    int d;
    Node(int _r, int _c, bool _s, int _d): r(_r), c(_c), smell(_s), d(_d) {}
};
int main() {
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    scanf("%d %d", &row, &col);
    memset(dp, -1, sizeof dp);
    FOR(i, row) FOR(j, col) {
        scanf("%d", &g[i][j]);
    }
    queue<Node> q;
    q.push(Node(0, 0, false, 0));
    dp[0][0][0][0] = 0;
    int res = INF;
    while (!q.empty()) {
        Node tp = q.front(); q.pop();
        int r = tp.r, c = tp.c, d = tp.d;
        bool smell = tp.smell;
        int cur = dp[r][c][smell][d];
        if (r == row - 1 && c == col - 1) {
            res = cur;
            break;
        }
        if (g[r][c] == PURPLE) {
            int nr = r + dir_x[d], nc = c + dir_y[d];
            if (nr >= 0 && nr < row && nc >= 0 && nc < col && g[nr][nc] != RED && g[nr][nc] != BLUE) {
                int& nt = dp[nr][nc][0][d];
                if (nt >= 0) continue;
                else {
                    nt = cur + 1;
                    q.push(Node(nr, nc, 0, d));
                    continue;
                }
            }
        }
        FOR(i, 4) {
            int nr = r + dir_x[i], nc = c + dir_y[i];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == RED) continue;
            if (g[r][c] == PINK) {
                int& nt = dp[nr][nc][smell][i];
                if (nt >= 0) continue;
                nt = cur + 1;
                q.push(Node(nr, nc, smell, i));
            }
            else if (g[r][c] == ORANGE) {
                int& nt = dp[nr][nc][1][i];
                if (nt >= 0) continue;
                nt = cur + 1;
                q.push(Node(nr, nc, true, i));
            }
            else if (g[r][c] == BLUE) {
                int& nt = dp[nr][nc][smell][i];
                if (nt >= 0) continue;
                if (!smell) nt = INF;
                else {
                    nt = cur + 1;
                    q.push(Node(nr, nc, smell, i));
                }
            }
            else if (g[r][c] == PURPLE && d != i) {
                int& nt = dp[nr][nc][0][i];
                if (nt >= 0) continue;
                else {
                    nt = cur + 1;
                    q.push(Node(nr, nc, false, i));
                }
            }
        }
    }
    if (res >= INF) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}
