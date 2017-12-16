class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> > res;
        for (int i = 3; i < (1 << nums.size()); ++i) {
            vector<int> cur;
            bool ok = true;
            for (int j = 0; j < nums.size(); ++j) {
                if (i & (1 << j)) {
                    if (cur.size() >= 1 && cur.back() > nums[j]) {
                        ok = false;
                        break;
                    }
                    cur.push_back(nums[j]);
                }
            }
            if (ok && cur.size() > 1) {
                res.push_back(cur);
            }
        }
        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());
        return res;
    }
};
