#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define IDX(r, c) (r * col + c)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int row, col, fa[1000005];
int _find(int x) {
    if (fa[x] == x) return x;
    else fa[x] = _find(fa[x]);
    return fa[x];
}
inline void _union(int x, int y) {
    int rx = _find(x), ry = _find(y);
    if (rx != ry) {
        fa[rx] = ry;
    }
}
int main() {
    scanf("%d %d", &row, &col);
    FOR(i, row * col + 1) fa[i] = i;
    vector<vector<int> > arr(row, vector<int>(col));
    vector<int> res(row * col, 0), rmin(row, -1), cmin(col, -1);
    FOR(i, row) FOR(j, col) scanf("%d", &arr[i][j]);
    vector<vector<pii> > rows(row), cols(col);
    vector<pii> all;
    FOR(i, row) {
        FOR(j, col) rows[i].push_back({arr[i][j], IDX(i, j)});
        sort(rows[i].begin(), rows[i].end());
        int ptr = 0, len = rows[i].size();
        while (ptr < len) {
            int j = ptr + 1;
            while (j < len && rows[i][j].first == rows[i][ptr].first) {
                _union(rows[i][j].second, rows[i][ptr].second);
                ++j;
            }
            ptr = j;
        }
    }
    FOR(i, col) {
        FOR(j, row) cols[i].push_back({arr[j][i], IDX(j, i)});
        sort(cols[i].begin(), cols[i].end());
        int ptr = 0, len = cols[i].size();
        while (ptr < len) {
            int j = ptr + 1;
            while (j < len && cols[i][j].first == cols[i][ptr].first) {
                _union(cols[i][j].second, cols[i][ptr].second);
                ++j;
            }
            ptr = j;
        }
    }
    FOR(i, row) FOR(j, col) {
        all.push_back({arr[i][j], IDX(i, j)});
    }
    sort(all.begin(), all.end());
    FOR(i, all.size()) {
        int rr = all[i].second / col, cc = all[i].second % col, vv = all[i].first;
        int idx = _find(all[i].second);
        // check row
        if (rmin[rr] >= 0) {
            int r1 = rmin[rr] / col, c1 = rmin[rr] % col;
            if (arr[r1][c1] < vv) {
                res[idx] = max(res[idx], res[_find(IDX(r1, c1))] + 1);
            }
        }
        else res[idx] = max(1, res[idx]);
        // check col
        if (cmin[cc] >= 0) {
            int r2 = cmin[cc] / col, c2 = cmin[cc] % col;
            if (arr[r2][c2] < vv) {
                res[idx] = max(res[idx], res[_find(IDX(r2, c2))] + 1);
            }
        }
        else res[idx] = max(1, res[idx]);
        rmin[rr] = idx; cmin[cc] = idx;
    }
    FOR(i, row) {
        FOR(j, col) {
            printf("%d ", res[_find(IDX(i, j))]);
        }
        printf("\n");
    }
    return 0;
}
