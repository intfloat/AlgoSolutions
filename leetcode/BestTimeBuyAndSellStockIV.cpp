class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int res = 0;
        const int N = prices.size();
        for (int i = 1; i < N; ++i)
            res += max(0, prices[i] - prices[i - 1]);
        if (2 * k >= N) return res;
        vector<vector<int> > dp(2, vector<int>(N + 1, 0));
        res = 0;
        for (int i = 1; i <= k; ++i) {
            int tmp = -999999;
            for (int j = 2; j <= N; ++j) {
                tmp = max(tmp, dp[!(i & 1)][j - 2] - prices[j - 2]);
                dp[i & 1][j] = max(dp[i & 1][j - 1], tmp + prices[j - 1]);
            }
            res = max(res, dp[i & 1][N]);
        }
        return res;
    }
};
