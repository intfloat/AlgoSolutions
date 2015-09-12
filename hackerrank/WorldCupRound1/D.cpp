#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
char g[12][12];
int row, col;
map<pair<int, int>, int> memo[12];
int dfs(int r, int v1, int v2) {
    if (r == row) return 1;
    FOR(i, col) {
        if (g[r][i] == '*' && ((1 << i) & v1)) {
            v1 -= (1 << i);
        }
        if (g[r][i] == '*' && ((1 << i) & v2)) {
            v2 -= (1 << i);
        }
    }
    auto cur = make_pair(v1, v2);
    if (memo[r].find(cur) != memo[r].end()) return memo[r][cur];
    int ret = 0;
    FOR(i, col) {
        if (g[r][i] == '*' || ((1 << i) & v1) || ((1 << i) & v2)) {
            continue;
        }
        int t = (1 << i);
        int nv1 = ((v1 << 1) | (t << 1)) % (1 << col);
        int nv2 = (v2 >> 1) | (t >> 1);
        ret += dfs(r + 1,nv1, nv2);
    }
    memo[r][cur] = ret;
    return ret;
}
int main() {
    scanf("%d %d", &row, &col);
    FOR(i, row) scanf("%s", g[i]);
    printf("%d\n", dfs(0, 0, 0));
    return 0;
}
