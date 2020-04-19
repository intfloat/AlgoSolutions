class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int mx_sm = accumulate(nums.begin(), nums.begin() + k, 0);
        int sm = mx_sm;
        for (int i = k; i < nums.size(); ++i) {
            sm += nums[i];
            sm -= nums[i - k];
            mx_sm = max(mx_sm, sm);
        }
        return 1.0 * mx_sm / k;
    }
};
