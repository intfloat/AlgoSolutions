class Solution {
public:
    int getMoneyAmount(int n) {
        int INF = n * n;
        vector<vector<int> > dp(n, vector<int>(n, INF));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n && i + len <= n; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    int cur = 0;
                    if (k > i) cur = max(cur, dp[i][k - 1] + k + 1);
                    if (j > k) cur = max(cur, dp[k + 1][j] + k + 1);
                    dp[i][j] = min(dp[i][j], cur);
                }
            }
        }
        return dp[0][n - 1];
    }
};
