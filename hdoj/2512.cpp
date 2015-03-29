#include <stdio.h>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MOD = 1000;
int main() {
    vector<vector<int> > dp(2001, vector<int>(2001, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= 2000; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % MOD;
        }
    }
    int N, number;
    scanf("%d", &N);
    FOR(i, N) {
        scanf("%d", &number);
        int res = 0;
        for (int i = 1; i <= number; ++i) {
            res = (res + dp[number][i]) % MOD;
        }
        printf("%d\n", res);
    }
    return 0;
}
