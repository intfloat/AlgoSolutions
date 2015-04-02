#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

vector<vector<bool> > visited;
int row, col;
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};

bool bfs(const vector<vector<int> >& grid,
         const vector<vector<int> >& check,
         int mid) {
    FOR(i, visited.size()) fill(visited[i].begin(), visited[i].end(), false);
    queue<pair<int, int> > q;
    FOR(i, row) {
        FOR(j, col) {
            if (check[i][j]) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
                break;
            }
        }
        if (!q.empty()) break;
    }
    while (!q.empty()) {
        pair<int, int> tp = q.front(); q.pop();
        int x = tp.first, y = tp.second;
        FOR(i, 4) {
            int xx = x + dir_x[i];
            int yy = y + dir_y[i];
            if (xx < 0 || xx >= row || yy < 0 || yy >= col || visited[xx][yy]) continue;
            if (abs(grid[x][y] - grid[xx][yy]) > mid) continue;
            visited[xx][yy] = true;
            q.push(make_pair(xx, yy));
        }
    }
    FOR(i, row) FOR(j, col) {
        if (check[i][j] && !visited[i][j]) return false;
    }
    return true;
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);    
    scanf("%d %d", &row, &col);
    vector<vector<int> > grid(row, vector<int>(col));
    vector<vector<int> > check(row, vector<int>(col));
    FOR(i, row) FOR(j, col) scanf("%d", &grid[i][j]);
    FOR(i, row) FOR(j, col) scanf("%d", &check[i][j]);
    visited.resize(row);
    FOR(i, row) visited[i].resize(col);

    int left = 0, right = -1;
    FOR(i, row) right = max(right, *max_element(grid[i].begin(), grid[i].end()));
    while (left < right) {
        int mid = (left + right) / 2;
        if (bfs(grid, check, mid)) right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
    return 0;
}
