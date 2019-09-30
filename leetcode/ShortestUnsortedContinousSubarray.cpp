class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int left = 0;
        while (left < nums.size() && nums[left] == sorted_nums[left]) ++left;
        int right = nums.size() - 1;
        while (right >= 0 && nums[right] == sorted_nums[right]) --right;
        return max(0, right - left + 1);
    }
};