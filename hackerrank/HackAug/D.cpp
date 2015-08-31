#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
char g[1005][1005];
const int MAX_N = 1000005;
const int MAX_M = MAX_N * 8;
const int INF = INT_MAX / 2;
vector<int> head(MAX_N), pnt(MAX_M), nt(MAX_M), wei(MAX_M);
int ptr;
int row, col;
inline void addedge(int from, int to, int w) {
    pnt[ptr] = to; nt[ptr] = head[from]; wei[ptr] = w; head[from] = ptr++;
}
inline void dijsktra(int start, vector<int>& dis) {
    fill(dis.begin(), dis.end(), INF);
    priority_queue<point> q;
    q.push({0, start});
    dis[start] = 0;
    while (!q.empty()) {
        point tp = q.top(); q.pop();
        int pos = tp.second, d = -tp.first;
        if (d > dis[pos]) continue;
        for (int i = head[pos]; i != -1; i = nt[i]) {
            int to = pnt[i];
            if (dis[pos] + wei[i] < dis[to]) {
                dis[to] = dis[pos] + wei[i];
                q.push({-dis[to], to});
            }
        }
    }
    return;
}
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
int main() {
    ptr = 0;
    fill(head.begin(), head.end(), -1);
    scanf("%d %d", &row, &col);
    int T = row * col;
    int S, P;
    FOR(i, row) {
        scanf("%s", g[i]);
    }
    FOR(i, row) FOR(j, col) {
        int idx = i * col + j;
        if (g[i][j] == 'S') {
            S = idx;
            g[i][j] = '.';
        }
        else if (g[i][j] == 'P') {
            P = idx;
            g[i][j] = '.';
        }
        FOR(k, 4) {
            int nr = i + dir_x[k];
            int nc = j + dir_y[k];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
            int ii = nr * col + nc;
            addedge(idx, ii, g[nr][nc] == '#');
        }
        if (i == 0 || i + 1 == row || j == 0 || j + 1 == col) {
            addedge(T, idx, g[i][j] == '#');
        }
    }
    vector<int> ds(T + 1), dp(T + 1), dt(T + 1);
    dijsktra(S, ds);
    dijsktra(P, dp);
    dijsktra(T, dt);
    int res = INF;
    FOR(i, row) FOR(j, col) {
        int idx = i * col + j;
        int cur = ds[idx] + dp[idx] + dt[idx];
        if (g[i][j] == '#') {
            cur -= 2;
        }
        res = min(res, cur);
    }
    printf("%d\n", res);
    return 0;
}
