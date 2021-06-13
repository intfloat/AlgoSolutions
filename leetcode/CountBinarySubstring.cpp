class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> cnt;
        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || s[i] == s[i - 1]) {
                ++cur;
            } else {
                cnt.push_back(cur);
                cur = 1;
            }
        }
        cnt.push_back(cur);

        int res = 0;
        for (int i = 1; i < cnt.size(); ++i) {
            res += min(cnt[i - 1], cnt[i]);
        }
        return res;
    }
};
