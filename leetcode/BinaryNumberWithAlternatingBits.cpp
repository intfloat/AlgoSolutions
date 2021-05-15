class Solution {
public:
    bool hasAlternatingBits(int n) {
        int end = 0;
        int nn = n;
        while (nn > 0) {
            nn -= nn & (1 << end);
            ++end;
        }

        for (int i = end - 1; i >= 1; --i) {
            bool high_bit = (n & (1 << i)) > 0;
            bool low_bit = (n & (1 << (i - 1))) > 0;
            if (high_bit == low_bit) {
                return false;
            }
        }
        return true;
    }
};
