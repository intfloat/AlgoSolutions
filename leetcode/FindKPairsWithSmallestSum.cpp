typedef pair<int, int> pii;
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pii> res;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return res;
        }
        vector<int> pos(nums1.size(), 0);
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        for (int i = 0; i < min(k, (int)nums1.size()); ++i) {
            pq.push(make_pair(nums1[i] + nums2[0], i));
        }
        while ((int)res.size() < k && !pq.empty()) {
            pii tp = pq.top(); pq.pop();
            int ii = tp.second;
            res.push_back(make_pair(nums1[ii], nums2[pos[ii]]));
            ++pos[ii];
            if (pos[ii] < (int)nums2.size()) {
                pq.push(make_pair(nums1[ii] + nums2[pos[ii]], ii));
            }
        }
        return res;
    }
};
