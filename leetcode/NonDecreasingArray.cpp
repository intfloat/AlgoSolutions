class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int sz = nums.size();
        int mod_cnt = 0;
        for (int i = 0; i < sz - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (mod_cnt >= 1) {
                    return false;
                }
                if (i - 1 < 0 || nums[i + 1] >= nums[i - 1]) {
                    ++mod_cnt;
                    nums[i] = nums[i + 1];
                } else if (i + 2 >= sz || nums[i + 2] >= nums[i]) {
                    ++mod_cnt;
                    nums[i + 1] = nums[i];
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
