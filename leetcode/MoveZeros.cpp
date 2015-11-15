class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0, sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            cnt += (nums[i] == 0);
        }
        int ptr = 0;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] != 0) {
                nums[ptr++] = nums[i];
            }
        }
        for (int i = sz - cnt; i < sz; ++i) {
            nums[i] = 0;
        }
    }
};
