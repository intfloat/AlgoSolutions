class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(n + 1, vector<int>(n + 1));
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = 0;
                for (int k = i; k <= j; ++k) {
                    int cur = nums[i - 1] * nums[k] * nums[j + 1];
                    if (i <= k - 1) cur += dp[i][k - 1];
                    if(k + 1 <= j) cur += dp[k + 1][j];
                    dp[i][j] = max(dp[i][j], cur);
                }
            }
        }
        return dp[1][n];
    }
};
