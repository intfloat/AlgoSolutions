class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s > accumulate(nums.begin(), nums.end(), 0)) return 0;
        int left = 1, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            int cur = accumulate(nums.begin(), nums.begin() + mid, 0);
            int ptr = mid;
            while (ptr < nums.size() && cur < s) {
                cur = cur - nums[ptr - mid] + nums[ptr];
                ++ptr;
            }
            if (cur >= s) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
