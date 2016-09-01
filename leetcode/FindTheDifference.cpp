class Solution {
public:
    char findTheDifference(string s, string t) {
        int sz = s.size();
        vector<int> cnt(26, 0);
        for (int i = 0; i < sz; ++i) {
            ++cnt[s[i] - 'a'];
        }
        for (int i = 0; i < t.size(); ++i) {
            --cnt[t[i] - 'a'];
        }
        char res;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] < 0) {
                res = (char)('a' + i);
                break;
            }
        }
        return res;
    }
};
