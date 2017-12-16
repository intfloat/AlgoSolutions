class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < findNums.size(); ++i) {
            int idx = find(nums.begin(), nums.end(), findNums[i]) - nums.begin();
            for (int j = idx + 1; j < nums.size(); ++j) {
                if (nums[j] > findNums[i]) {
                    res.push_back(nums[j]);
                    break;
                }
            }
            if (i + 1 > res.size()) {
                res.push_back(-1);
            }
        }
        return res;
    }
};
