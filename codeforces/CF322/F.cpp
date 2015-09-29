#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int dp[5001][2501][2];
vector<int> g[5001];
int leaves = 0, sz[5001];
void solve(int pos, int fa) {
    if (g[pos].size() == 1) {
        dp[pos][0][0] = dp[pos][1][1] = 0;
        sz[pos] = 1;
        return;
    }
    int cnt = 0;
    dp[pos][0][0] = dp[pos][0][1] = 0;
    FOR(i, g[pos].size()) {
        int to = g[pos][i];
        if (to == fa) continue;
        solve(to, pos);
        cnt += sz[to];
        for (int j = min(leaves / 2, cnt); j >= 0; --j) {
            dp[pos][j][0] += min(dp[to][0][0], dp[to][0][1] + 1);
            dp[pos][j][1] += min(dp[to][0][0] + 1, dp[to][0][1]);
            for (int k = min(sz[to], j); k > 0; --k) {
                FOR(p, 2) FOR(q, 2) {
                    dp[pos][j][p] = min(dp[pos][j][p], dp[pos][j - k][p] + dp[to][k][q] + (p != q));
                }
            }
        }
    }
    sz[pos] = cnt;
}
int main() {
    int n, x, y;
    scanf("%d", &n);
    if (n == 2) {
        printf("1\n");
        return 0;
    }
    FOR(i, n - 1) {
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(sz, 0, sizeof sz);
    int root = 1;
    while (g[root].size() <= 1) ++root;
    for (int i = 1; i <= n; ++i) leaves += (g[i].size() == 1);
    assert(leaves % 2 == 0);
    FOR(i, n + 1) FOR(j, leaves / 2 + 1) FOR(k, 2) dp[i][j][k] = INT_MAX / 2;
    solve(root, -1);
    cout << dp[root][leaves / 2][0] << endl;
    return 0;
}
