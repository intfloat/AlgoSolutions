class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;
        int cur_len = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i - 1 >= 0 && nums[i - 1] >= nums[i]) {
                cur_len = 1;
            } else {
                ++cur_len;
            }

            res = max(res, cur_len);
        }

        return res;
    }
};
