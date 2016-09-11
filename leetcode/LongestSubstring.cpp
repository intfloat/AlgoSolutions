class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k > (int)s.size()) {
            return 0;
        }
        vector<int> cnt(26, 0);
        for (int i = 0; i < (int)s.size(); ++i) ++cnt[s[i] - 'a'];

        int mn = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) mn = min(cnt[i], mn);
        }
        if (mn >= k) return s.size();

        int pv = 0;
        int res = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (cnt[s[i] - 'a'] < k) {
                res = max(res, longestSubstring(s.substr(pv, i - pv), k));
                pv = i + 1;
            }
        }
        res = max(res, longestSubstring(s.substr(pv, s.size() - pv), k));
        return res;
    }
};
