class Solution {
private:
    bool checkPrefix(int num, int ones) {
        for (int i = 0; i < ones; ++i) {
            int t = num & (1 << (7 - i));
            if (0 == t) return false;
        }
        return (0 == (num & (1 << (7 - ones))));
    }
    bool checkByte(int num) {
        return (num & (1 << 7)) && !(num & (1 << 6));
    }
public:
    bool validUtf8(vector<int>& data) {
        int sz = data.size();
        int ptr = 0;
        while (ptr < sz) {
            int cnt = -1;
            if (!(data[ptr] & (1 << 7))) {
                ++ptr;
                continue;
            } else if (checkPrefix(data[ptr], 2)) {
                cnt = 2;
            } else if (checkPrefix(data[ptr], 3)) {
                cnt = 3;
            } else if (checkPrefix(data[ptr], 4)) {
                cnt = 4;
            }
            if (cnt <= 0 || ptr + cnt > sz) return false;
            else {
                ++ptr;
                for (int i = 0; i < cnt - 1; ++i) {
                    if (!checkByte(data[ptr])) return false;
                    ++ptr;
                }
            }
        }
        return true;
    }
};
