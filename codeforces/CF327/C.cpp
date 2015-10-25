#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1005;
const int INF = INT_MAX / 10;
char g[MAX_N][MAX_N];
int dp[4][MAX_N][MAX_N], dis[5][5];
struct Node {
    int r, c, d, to;
    Node(int _r, int _c, int _to, int _d): r(_r), c(_c), to(_to), d(_d) {}
};
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    vector<pii> arr[4];
    queue<Node> q;
    FOR(i, 5) FOR(j, 5) dis[i][j] = INF;
    FOR(k, 4) FOR(i, row) FOR(j, col) dp[k][i][j] = INF;
    FOR(i, row) {
        scanf("%s", g[i]);
        FOR(j, col) {
            if (g[i][j] >= '1' && g[i][j] <= '3') {
                int idx = g[i][j] - '0';
                q.push(Node(i, j, idx, 0));
                dp[idx][i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        Node tp = q.front(); q.pop();
        FOR(i, 4) {
            int nr = tp.r + dir_x[i], nc = tp.c + dir_y[i];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == '#') continue;
            if (g[nr][nc] == '.') {
                if (dp[tp.to][nr][nc] > tp.d + 1) {
                    dp[tp.to][nr][nc] = tp.d + 1;
                    q.push(Node(nr, nc, tp.to, tp.d + 1));
                }
            }
            else {
                int idx = g[nr][nc] - '0';
                if (dis[tp.to][idx] > tp.d + 1) {
                    dis[tp.to][idx] = dis[idx][tp.to] = tp.d + 1;
                }
            }
        }
    }
    int res = INF;
    --dis[1][2]; --dis[1][3]; --dis[2][3];
    int mx = max(dis[1][2], max(dis[1][3],  dis[2][3]));
    res = min(res, dis[1][2] + dis[1][3] + dis[2][3] - mx);
    FOR(i, row) FOR(j, col) {
        if (g[i][j] == '.') {
            res = min(res, dp[1][i][j] + dp[2][i][j] + dp[3][i][j] - 2);
        }
    }
    if (res >= INF - 1000) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}
