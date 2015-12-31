class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> t = nums;
        sort(t.begin(), t.end());
        nums.clear();
        int dis = (t.size() + 1) / 2;
        for (int i = 0; i < dis; ++i) {
            nums.push_back(t[i]);
            if (i + dis < (int)t.size()) {
                nums.push_back(t[i + dis]);
            }
        }
        return;
    }
};
