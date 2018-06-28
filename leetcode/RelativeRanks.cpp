typedef pair<int, int> pii;
string int2str(int num) {
    if (num == 1) {
        return "Gold Medal";
    } else if (num == 2) {
        return "Silver Medal";
    } else if (num == 3) {
        return "Bronze Medal";
    } else {
        stringstream ss;
        ss << num;
        string ret;
        ss >> ret;
        return ret;
    }
}

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pii> ns;
        for (int i = 0; i < (int)nums.size(); ++i) {
            ns.push_back({nums[i], i});
        }
        sort(ns.begin(), ns.end(), greater<pii>());
        vector<string> res(nums.size());
        for (int i = 0; i < (int)ns.size(); ++i) {
            res[ns[i].second] = int2str(i + 1);
        }
        return res;
    }
};
