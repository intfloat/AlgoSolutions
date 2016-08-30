#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll dp[101][101][101];
const ll INF = (ll)(1e14);
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> color(n);
    FOR(i, n) cin >> color[i];
    vector<vector<int> > price(n, vector<int>(m));
    FOR(i, n) FOR(j, m) cin >> price[i][j];
    FOR(i, n) FOR(j, m) FOR(u, k + 1) {
        if (color[i] > 0 && j + 1 != color[i]) {
            dp[i][j][u] = INF;
        } else if (i == 0) {
            if (color[i] == 0) {
                if (u == 1) dp[i][j][u] = price[i][j];
                else dp[i][j][u] = INF;
            } else {
                if (u == 1 && j + 1 == color[i]) dp[i][j][u] = 0;
                else dp[i][j][u] = INF;
            }
        } else {
            dp[i][j][u] = INF;
            FOR(tt, m) {
                if (j + 1 == tt + 1) {
                    ll cur = dp[i - 1][tt][u];
                    if (color[i] == 0) cur += price[i][j];
                    dp[i][j][u] = min(dp[i][j][u], cur);
                } else {
                    if (u - 1 < 0) continue;
                    ll cur = dp[i - 1][tt][u - 1];
                    if (color[i] == 0) cur += price[i][j];
                    dp[i][j][u] = min(dp[i][j][u], cur);
                }
            }
        }
    }
    ll res = INF;
    FOR(i, m) res = min(res, dp[n - 1][i][k]);
    if (res == INF) {
        printf("-1\n");
    } else {
        cout << res << endl;
    }
    return 0;
}
