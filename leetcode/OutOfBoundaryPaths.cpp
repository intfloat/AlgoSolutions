#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<vector<int> > > vii;
typedef vector<vector<int> > vi;

const int MOD = 1000000007;
const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vii dp(N + 1, vi(m, vector<int>(n, 0)));
        dp[0][i][j] = 1;
        int res = 0;
        for (int step = 1; step <= N; ++step) {
            FOR(r, m) FOR(c, n) FOR(d, 4) {
                int nr = r + dir_x[d];
                int nc = c + dir_y[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    res = (res + dp[step - 1][r][c]) % MOD;
                } else {
                    dp[step][nr][nc] = (dp[step][nr][nc] + dp[step - 1][r][c]) % MOD;
                }
            }
        }
        return res;
    }
};
