#include <stdio.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const ll MOD = 1000000000;
const int MAX_N = 2005;
ll dp[MAX_N][MAX_N], acc[MAX_N][MAX_N];
ll cnt[MAX_N][MAX_N], sm[MAX_N][MAX_N];
void solve() {
    int row, col;
    scanf("%d %d", &row, &col);
    FOR(i, col + 1) dp[0][i] = 1;
    FOR(i, col + 1) {
        if (i == 0) {
            acc[0][i] = dp[0][i];
        }
        else {
            acc[0][i] = (acc[0][i - 1] + dp[0][i]) % MOD;
        }
    }
    for (int i = 1; i < col; ++i) {
        for (int j = 0; j <= col; ++j) {
            dp[i][j] = acc[i - 1][j];
        }
        for (int j = 0; j <= col; ++j) {
            if (j == 0) {
                acc[i][j] = dp[i][j];
            }
            else {
                acc[i][j] = (acc[i][j - 1] + dp[i][j]) % MOD;
            }
        }
    }
    for (int i = 0; i <= col; ++i) {
        cnt[0][i] = dp[col - 1][i];
        if (i == 0) sm[0][i] = cnt[0][i];
        else sm[0][i] = (sm[0][i - 1] + cnt[0][i]) % MOD;
    }
    for (int i = 1; i < row; ++i) {
        for (int j = 0; j <= col; ++j) {
            cnt[i][j] = sm[i - 1][j] * dp[col - 1][j];
            if (j == 0) sm[i][j] = cnt[i][j];
            else sm[i][j] = (sm[i][j - 1] + cnt[i][j]) % MOD;
        }
    }
    printf("%lld\n", sm[row - 1][col]);
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        solve();
    }
    return 0;
}
