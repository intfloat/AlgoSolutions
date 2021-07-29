class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int left = 0;
        int val = 1;
        for (int i = 0; i < nums.size(); ++i) {
            val *= nums[i];
            while (val >= k && left <= i) {
                val /= nums[left];
                ++left;
            }
            if (left <= i) {
                res += i - left + 1;
            }
        }
        return res;
    }
};
