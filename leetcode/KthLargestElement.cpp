class Solution {
public:
    int kth(vector<int>& nums, int left, int right, int k) {
        if (left == right) {            
            return nums[left];
        }
        int pivot = nums[right];
        int lp = left, rp = right;
        while (lp < rp) {
            while (lp < rp && nums[lp] <= pivot) ++lp;
            if (lp == rp) break;
            nums[rp] = nums[lp];
            while (lp < rp && nums[rp] > pivot) --rp;
            if (lp == rp) break;
            nums[lp] = nums[rp];
        }
        nums[lp] = pivot;
        if (k == lp - left + 1) return pivot;
        else if (k < lp - left + 1) return kth(nums, left, lp - 1, k);
        else return kth(nums, lp + 1, right, k - (lp - left + 1));
    }
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        k = len - k + 1;
        return kth(nums, 0, len - 1, k);
    }
};
