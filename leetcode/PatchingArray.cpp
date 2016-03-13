class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long cur = 0, res = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (cur >= n) {
                return res;
            }
            while (cur < n && nums[i] > cur + 1) {
                cur += cur + 1;
                ++res;
            }
            cur += nums[i];
        }
        while (cur < n) {
            cur += cur + 1;
            ++res;
        }
        return res;
    }
};
