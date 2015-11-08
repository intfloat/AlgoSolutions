#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int g[105][105];
const int dir_x[] = {1, -1, 0, 0};
const int dir_y[] = {0, 0, 1, -1};
int bfs(int row, int col) {
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    int ret = 0;
    FOR(i, row) FOR(j, col) {
        if (g[i][j] == 1 && !visited[i][j]) {
            ++ret;
            queue<pii> q;
            q.push({i, j});
            visited[i][j] = true;
            while (!q.empty()) {
                pii tp = q.front(); q.pop();
                int r = tp.first, c = tp.second;
                FOR(k, 4) {
                    int nr = r + dir_x[k], nc = c + dir_y[k];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == 0 || visited[nr][nc]) continue;
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
    return ret;
}
void solve() {
    int row, col, N;
    cin >> row >> col;
    FOR(i, row) {
        string s;
        cin >> s;
        FOR(j, col) g[i][j] = s[j] - '0';
    }
    cin >> N;
    char type;
    int r, c, z;
    FOR(i, N) {
        cin >> type;
        if (type == 'M') {
            cin >> r >> c >> z;
            g[r][c] = z;
        }
        else {
            assert(type == 'Q');
            printf("%d\n", bfs(row, col));
        }
    }
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ":" << endl;
        solve();
    }
    return 0;
}
