#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char g[505][505];
int row, col;
set<pii> st;
const int dir_x[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dir_y[] = {1, -1, 0, 0, 1, -1, 1, -1};

int check_aux(pii p, int dr, int dc) {
    int ret = 0;
    bool pv = false;
    while (p.first >= 0 && p.first < row && p.second >= 0 && p.second < col) {
        int x = p.first, y = p.second;
        if (g[x][y] == '#' && st.find({x, y}) != st.end()) {
            if (!pv) ++ret;
            pv = true;
        } else {
            pv = false;
        }
        p.first += dr;
        p.second += dc;
    }
    return ret;
}
bool check(pii p) {
    int ret = max(check_aux({p.first, 0}, 0, 1), check_aux({0, p.second}, 1, 0));
    int mn = min(p.first, p.second);
    ret = max(ret, check_aux({p.first - mn, p.second - mn}, 1, 1));
    if (p.first + p.second < row) ret = max(ret, check_aux({p.first + p.second, 0}, -1, 1));
    else ret = max(ret, check_aux({row - 1, p.second - (row - 1 - p.first)}, -1, 1));
    return ret >= 4;
}
int main() {
    scanf("%d %d", &row, &col);
    FOR(i, row) scanf("%s", g[i]);
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    int mcnt = 0, scnt = 0;
    FOR(i, row) FOR(j, col) {
        if (visited[i][j] || g[i][j] == '.') continue;
        st.clear();
        vector<pii> arr;
        queue<pii> q; q.push({i, j}); st.insert({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
            pii tp = q.front(); q.pop();
            FOR(k, 8) {
                int nr = tp.first + dir_x[k];
                int nc = tp.second + dir_y[k];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc] || g[nr][nc] == '.') continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
                st.insert({nr, nc});
            }
        }
        for (auto it = st.begin(); it != st.end(); ++it) arr.push_back(*it);
        int fours = 0;
        FOR(k, 100) {
            pii r = arr[rand() % ((int)arr.size())];
            fours += check(r);
            if (fours >= 5) break;
        }
        if (fours >= 5) ++mcnt;
        else ++scnt;
    }
    printf("%d %d\n", mcnt, scnt);
    return 0;
}
