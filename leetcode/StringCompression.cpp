class Solution {
private:
    vector<char> i2c(int i) {
        vector<char> ret;
        while (i > 0) {
            ret.push_back((char)('0' + i % 10));
            i /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) {
            return 1;
        }
        int cnt = 1, ptr = 0;
        char c = chars[0];
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == c) {
                ++cnt;
            }
            char bk = chars[i];
            if (chars[i] != c || i + 1 == chars.size()) {
                if (cnt == 1) {
                    chars[ptr] = c;
                    ++ptr;
                } else {
                    chars[ptr] = c;
                    ++ptr;
                    vector<char> r = i2c(cnt);
                    for (int j = 0; j < r.size(); ++j) {
                        chars[j + ptr] = r[j];
                    }
                    ptr += r.size();
                }
                if (i + 1 == chars.size() && bk != c) {
                    chars[ptr] = bk;
                    ++ptr;
                }
                cnt = 1;
                c = bk;
            }
        }
        chars.resize(ptr);
        return ptr;
    }
};
