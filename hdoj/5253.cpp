#include <stdio.h>
#include <utility>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAX_N = 1005;
int g[MAX_N][MAX_N];
bool visited[MAX_N * MAX_N];
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
const int INF = INT_MAX / 2;
struct Node {
    int w, to;
    bool operator<(const Node& that) const {
        return w > that.w;
    }
    Node(int _w, int _to): w(_w), to(_to) {}
};
void solve() {
    int row, col, res = 0, rr, cc, idx, mn, nr, nc;
    scanf("%d %d", &row, &col);
    FOR(i, row) FOR(j, col) scanf("%d", g[i] + j);
    FOR(i, row * col) visited[i] = false;
    priority_queue<Node> q;
    q.push(Node(0, 0));
    FOR(i, row * col) {
        idx = -1;
        while (!q.empty()) {
            Node node = q.top(); q.pop();
            if (!visited[node.to]) {
                idx = node.to; mn = node.w; break;
            }
        }
        res += mn;
        visited[idx] = true;
        rr = idx / col; cc = idx % col;
        FOR(j, 4) {
            nr = rr + dir_x[j]; nc = cc + dir_y[j];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr * col + nc]) continue;
            q.push(Node(abs(g[rr][cc] - g[nr][nc]), nr * col + nc));
        }
    }
    printf("%d\n", res);
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
