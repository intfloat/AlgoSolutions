class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> name2idx;
        for (int i = 0; i < list1.size(); ++i) {
            name2idx[list1[i]] = i;
        }
        int mn = list1.size() + list2.size();
        vector<string> res;
        for (int i = 0; i < list2.size(); ++i) {
            if (name2idx.find(list2[i]) != name2idx.end()) {
                int sm = i + name2idx[list2[i]];
                if (sm < mn) {
                    res.clear();
                    res.push_back(list2[i]);
                    mn = sm;
                } else if (sm == mn) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};
