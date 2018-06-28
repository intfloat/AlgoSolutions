class Solution {
private:
    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int mid = l + (r - l) / 2;
        int lcnt = merge(nums, l, mid);
        int rcnt = merge(nums, mid + 1, r);
        int cur_cnt = 0, ptr = mid + 1;
        for (int i = l; i <= mid; ++i) {
            while (ptr <= r && (long long)nums[i] > 2 * (long long)nums[ptr]) {
                ++ptr;
            }
            cur_cnt += ptr - mid - 1;
        }
        vector<int> sorted;
        int lptr = l, rptr = mid + 1;
        while (lptr <= mid && rptr <= r) {
            if (nums[lptr] <= nums[rptr]) {
                sorted.push_back(nums[lptr++]);
            } else {
                sorted.push_back(nums[rptr++]);
            }
        }
        while (lptr <= mid) sorted.push_back(nums[lptr++]);
        while (rptr <= r) sorted.push_back(nums[rptr++]);
        for (int i = l; i <= r; ++i) {
            nums[i] = sorted[i - l];
        }
        return lcnt + rcnt + cur_cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, static_cast<int>(nums.size()) - 1);
    }
};
