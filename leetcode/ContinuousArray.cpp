class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> diff2idx;
        diff2idx[0] = -1;
        int zeros = 0, ones = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            zeros += nums[i] == 0;
            ones += nums[i] == 1;
            int diff = zeros - ones;
            if (diff2idx.find(diff) != diff2idx.end()) {
                res = max(res, i - diff2idx[diff]);
            } else {
                diff2idx[diff] = i;
            }
        }
        return res;
    }
};