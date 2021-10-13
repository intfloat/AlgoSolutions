class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        if (l > r || nums[l] != target) return -1;
        return l;
    }
};
