class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> row;
        for (int i = 1; i < (1 << 9); ++i) {
            if (__builtin_popcount(i) != k) continue;
            int sm = 0;
            for (int j = 0; j < 9; ++j) {
                if (i & (1 << j)) sm += j + 1;
            }
            if (sm == n) {
                row.clear();
                for (int j = 0; j < 9; ++j) {
                    if (i & (1 << j)) row.push_back(j + 1);
                }
                res.push_back(row);
            }
        }
        return res;
    }
};
