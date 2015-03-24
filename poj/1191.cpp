#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <limits.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int arr[9][9], sm[9][9];
int dp[9][9][9][9][16];
// get the square of sum in this region
int get(int r1, int c1, int r2, int c2) {
    assert(r1 <= r2 && c1 <= c2);
    int res = sm[r2][c2] - sm[r2][c1 - 1] - sm[r1 - 1][c2] + sm[r1 - 1][c1 - 1];
    return res * res;
}

const int INF = INT_MAX / 4;
int solve(int r1, int c1, int r2, int c2, int n) {
    assert(n >= 0);
    if (dp[r1][c1][r2][c2][n] != -1) return dp[r1][c1][r2][c2][n];
    if (r1 > r2 || c1 > c2) return INF;
    if (n == 0) return get(r1, c1, r2, c2);
    // can not be divided anymore
    if (r1 == r2 && c1 == c2) return INF;
    int mn = INF;
    // split in column
    for (int c = c1; c < c2; ++c) {
        // continue to split on right part
        mn = min(mn, get(r1, c1, r2, c) + solve(r1, c + 1, r2, c2, n - 1));
        // continue to split on left part
        mn = min(mn, solve(r1, c1, r2, c, n - 1) + get(r1, c + 1, r2, c2));
    }
    // split in row
    for (int r = r1; r < r2; ++r) {
        // continue to split on bottom part
        mn = min(mn, get(r1, c1, r, c2) + solve(r + 1, c1, r2, c2, n - 1));
        // continue to split on top part
        mn = min(mn, solve(r1, c1, r, c2, n - 1) + get(r + 1, c1, r2, c2));
    }
    dp[r1][c1][r2][c2][n] = mn;
    return mn;
}

int main() {
    int N, total = 0;
    scanf("%d", &N);
    memset(arr, 0, sizeof(arr));
    memset(sm, 0, sizeof(sm));
    FOR(i, 8) FOR(j, 8) {
        scanf("%d", arr[i + 1] + j + 1);
        total += arr[i + 1][j + 1];
    }
    for (int i = 1; i <= 8; ++i)
    for (int j = 1; j <= 8; ++j)
        sm[i][j] = sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1] + arr[i][j];
    memset(dp, -1, sizeof(dp));
    double res = solve(1, 1, 8, 8, N - 1) - static_cast<double>(total * total) / N;
    res = sqrt(res / N);
    // answer for sample: 1.633
    printf("%.3f\n", res);
    return 0;
}
