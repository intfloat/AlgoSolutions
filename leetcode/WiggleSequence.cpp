class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int res = 1;
        vector<vector<int> > dp(n, vector<int>(2, 1));
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                } else if (nums[j] > nums[i]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};
