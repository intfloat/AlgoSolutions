#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1000000007;

ll dp[100005][3][2][3];
class Solution {
public:
    int checkRecord(int n) {
        // 0: P, 1: A, 2: L
        FOR(i, n + 1) FOR(j, 3) FOR(k, 2) FOR(p, 3) dp[i][j][k][p] = 0;
        dp[1][0][0][0] = 1;
        dp[1][1][1][0] = 1;
        dp[1][2][0][1] = 1;
        for (int i = 2; i <= n; ++i) {
            FOR(late, 3) FOR(absent, 2) FOR(cur, 3) {
                if (cur == 0 && late == 0) {
                    dp[i][cur][absent][late] = (dp[i - 1][0][absent][0] + dp[i - 1][1][absent][0]
                        + dp[i - 1][2][absent][1] + dp[i - 1][2][absent][2]) % MOD;
                }
                if (cur == 1 && absent == 1 && late == 0) {
                    dp[i][cur][absent][late] = (dp[i - 1][0][0][0] + dp[i - 1][2][0][1]
                        + dp[i - 1][2][0][2]) % MOD;
                }
                if (cur == 2 && late == 1) {
                    dp[i][cur][absent][late] = (dp[i - 1][0][absent][0] + dp[i - 1][1][absent][0]
                        + dp[i - 1][2][absent][0]) % MOD;
                }
                if (cur == 2 && late == 2) {
                    dp[i][cur][absent][late] = dp[i - 1][2][absent][1];
                }
            }
        }
        ll res = 0;
        FOR(i, 3) FOR(j, 2) FOR(cur, 3) {
            res = (res + dp[n][cur][j][i]) % MOD;
        }
        return (int)res;
    }
};

int main() {
    Solution solution;
    cout << solution.checkRecord(100000) << endl;
    return 0;
}