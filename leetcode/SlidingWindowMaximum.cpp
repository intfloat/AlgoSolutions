class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return vector<int>();
        }
        int sz = nums.size();
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < sz; ++i) {
            while (!q.empty() && q.front() + k <= i) {
                q.pop_front();
            }
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};
