#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> g[105][105];
bool visited[105][105], lit[105][105];
int fa[10005];
queue<pii> q;
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
int _find(int x) {
    if (fa[x] == x) return x;
    fa[x] = _find(fa[x]);
    return fa[x];
}
void _merge(int x, int y) {
    fa[x] = y;
}
int n, m, r, c, a, b;
inline void update(int r, int c) {
    FOR(i, g[r][c].size()) {
        int nx = g[r][c][i].first, ny = g[r][c][i].second;
        if (!lit[nx][ny]) {
            lit[nx][ny] = true;
            int idx = nx * n + ny;
            FOR(j, 4) {
                int nr = nx + dir_x[j], nc = ny + dir_y[j];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || !lit[nr][nc]) continue;
                _merge(_find(idx), _find(nr * n + nc));
            }
            if (_find(idx) == _find(0)) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}
int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    scanf("%d %d", &n, &m);
    memset(visited, false, sizeof visited);
    memset(lit, false, sizeof lit);
    FOR(i, 10005) fa[i] = i;
    FOR(i, m) {
        scanf("%d %d %d %d", &r, &c, &a, &b);
        --r; --c; --a; --b;
        g[r][c].push_back({a, b});
    }
    q.push({0, 0});
    visited[0][0] = true;
    lit[0][0] = true;
    update(0, 0);
    while (!q.empty()) {
        pii tp = q.front(); q.pop();
        int x = tp.first, y = tp.second;
        update(x, y);
        FOR(i, 4) {
            int nx = x + dir_x[i], ny = y + dir_y[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!lit[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
            update(nx, ny);
        }
    }
    int res = 0;
    FOR(i, n) FOR(j, n) {
        res += lit[i][j];
    }
    printf("%d\n", res);
    return 0;
}
