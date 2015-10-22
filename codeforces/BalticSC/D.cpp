#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 505;
const int INF = INT_MAX / 2;
const char wilder = '&';
const char town = '*';
const char empty = '.';
const char mountain = '#';
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
char g[MAX_N][MAX_N];
int dis[MAX_N][MAX_N];
int main() {
    int row, col, wt, tw;
    scanf("%d %d", &col, &row);
    scanf("%d %d", &wt, &tw);
    FOR(i, row) scanf("%s", g[i]);
    FOR(i, row) FOR(j, col) dis[i][j] = INF;
    vector<bool> inq(row * col + 5, false);
    queue<int> q;
    dis[0][0] = 0; q.push(0); inq[0] = true;
    g[0][0] = town;
    while (!q.empty()) {
        int tp = q.front(); q.pop(); inq[tp] = false;
        int r = tp / col, c = tp % col;
        FOR(i, 4) {
            int nr = r + dir_x[i], nc = c + dir_y[i];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == mountain) continue;
            int cost = 0;
            if (g[r][c] == town) { cost = tw; g[nr][nc] = wilder; }
            else if (g[r][c] == wilder) { cost = wt; g[nr][nc] = town; }
            if (dis[nr][nc] > dis[r][c] + cost) {
                dis[nr][nc] = dis[r][c] + cost;
                int index = nr * col + nc;
                if (!inq[index]) {
                    q.push(index);
                    inq[index] = true;
                }
            }
        }
    }
    if (dis[row - 1][col - 1] == INF) printf("IMPOSSIBLE\n");
    else printf("%d\n", dis[row - 1][col - 1]);
    return 0;
}
