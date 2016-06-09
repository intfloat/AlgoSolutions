bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) {
        return p1.first < p2.first;
    }
    else {
        return p1.second > p2.second;
    }
}
class Solution {
private:
    int lis(vector<int>& num) {
        set<int> st;
        for (int i = 0; i < num.size(); ++i) {
            auto it = st.lower_bound(num[i]);
            if (it != st.end()) {
                st.erase(it);
            }
            st.insert(num[i]);
        }
        return st.size();
    }

public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int sz = envelopes.size();
        if (sz == 0) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> num;
        for (int i = 0; i < sz; ++i) {
            num.push_back(envelopes[i].second);
        }
        return lis(num);
    }
};
