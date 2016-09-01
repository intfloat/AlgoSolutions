class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> cnt;
        for (int i = 0; i < magazine.size(); ++i) {
            ++cnt[magazine[i]];
        }
        for (int i = 0; i < ransomNote.size(); ++i) {
            if (cnt[ransomNote[i]] <= 0) {
                return false;
            } else {
                --cnt[ransomNote[i]];
            }
        }
        return true;
    }
};
