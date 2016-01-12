#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define CHANGE(r, c) (r * col + c)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1005;
int row, col;
char g[MAX_N][MAX_N];
int N, fa[MAX_N * MAX_N], sz[MAX_N * MAX_N];
inline void init() {
    for (int i = 0; i < N; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
}
int _find(int x) {
    if (x == fa[x]) return x;
    fa[x] = _find(fa[x]);
    return fa[x];
}
inline void merge(int x, int y) {
    if (x != y) {
        fa[x] = y;
        sz[y] += sz[x];
    }
}
const int dir_x[] = {1, -1, 0, 0};
const int dir_y[] = {0, 0, 1, -1};
int main() {
    scanf("%d %d", &row, &col);
    N = row * col;
    FOR(i, row) {
        scanf("%s", g[i]);
    }
    init();
    FOR(i, row) FOR(j, col) {
        if (g[i][j] == '*') continue;
        int pos = CHANGE(i, j);
        FOR(k, 4) {
            int nr = i + dir_x[k], nc = j + dir_y[k];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == '*') continue;
            merge(_find(pos), _find(CHANGE(nr, nc)));
        }
    }
    vector<string> res(row);
    FOR(i, row) FOR(j, col) {
        if (g[i][j] == '.') {
            res[i].push_back('.');
            continue;
        }
        set<int> st;
        int cnt = 1;
        FOR(k, 4) {
            int nr = i + dir_x[k], nc = j + dir_y[k];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == '*') continue;
            int cur = _find(CHANGE(nr, nc));
            if (st.find(cur) != st.end()) continue;
            st.insert(cur);
            cnt = (cnt + sz[cur]) % 10;
        }
        res[i].push_back((char)(cnt + '0'));
    }
    FOR(i, row) {
        printf("%s\n", res[i].c_str());
    }
    return 0;
}
