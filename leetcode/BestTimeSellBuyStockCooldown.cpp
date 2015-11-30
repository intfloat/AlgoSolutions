class Solution {
private:
    vector<int> dp[2];
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        dp[0].resize(n);
        dp[1].resize(n);
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        for (int i = 1; i < (int)prices.size(); ++i) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            if (i - 2 >= 0) dp[1][i] = max(dp[1][i - 1], dp[0][i - 2] - prices[i]);
            else dp[1][i] = max(dp[1][i - 1], -prices[i]);
        }
        return dp[0][(int)prices.size() - 1];
    }
};

