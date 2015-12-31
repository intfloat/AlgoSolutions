class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = (int)1e8;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        if (dp[amount] == INF) {
            return -1;
        }
        else {
            return dp[amount];
        }
    }
};
