#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9 + 7);
char g[505][505];
ll dp[2][505][505];
int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    if (row == 1 && col == 1) {
        printf("1\n");
        return 0;
    }
    FOR(i, row) scanf("%s", g[i]);
    int mx = (row + col - 1 - 1) / 2;
    vector<int> c1(row), c2(row);
    bool idx = 0;
    for (int i = mx; i >= 0; --i) {
        for (int j = 0; j < row; ++j) {
            c1[j] = i - j;
            c2[j] = row - 1 - j + col - 1 - i;
        }
        for (int j = 0; j < row; ++j) {
            for (int k = 0; k < row; ++k) {
                if (j > k || c1[j] < 0 || c1[j] >= col || c2[k] < 0 || c2[k] >= col
                    || c1[j] > c2[k]
                    || g[j][c1[j]] != g[k][c2[k]]) {
                    dp[idx][j][k] = 0;
                    continue;
                }
                if (i == mx) {
                    if (j == k && c1[j] == c2[k]) {
                        dp[idx][j][k] = 1;
                    }
                    else if (k - j + c2[k] - c1[j] == 1) {
                        dp[idx][j][k] = 1;
                    }
                    else dp[idx][j][k] = 0;
                    continue;
                }
                ll val = 0;
                val = (val + dp[!idx][j][k]) % MOD;
                if (j + 1 < row) val = (val + dp[!idx][j + 1][k]) % MOD;
                if (k - 1 >= 0) val = (val + dp[!idx][j][k - 1]) % MOD;
                if (j + 1 < row && k - 1 >= 0) val = (val + dp[!idx][j + 1][k - 1]) % MOD;
                dp[idx][j][k] = val;
            }
        }
        idx = !idx;
    }
    cout << dp[!idx][0][row - 1] << endl;
    return 0;
}
