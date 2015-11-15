class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss;
        ss << str;
        string cur;
        map<char, string> mp;
        set<string> st;
        vector<string> arr;
        while (ss >> cur) {
            arr.push_back(cur);
        }
        if (arr.size() != pattern.size()) {
            return false;
        }
        for (int i = 0; i < (int)arr.size(); ++i) {
            if (mp.find(pattern[i]) == mp.end()) {
                if (st.find(arr[i]) != st.end()) {
                    return false;
                }
                mp[pattern[i]] = arr[i];
            }
            else if (mp[pattern[i]] != arr[i]) {
                return false;
            }
            st.insert(arr[i]);
        }
        return true;
    }
};
