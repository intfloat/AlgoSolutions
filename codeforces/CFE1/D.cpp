#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1005;
char g[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int res[MAX_N][MAX_N];
map<int, int> mp;
const int dir_x[] = {1, -1, 0, 0};
const int dir_y[] = {0, 0, 1, -1};
int main() {
    int row, col, Q;
    scanf("%d %d %d", &row, &col, &Q);
    FOR(i, row) {
        scanf("%s", g[i]);
    }
    memset(visited, false, sizeof visited);
    int cc = 0;
    FOR(i, row) FOR(j, col) {
        if (!visited[i][j] && g[i][j] == '.') {
            ++cc; mp[cc] = 0;
            queue<pii> q;
            q.push({i, j});
            visited[i][j] = true; res[i][j] = cc;
            while (!q.empty()) {
                pii tp = q.front(); q.pop();
                int r = tp.first, c = tp.second;
                FOR(k, 4) {
                    int nr = r + dir_x[k], nc = c + dir_y[k];
                    if (visited[nr][nc]) continue;
                    if (g[nr][nc] == '*') {
                        ++mp[cc];
                        continue;
                    }
                    visited[nr][nc] = true;
                    res[nr][nc] = cc;
                    q.push({nr, nc});
                }
            }
        }
    }
    int x, y;
    FOR(i, Q) {
        scanf("%d %d", &x, &y);
        --x; --y;
        printf("%d\n", mp[res[x][y]]);
    }
    return 0;
}
