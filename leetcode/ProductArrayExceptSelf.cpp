class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz, 1);
        int prod = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res[i] *= prod;
            prod *= nums[i];
        }
        prod = 1;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            res[i] *= prod;
            prod *= nums[i];
        }
        return res;
    }
};
