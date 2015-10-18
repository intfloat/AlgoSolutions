#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// D L U R
const int dir_c[] = {0, -1, 0, 1};
const int dir_r[] = {1, 0, -1, 0};
int main() {
    int row, col, d;
    scanf("%d %d", &row, &col);
    vector<string> g(row);
    FOR(i, row) cin >> g[i];
    pii start;
    FOR(i, row) FOR(j, col) {
        if (g[i][j] == 'D') {
            g[i][j] = '.';
            start = make_pair(i, j);
            d = 0;
        }
        if (g[i][j] == 'L') {
            g[i][j] = '.';
            start = make_pair(i, j);
            d = 1;
        }
        if (g[i][j] == 'U') {
            g[i][j] = '.';
            start = make_pair(i, j);
            d = 2;
        }
        if (g[i][j] == 'R') {
            g[i][j] = '.';
            start = make_pair(i, j);
            d = 3;
        }
    }
    set<tuple<int, int, int> > st;
    set<pii> area;
    while (true) {
        area.insert(start);
        int r = start.first, c = start.second;
        auto cur = make_tuple(r, c, d);
        if (st.find(cur) != st.end()) break;
        else st.insert(cur);
        int nr = r + dir_r[d], nc = c + dir_c[d];
        if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == '*') {
            d = (d + 1) % 4;
        }
        else {
            start = make_pair(nr, nc);
        }
    }
    printf("%d\n", (int)area.size());
    return 0;
}
