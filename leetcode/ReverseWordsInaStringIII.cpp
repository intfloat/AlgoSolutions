class Solution {
public:
    string reverseWords(string s) {
        int sz = s.size();
        int ptr = 0;
        while (ptr < sz) {
            int i = ptr;
            while (i < sz && s[i] != ' ') ++i;
            reverse(s.begin() + ptr, s.begin() + i);
            ptr = i + 1;
        }
        return s;
    }
};