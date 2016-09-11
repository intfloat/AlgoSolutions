class Solution {
private:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
public:
    string decodeString(string s) {
        int sz = s.size();
        int ptr = 0;
        string res;
        while (ptr < sz) {
            if (isDigit(s[ptr])) {
                int cnt = 0;
                while (isDigit(s[ptr])) {
                    cnt = cnt * 10 + (s[ptr++] - '0');
                }
                assert(s[ptr] == '[');
                ++ptr;
                int l = ptr, balance = 1;
                while (balance != 0) {
                    if (s[ptr] == '[') ++balance;
                    else if (s[ptr] == ']') --balance;
                    ++ptr;
                }
                string sub = decodeString(s.substr(l, ptr - l - 1));
                for (int i = 0; i < cnt; ++i) {
                    res += sub;
                }
            } else {
                string val;
                while (ptr < sz && !isDigit(s[ptr])) {
                    val.push_back(s[ptr++]);
                }
                res += val;
            }
        }
        return res;
    }
};
