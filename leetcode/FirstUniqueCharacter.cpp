class Solution {
public:
    int firstUniqChar(string s) {
        int sz = s.size();
        vector<int> cnt(26, 0);
        for (int i = 0; i < sz; ++i) {
            ++cnt[s[i] - 'a'];
        }
        for (int i = 0; i < sz; ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
