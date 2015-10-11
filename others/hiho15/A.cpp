#include <vector>
#include <stdio.h>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 1000005;
vector<int> two(MAX_N, 0), five(MAX_N, 0);
inline void preprocess() {
    int val = 2, cnt = 1;
    while (val < MAX_N) {
        for (int i = val; i < MAX_N; i += val) two[i] = cnt;
        ++cnt; val = val * 2;
    }
    val = 5; cnt = 1;
    while (val < MAX_N) {
        for (int i = val; i < MAX_N; i += val) five[i] = cnt;
        ++cnt; val = val * 5;
    }
    two[0] = MAX_N * 100; five[0] = MAX_N * 100;
}
int t[1005][1005], f[1005][1005], dp[1005][1005];
int main() {
    preprocess();
    int N, x;
    scanf("%d", &N);
    FOR(i, N) FOR(j, N) {
        scanf("%d", &x);
        t[i][j] = two[x];
        f[i][j] = five[x];
    }
    dp[0][0] = t[0][0];
    for (int i = 1; i < N; ++i) dp[0][i] = min(MAX_N, dp[0][i - 1] + t[0][i]);
    for (int i = 1; i < N; ++i) dp[i][0] = min(MAX_N, dp[i - 1][0] + t[i][0]);
    for (int i = 1; i < N; ++i) for (int j = 1; j < N; ++j) {
        dp[i][j] = t[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        dp[i][j] = min(dp[i][j], MAX_N);
    }
    int res = dp[N - 1][N - 1];
    dp[0][0] = f[0][0];
    for (int i = 1; i < N; ++i) dp[0][i] = min(MAX_N, dp[0][i - 1] + f[0][i]);
    for (int i = 1; i < N; ++i) dp[i][0] = min(MAX_N, dp[i - 1][0] + f[i][0]);
    for (int i = 1; i < N; ++i) for (int j = 1; j < N; ++j) {
        dp[i][j] = f[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        dp[i][j] = min(dp[i][j], MAX_N);
    }
    res = min(res, dp[N - 1][N - 1]);
    printf("%d\n", res);
    return 0;
}
