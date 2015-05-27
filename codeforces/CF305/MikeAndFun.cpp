#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int solve(vector<int>& arr) {
    int ret = 0, cnt = 0;
    FOR(i, arr.size()) {
        if (arr[i]) ++cnt;
        else {
            ret = max(ret, cnt);
            cnt = 0;
        }
    }
    ret = max(ret, cnt);
    return ret;
}
int main() {
    int row, col, q, x, y;
    scanf("%d %d %d", &row, &col, &q);
    vector<vector<int> > g(row, vector<int>(col));
    FOR(i, row) FOR(j, col) scanf("%d", &g[i][j]);
    vector<int> r(row);
    FOR(i, row) r[i] = solve(g[i]);
    FOR(i, q) {
        scanf("%d %d", &x, &y);
        --x; --y;
        g[x][y] = 1 - g[x][y];
        r[x] = solve(g[x]);
        cout << *max_element(r.begin(), r.end()) << endl;
    }
    return 0;
}
