class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> num_to_start, num_to_end, cnt;
        int max_freq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
            num_to_end[nums[i]] = i;
            if (num_to_start.find(nums[i]) == num_to_start.end()) {
                num_to_start[nums[i]] = i;
            }
            max_freq = max(max_freq, cnt[nums[i]]);
        }

        int res = nums.size();
        for (auto& it : cnt) {
            if (it.second < max_freq) {
                continue;
            }
            int num = it.first;
            res = min(res, num_to_end[num] - num_to_start[num] + 1);
        }

        return res;
    }
};
