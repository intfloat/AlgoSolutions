#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;


class Solution {
private:
    vector<int> dp = vector<int>(1<<16);
    int target;
    int target_mask;
    bool solve(const vector<int>& nums, int mask, int cur_sum) {
        if (dp[mask] >= 0) {
            return dp[mask];
        }
        if (mask == target_mask) {
            dp[mask] = true;
            return dp[mask];
        }

        for (int i = 0; i < nums.size(); ++i) {
            if ((1 << i) & mask) continue;
            if (cur_sum + nums[i] > target) continue;
            if (solve(nums, mask | (1 << i), (cur_sum + nums[i]) % target)) {
                dp[mask] = true;
                return dp[mask];
            }
        }
        dp[mask] = false;
        return dp[mask];
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k > 0) {
            return false;
        }
        this->target = sum / k;
        this->target_mask = (1 << nums.size()) - 1;
        fill(dp.begin(), dp.end(), -1);
        return solve(nums, 0, 0);
    }
};

int main() {
    Solution sol;
    return 0;
}
