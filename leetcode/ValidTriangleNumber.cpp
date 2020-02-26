class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] > 0) {
                    int idx = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin();
                    res += idx - (i + 1);
                }
            }
        }
        return res;
    }
};
