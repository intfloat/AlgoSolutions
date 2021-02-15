class Solution {
private:
    bool check(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] == s[end]) {
                ++start;
                --end;
            } else {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int start = 0, end = (int)s.size() - 1;
        while (start < end) {
            if (s[start] == s[end]) {
                ++start;
                --end;
            } else {
                return check(s, start + 1, end) || check(s, start, end - 1);
            }
        }
        return true;
    }
};
