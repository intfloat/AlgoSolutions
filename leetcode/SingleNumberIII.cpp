class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val = 0, sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            val ^= nums[i];
        }
        val = (val & (-val));
        int v1 = 0, v2 = 0;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] & val) {
                v1 ^= nums[i];
            }
            else {
                v2 ^= nums[i];
            }
        }
        vector<int> res = {v1, v2};
        return res;
    }
};
