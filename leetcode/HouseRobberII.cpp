class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return max(0, nums[0]);
        vector<int> rob(len), pass(len);
        // not rob first house
        rob[0] = pass[0] = 0;
        for (int i = 1; i < len; ++i) {
            rob[i] = pass[i - 1] + nums[i];
            pass[i] = max(pass[i - 1], rob[i - 1]);
        }
        int res = max(rob[len - 1], pass[len - 1]);
        // rob first house
        rob[0] = nums[0]; pass[0] = 0;
        for (int i = 1; i < len; ++i) {
            rob[i] = pass[i - 1] + nums[i];
            pass[i] = max(pass[i - 1], rob[i - 1]);
        }
        res = max(res, pass[len - 1]);
        return res;
    }
};
