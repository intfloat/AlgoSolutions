class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(sz, 1), pv(sz, -1);
        vector<int> ret;
        int mx = -1, idx = -1;
        for (int i = 0; i < sz; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        pv[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if (dp[i] > mx) {
                mx = dp[i];
                idx = i;
            }
        }
        while (true) {
            ret.push_back(nums[idx]);
            idx = pv[idx];
            if (idx < 0) {
                break;
            }
        }
        return ret;
    }
};
