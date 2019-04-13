class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            ++cnt[s1[i] - 'a'];
        }
        int diff = s1.size();
        for (int i = 0; i < s2.size(); ++i) {
            if (cnt[s2[i] - 'a'] > 0) {
                --diff;
            } else {
                ++diff;
            }
            --cnt[s2[i] - 'a'];
            int idx = i - s1.size();
            if (idx >= 0) {
                if (cnt[s2[idx] - 'a'] >= 0) {
                    ++diff;
                } else {
                    --diff;
                }
                ++cnt[s2[idx] - 'a'];
            }
            if (diff == 0) return true;
        }
        return false;
    }
};