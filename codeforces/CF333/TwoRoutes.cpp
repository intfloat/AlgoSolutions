#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 405;
bool g[MAX_N][MAX_N];
int n, m;
int bfs() {
    vector<bool> visited(n + 1, false);
    queue<pii> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty()) {
        pii tp = q.front(); q.pop();
        if (tp.first == n) {
            return tp.second;
        }
        for (int i = 1; i <= n; ++i) {
            if (g[tp.first][i] && !visited[i]) {
                q.push({i, tp.second + 1});
                visited[i] = true;
            }
        }
    }
    return -1;
}
int main() {
    memset(g, false, sizeof g);
    scanf("%d %d", &n, &m);
    FOR(i, m) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][y] = g[y][x] = true;
    }
    if (g[1][n]) {
        FOR(i, n + 1) FOR(j, n + 1) g[i][j] = 1 - g[i][j];
    }
    printf("%d\n", bfs());
    return 0;
}
