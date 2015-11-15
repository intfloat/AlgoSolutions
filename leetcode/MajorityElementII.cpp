class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand[2], cnt[2];
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            bool update = false;
            for (int j = 0; j < 2; ++j) {
                if (nums[i] == cand[j] && cnt[j]) {
                    ++cnt[j];
                    update = true;
                    break;
                }
            }
            if (!update) {
                for (int j = 0; j < 2; ++j) {
                    if (!cnt[j]) {
                        cnt[j] = 1;
                        cand[j] = nums[i];
                        update = true;
                        break;
                    }
                }
            }
            if (!update) {
                cnt[0] = max(0, cnt[0] - 1);
                cnt[1] = max(0, cnt[1] - 1);
            }
        }
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt[0] += (nums[i] == cand[0]);
            cnt[1] += (nums[i] == cand[1]);
        }
        vector<int> res;
        if (cnt[0] * 3 > nums.size()) res.push_back(cand[0]);
        if (cand[1] != cand[0] && cnt[1] * 3 > nums.size()) res.push_back(cand[1]);
        return res;
    }
};
