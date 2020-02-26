class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int ptr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            while (ptr < nums.size() && nums[ptr] - nums[i] <= 1) {
                ++ptr;
            }
            if (nums[ptr - 1] == nums[i] + 1) {
                res = max(res, ptr - i);
            }
        }
        return res;
    }
};
