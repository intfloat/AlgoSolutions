class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) return nums;
        int row = nums.size();
        int col = nums[0].size();
        if (row * col != r * c) return nums;
        vector<vector<int> > res(r, vector<int>(c));
        int pr = 0, pc = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res[pr][pc] = nums[i][j];
                ++pc;
                if (pc == c) {
                    ++pr;
                    pc = 0;
                }
            }
        }
        return res;
    }
};