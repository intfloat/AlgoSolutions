class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size();
        int sm = sz * (sz + 1) / 2;
        for (int i = 0; i < sz; ++i) {
            sm -= nums[i];
        }
        return sm;
    }
};
