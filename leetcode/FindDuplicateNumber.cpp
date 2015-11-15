class Solution {
public:
    bool ok(vector<int>& nums, int mid) {
        int ret = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            ret += nums[i] <= mid;
        }
        return ret > mid;
    }
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (ok(nums, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
