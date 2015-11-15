class Solution {
public:
    int rob(vector<int> &num) {
        int len = num.size();
        if (len == 0) return 0;
        if (len == 1) return num[0];
        vector<int> dp(len, 0);
        dp[0] = num[0]; dp[1] = max(num[1], num[0]);
        for (int i = 2; i < len; ++i) {
            dp[i] = max(dp[i - 1], num[i] + dp[i - 2]);
        }
        return dp[len - 1];
    }
};
