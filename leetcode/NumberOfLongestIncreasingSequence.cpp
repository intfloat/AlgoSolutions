class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz, 1), cnt(sz, 1);
        int max_len = 0;

        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= nums[i]) {
                    continue;
                }
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
            max_len = max(max_len, dp[i]);
        }

        int res = 0;
        for (int i = 0; i < sz; ++i) {
            if (dp[i] == max_len) {
                res += cnt[i];
            }
        }

        return res;
    }
};
