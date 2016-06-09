class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
        }
        priority_queue<pair<int, int> > pq;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            pq.push(make_pair(-it->second, it->first));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            pair<int, int> tp = pq.top();
            pq.pop();
            res.push_back(tp.second);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
