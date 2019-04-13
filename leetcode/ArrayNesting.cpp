class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int sz = nums.size();
        int mx = 0;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] >= 0) {
                int idx = i;
                int len = 1;
                while (true) {
                    int n_idx = nums[idx];
                    nums[idx] = -1;
                    if (n_idx == i) {
                        mx = max(mx, len);
                        break;
                    }
                    idx = n_idx;
                    ++len;
                }
            }
        }
        return mx;
    }
};