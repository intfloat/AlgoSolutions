class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr = 0, pt = 0;
        while (ptr < s.size() && pt < t.size()) {
            if (s[ptr] == t[pt]) {
                ++ptr;
            }
            ++pt;
        }
        return (ptr >= s.size());
    }
};
