#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

bool wall[10][10];
int g[10][10];
pair<int, int> source, target, person;
// left, down, right, up
const int dir_x[] = {0, 1, 0, -1};
const int dir_y[] = {-1, 0, 1, 0};
int dp[10][10][4];
int T, row, col;
bool visited[10][10];
const int INF = INT_MAX / 2;
struct Node {
    int r, c, d;
    Node(int _r, int _c, int _d): r(_r), c(_c), d(_d) {}
};

void bfs(int x, int y, int bx, int by) {
    assert(!(x == bx && y == by));
    assert(wall[bx][by] == false);
    queue<pair<int, int> > q;
    visited[x][y] = wall[bx][by] = true;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> tp = q.front(); q.pop();
        FOR(i, 4) {
            int nx = tp.first + dir_x[i];
            int ny = tp.second + dir_y[i];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if (visited[nx][ny] || wall[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    wall[bx][by] = false;
    return;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> row >> col;
        memset(wall, false, sizeof(wall));
        FOR(i, 10) FOR(j, 10) FOR(dir, 4) dp[i][j][dir] = INF;
        FOR(r, row) FOR(c, col) {
            cin >> g[r][c];
            if (g[r][c] == 1) wall[r][c] = true;
            else if (g[r][c] == 2) source = make_pair(r, c);
            else if (g[r][c] == 3) target = make_pair(r, c);
            else if (g[r][c] == 4) person = make_pair(r, c);
        }
        memset(visited, false, sizeof(visited));
        bfs(person.first, person.second, source.first, source.second);
        queue<Node> q;
        FOR(i, 4) {
            int xx = source.first + dir_x[i];
            int yy = source.second + dir_y[i];
            if (xx < 0 || yy < 0 || xx >= row || yy >= col) continue;
            if (wall[xx][yy] || !visited[xx][yy]) continue;
            dp[source.first][source.second][i] = 0;
            q.push(Node(source.first, source.second, i));
        }
        while (!q.empty()) {
            Node tp = q.front(); q.pop();
            if (tp.r == target.first && tp.c == target.second) break;
            memset(visited, false, sizeof(visited));
            int xx = tp.r - dir_x[tp.d];
            int yy = tp.c - dir_y[tp.d];
            if (xx < 0 || yy < 0 || xx >= row || yy >= col) continue;
            if (wall[xx][yy]) continue;
            bfs(tp.r, tp.c, xx, yy);
            FOR(i, 4) {
                int x = xx + dir_x[i];
                int y = yy + dir_y[i];
                if (x < 0 || y < 0 || x >= row || y >= col) continue;
                if (wall[x][y] || !visited[x][y]) continue;
                if (dp[tp.r][tp.c][tp.d] + 1 < dp[xx][yy][i]) {
                    dp[xx][yy][i] = dp[tp.r][tp.c][tp.d] + 1;
                    q.push(Node(xx, yy, i));
                }
            }
        }
        int mn = INF;
        FOR(i, 4) mn = min(mn, dp[target.first][target.second][i]);
        if (mn < INF) cout << mn << endl;
        else cout << -1 << endl;
    }
    return 0;
}
