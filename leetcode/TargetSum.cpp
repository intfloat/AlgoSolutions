#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sm = accumulate(nums.begin(), nums.end(), 0);
        if (S > sm) {
            return 0;
        }
        int mid = 1005;
        vector<int> dp(mid * 2), backup(mid * 2);
        dp[mid] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = -sm; j <= sm; ++j) {
                backup[j + mid] = 0;
                if (j - nums[i] + mid >= 0) {
                    backup[j + mid] += dp[j - nums[i] + mid];
                }
                if (j + nums[i] + mid < dp.size()) {
                    backup[j + mid] += dp[j + nums[i] + mid];
                }
            }
            for (int j = -sm; j <= sm; ++j) {
                dp[j + mid] = backup[j + mid];
            }
        }
        return dp[S + mid];
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;
    Solution sol;
    cout << sol.findTargetSumWays(nums, S) << endl;
    return 0;
}
