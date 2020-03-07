class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int> > dp_mx(sz, vector<int>(3));
        vector<vector<int> > dp_mn(sz, vector<int>(3));
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                dp_mx[i][0] = dp_mn[i][0] = nums[i];
            } else {
                dp_mx[i][0] = max(nums[i], dp_mx[i-1][0]);
                dp_mn[i][0] = min(nums[i], dp_mn[i-1][0]);
            }
            if (i == 1) {
                dp_mx[i][1] = dp_mn[i][1] = nums[i]*nums[i-1];
            } else if (i > 1) {
                dp_mx[i][1] = max(dp_mx[i-1][1], max(dp_mx[i-1][0]*nums[i], dp_mn[i-1][0]*nums[i]));
                dp_mn[i][1] = min(dp_mn[i-1][1], min(dp_mx[i-1][0]*nums[i], dp_mn[i-1][0]*nums[i]));
            }
            if (i == 2) {
                dp_mx[i][2] = dp_mn[i][2] = nums[i]*nums[i-1]*nums[i-2];
            } else if (i > 2) {
                dp_mx[i][2] = max(dp_mx[i-1][2], max(dp_mx[i-1][1]*nums[i], dp_mn[i-1][1]*nums[i]));
                dp_mn[i][2] = min(dp_mn[i-1][2], min(dp_mx[i-1][1]*nums[i], dp_mn[i-1][1]*nums[i]));
            }
        }
        return dp_mx[sz-1][2];
    }
};
