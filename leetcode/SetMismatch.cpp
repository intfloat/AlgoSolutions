class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> exist(n + 1, false);
        vector<int> res(2);
        for (auto& i : nums) {
            if (exist[i]) {
                res[0] = i;
            } else {
                exist[i] = true;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!exist[i]) {
                res[1] = i;
                break;
            }
        }
        return res;
    }
};
