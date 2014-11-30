#include <algorithm>
#include <iostream>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MOD = 12345678;
typedef long long ll;
int dp[155][155][25][25];
int main() {
    memset(dp, 0, sizeof(dp));
    int n, m, k;
    cin >> n >> m >> k;
    dp[0][0][0][0] = 1;
    FOR(i, n + 1) FOR(j, m + 1) FOR(p, k + 1) FOR(q, k + 1) {
        int cur = dp[i][j][p][q];
        dp[i + 1][j][p + 1][max(0, q - 1)] = (dp[i + 1][j][p + 1][max(0, q - 1)] + cur) % MOD;
        dp[i][j + 1][max(0, p - 1)][q + 1] = (dp[i][j + 1][max(0, p - 1)][q + 1] + cur) % MOD;
    }
    int res = 0;
    FOR(p, k + 1) FOR(q, k + 1) res = (res + dp[n][m][p][q]) % MOD;
    cout << res << endl;
    return 0;
}
