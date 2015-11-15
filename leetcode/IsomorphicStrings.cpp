class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        set<char> st;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = t[i];
                if (st.find(t[i]) != st.end()) return false;
                else st.insert(t[i]);
            }
            else if (m[s[i]] != t[i]) return false;
        }
        return true;
    }
};
